# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import torch
from torchvision import transforms
from torch import nn
import torch.optim as optim

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from sensor_msgs.msg import Image
from data_interface.msg import Data
from geometry_msgs.msg import Vector3
from cv_bridge import CvBridge
import cv2
from PIL import Image as pil_img
import numpy as np
import time
from torch.utils.data import DataLoader, random_split

from .auto import NeuralNetwork
from . import auto
from . import dataset
import utm
import math


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.mat = None

        self.get_logger().set_level(10)

        self.publisher_ = self.create_publisher(Data, 'data_topic', 10)
        timer_period = 0.05  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

        

        # Create subscription to the "/odu/fix" topic fo GPS
        self.subscription_gps = self.create_subscription(
            Vector3,
            '/odu/fix',
            self.gps_callback,
            1
        )
        self.gps_data = False
        self.prev_gps_data = False
        self.utm_coords = [0, 0, 0, 0]
        self.waypoints = [[318129.25506070675, 4726349.1617945405], 
                          [318129.2455176051, 4726344.271294684], 
                          [318131.3939482387, 4726327.665212304]]
        
        # Create a subscription to the "usb_cam_0/image_raw" topic
        self.subscription_cam0 = self.create_subscription(
            Image,
            'usb_cam_0/image_raw',
            self.camera0_callback,
            1
        )
        self.cam0_data = False

        # Create a subscription to the "usb_cam_1/image_raw" topic
        self.subscription_cam1 = self.create_subscription(
            Image,
            'usb_cam_1/image_raw',
            self.camera1_callback,
            1
        )
        self.cam1_data = False

        # Create a subscription to the "usb_cam_1/image_raw" topic
        self.subscription_joy = self.create_subscription(
            Joy,
            'joy',
            self.joy_callback,
            1
        )
        self.joy_data = False
        self.dataActive = False
        self.autoActive = False
        self.waypointActive = False
        self.prevData = 0
        self.currData = 0
        self.prevAuto = 0
        self.currAuto = 0
        self.prevWaypoint = 0
        self.currWaypoint = 0
        self.heading = None


        weightsPath = f"/home/{os.getlogin()}/IGVCDev/src/data_collection_ws/model/best.pt"

        self.model = NeuralNetwork()
        self.model.load_state_dict(torch.load(weightsPath, map_location=torch.device('cpu')))
        self.model.eval()

        self.get_logger().info("Model is ready for evaluation")

        self.transform = transforms.Compose([
            # Add any necessary transformations (e.g., resizing, normalization) here
            self.normalize
        ])
        self.bridge = CvBridge()
        print("Ready!")



    def normalize(self, image):
        # Convert the image to a tensor
        tensor_image = transforms.ToTensor()(image)

        # Flatten the tensor and collect pixel values
        pixel_values = tensor_image.view(-1).numpy()

        # Calculate mean and standard deviation
        mean = np.mean(pixel_values)
        std_dev = np.std(pixel_values)

        # Define Normalize transform
        normalize_transform = transforms.Normalize(mean=[mean], std=[std_dev])

        # Apply normalization transform
        normalized_image = normalize_transform(tensor_image)

        return normalized_image
    
    def write(self, msg, index):
        sz = (msg.height, msg.width)
        if msg.step * msg.height != len(msg.data):
            print('bad step/height/data size')
            return

        if msg.encoding == 'rgb8':
            dirty = (self.mat is None or msg.width != self.mat.shape[1] or
                     msg.height != self.mat.shape[0] or len(self.mat.shape) < 2 or
                     self.mat.shape[2] != 3)
            if dirty:
                self.mat = np.zeros([msg.height, msg.width, 3], dtype=np.uint8)
            self.mat[:, :, 2] = np.array(msg.data[0::3]).reshape(sz)
            self.mat[:, :, 1] = np.array(msg.data[1::3]).reshape(sz)
            self.mat[:, :, 0] = np.array(msg.data[2::3]).reshape(sz)
        elif msg.encoding == 'mono8':
            self.mat = np.array(msg.data).reshape(sz)
        else:
            print('unsupported encoding {}'.format(msg.encoding))
            return
        if self.mat is not None:
            start = time.time()
            filename = f"cam{index}.jpg" 
            cv2.imwrite(filename, self.mat)
            end = time.time()
            # print(f"Time to save: {end - start}")
    
    def camera0_callback(self, msg):
        self.cam0_data = msg
        self.get_logger().debug(f"Cam0 image timestamp: {msg.header}")
        # start = time.time()
        if self.autoActive:
            self.write(msg, 0)
        # end = time.time()
        # self.get_logger().debug(f"Time to save camera0 data as jpg: {end - start} seconds")
        # pass



    def camera1_callback(self, msg):
        self.cam1_data = msg
        self.get_logger().debug(f"Cam1 image timestamp: {msg.header}")
        # start = time.time()
        if self.autoActive:
            self.write(msg, 1)
        # end = time.time()
        # self.get_logger().debug(f"Time to save camera1 data as jpg: {end - start} seconds")

    
    def joy_callback(self, msg):
        self.joy_data = msg

        self.currData = msg.buttons[7]
        if self.currData > self.prevData:
            self.dataActive = not self.dataActive
        self.prevData = self.currData

        self.currAuto = msg.buttons[0]
        if self.currAuto > self.prevAuto:
            self.autoActive = not self.autoActive
        self.prevAuto = self.currAuto

        self.currWaypoint = msg.buttons[3]
        if self.currWaypoint > self.prevWaypoint:
            self.get_logger().debug(f"Waypoint Flag: {self.waypointActive}")
            self.waypointActive = not self.waypointActive
        self.prevWaypoint = self.currWaypoint
    
    def gps_callback(self, msg):
        self.gps_data = msg
        self.lat = msg.x
        self.long = msg.y
        self.prev_utm_coords = self.utm_coords
        self.utm_coords = utm.from_latlon(self.lat, self.long)
        self.heading = self.getHeading()
        self.get_logger().info(f"lat: {self.lat} | long: {self.long}")
        self.get_logger().debug(f"Heading: {self.heading}")
        

    def dir(self, x, y):
        if x:
            return (math.degrees((math.atan2(x, y))))
        if y > 0:
            return 0
        else:
            return 180
    
    def getVectorAngle(self, currPositionX, waypointX, currPositionY, waypointY):
        if self.prev_gps_data == self.gps_data:
            return -1
        if self.prev_gps_data:
            
            x2 = waypointX
            x1 = currPositionX
            y2 = waypointY
            y1 = currPositionY
            y = x2 - x1
            x = y2 - y1
            self.get_logger().info(f"Meters East: {x} | Meters North: {y}")
            heading = self.dir(x, y)
            return heading
        return 0
    
    def getHeading(self):
        if self.prev_gps_data == self.gps_data:
            return -1
        if self.prev_gps_data:
            x2 = self.utm_coords[0]
            x1 = self.prev_utm_coords[0]
            y2 = self.utm_coords[1]
            y1 = self.prev_utm_coords[1]
            x = x2 - x1
            y= y2 - y1
            heading = self.dir(x, y)
            return heading
        
        self.prev_gps_data = self.gps_data
        return 0
    
    # Calculate the steering angle while under waypoint mode
    def waypointSteering(self, vector_angle, heading):
        gain = 0.002

        # Determine the difference between the vector and heading
        angle = (vector_angle - heading)
        self.get_logger().debug(f"Angle before logic: {angle}")
        if angle > 180:
            angle = angle - 360
        if angle < -180:
            angle = angle + 360
        self.get_logger().debug(f"Angle after logic: {angle}")
        # Apply to the steering function
        steering = -math.tanh(gain*angle)
        # Return the result
        return steering
        
    
    def timer_callback(self):
        msg = Data()

        # Determine the predicted values
        if self.autoActive:
            start_inference = time.time()
            
            self.get_logger().debug("----------Inference Breakdown----------")
            
            start = time.time()
            cam0 = pil_img.open(f'cam0.jpg').convert('L')
            cam1 = pil_img.open(f'cam1.jpg').convert('L')
            end = time.time()
            self.get_logger().debug(f"Time to open cam images: {end - start} seconds")

            start = time.time()
            cam0 = self.crop(cam0)
            cam1 = self.crop(cam1)
            end = time.time()
            self.get_logger().debug(f"Time to crop images: {end - start} seconds")

            start = time.time()
            cam0 = self.transform(cam0)
            cam1 = self.transform(cam1)
            end = time.time()
            self.get_logger().debug(f"Time to convert to tensor: {end - start} seconds")
            
            start = time.time()
            data = torch.cat((cam0, cam1), dim=0)
            data = torch.unsqueeze(data, 0)
            end = time.time()
            self.get_logger().debug(f"Time to cat and unsqueeze: {end - start} seconds")

            start = time.time()
            with torch.no_grad():
                result = self.model(data)
            end = time.time()
            self.get_logger().debug(f"Time to inference: {end - start} seconds")
            
            msg.steering = result[0][0].item()
            msg.throttle = result[0][1].item()
            self.get_logger().debug(f"Steering value: {msg.steering}")
            self.get_logger().debug(f"Throttle value: {msg.throttle}")
            
            
            end = time.time()
            self.get_logger().debug(f"Time to execute AI inference: {end - start_inference} seconds")


        if self.waypointActive:
            self.get_logger().info("Waypoint mode is active")
            currNorthing = self.utm_coords[1]
            currEasting = self.utm_coords[0]
            # self.prevNorthing = self.currNorthing
            # self.prevEasting = self.currEasting
            waypointNorthing = 4726344.71
            waypointEasting = 318202.83
            vector_angle = self.getVectorAngle(currNorthing, waypointNorthing, currEasting, waypointEasting)
            self.heading = self.getHeading()
            self.get_logger().debug(f"Current Northing: {currNorthing} | CurrentEasting: {currEasting}")
            self.get_logger().debug(f"Vector Angle: {vector_angle} | Heading: {self.heading}")
            msg.steering = self.waypointSteering(vector_angle, self.heading)
            msg.throttle = 0.08
            self.get_logger().debug(f"steering: {msg.steering}")
        else:
            self.get_logger().info("Waypoint mode is not active")
        

        # Populate the gamepad data
        if self.joy_data:
            # Use the received gamepad data
            msg.gamepad = self.joy_data
            msg.data_active = self.dataActive
            msg.auto_active = self.autoActive
            msg.waypoint_active = self.waypointActive

        # Populate the camera 0 data
        if self.cam0_data:
            # Use the received camera data
            msg.cam0 = self.cam0_data

        # Populate the camera 1 data
        if self.cam1_data:
            # Use the received camera data
            msg.cam1 = self.cam1_data

        # Populate the gps data
        if self.gps_data:
            self.get_logger().info("GPS data has been received")
            msg.latitude = self.lat
            msg.longitude = self.long

        if self.joy_data and self.cam0_data and self.cam1_data:
        # if self.joy_data and self.cam0_data and self.cam1_data and self.gps_data:
            self.get_logger().info("Publishing data")
            self.get_logger().debug(f"Steering: {msg.steering} | Throttle: {msg.throttle}")
            
            self.publisher_.publish(msg)
            self.joy_data = False
            self.cam0_data = False
            self.cam1_data = False
            self.gps_data = False
            self.i += 1
        else:
            self.get_logger().debug("Data not publishing")
            if not self.joy_data:
                self.get_logger().info("Waiting for joy_data")
            if not self.cam0_data:
                self.get_logger().info("Waiting for cam0_data")
            if not self.cam1_data:
                self.get_logger().info("Waiting for cam1_data")
            if not self.gps_data:
                self.get_logger().info("Waiting for GPS data")

    def crop(self, image):
        # Define bounding box based on percentages (left_percentage, top_percentage, right_percentage, bottom_percentage)
        left_percentage = 0
        top_percentage = 0.6
        right_percentage = 1
        bottom_percentage = 0.8

        # Calculate pixel coordinates based on percentages
        image_width, image_height = image.size
        left = int(left_percentage * image_width)
        top = int(top_percentage * image_height)
        right = int(right_percentage * image_width)
        bottom = int(bottom_percentage * image_height)

        # Crop the image
        return image.crop((left, top, right, bottom))


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

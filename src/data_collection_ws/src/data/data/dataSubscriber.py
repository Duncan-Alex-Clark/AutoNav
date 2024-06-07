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
import time
from datetime import datetime
import numpy as np
import cv2
from queue import Queue

import rclpy
from rclpy.node import Node
from data_interface.msg import Data
from PIL import Image
import math

class MinimalSubscriber(Node):

    def __init__(self):
        start = time.time()
        super().__init__('minimal_subscriber')

        self.get_logger().set_level(10)
        

        self.mat = None
        self.subscription = self.create_subscription(
            Data,
            'data_topic',
            self.listener_callback,
            5)
        self.subscription  # prevent unused variable warning


        self.frameCount = 0
        self.counter = 0
        self.user = os.getlogin()
        self.data_dir = f"/home/{self.user}/IGVCDev/src/data_collection_ws/data"
        self.makeDirectories(self.data_dir)

        MAXSIZE = 100
        self.cam0_queue = Queue(maxsize=MAXSIZE)
        self.cam1_queue = Queue(maxsize=MAXSIZE)
        self.steering_queue = Queue(maxsize=MAXSIZE)
        self.throttle_queue = Queue(maxsize=MAXSIZE)
        self.lat_queue = Queue(maxsize=MAXSIZE)
        self.long_queue = Queue(maxsize=MAXSIZE)

        
        

        end = time.time()
        self.get_logger().debug(f"Listener object has been instantiated after {end - start} seconds")
        

    def listener_callback(self, msg):
        self.counter += 1
        self.get_logger().info("listener_callback() executing")
        self.get_logger().info(f"Auto status: {msg.auto_active}")
        if self.steering_queue.full():
            self.get_logger().info("Saving data to disk storage")
            start_loop = time.time()
            while not self.steering_queue.empty():
                start = time.time()
                msg.gamepad.axes[0] = self.steering_queue.get()
                msg.gamepad.axes[5] = self.throttle_queue.get()
                msg.cam0 = self.cam0_queue.get()
                msg.cam1 = self.cam1_queue.get()
                self.logGamepad(msg.gamepad)
                self.logCam0(msg.cam0)
                self.logCam1(msg.cam1)
                self.logLat(msg.latitude)
                self.logLong(msg.longitude)
                end = time.time()
                self.get_logger().debug(f"Time to store one index of data: {end - start} seconds")
                self.frameCount += 1
            end_loop = time.time()
            self.get_logger().debug(f"Time to store all data: {end_loop - start_loop} seconds")

        # if not msg.data_active:
        if msg.data_active:
            self.get_logger().info("Data capture is active")
            self.get_logger().info(f"Number of datapoints collected: {self.frameCount}")
            if msg.gamepad.axes[0]:
                self.get_logger().info("Vehicle is turning")
                self.get_logger().info("-----Data recording-----")
                self.get_logger().debug(f"Steering value: {msg.gamepad.axes[0]}")
                self.get_logger().debug(f"Throttle value: {msg.gamepad.axes[5]}")
                
                start = time.time()
                self.steering_queue.put(msg.gamepad.axes[0])
                self.throttle_queue.put(msg.gamepad.axes[5])
                end = time.time()
                self.get_logger().debug(f"Time to save gamepad data: {end - start} seconds")

                start = time.time()
                self.cam0_queue.put(msg.cam0)
                end = time.time()
                self.get_logger().debug(f"Time to save cam0 data: {end - start} seconds")

                start = time.time()
                self.cam1_queue.put(msg.cam1)
                end = time.time()
                self.get_logger().debug(f"Time to save cam1 data: {end - start} seconds")

                start = time.time()
                self.lat_queue.put(msg.latitude)
                self.long_queue.put(msg.longitude)
                end = time.time()
                self.get_logger().debug(f"Time to save gps data: {end - start} seconds")


            else:
                if not self.counter % 5: # Save non-steering data 1/10th the frequency as steering data
                    self.get_logger().info("-----Data recording-----")
                    self.steering_queue.put(msg.gamepad.axes[0])
                    self.throttle_queue.put(msg.gamepad.axes[5])
                    self.get_logger().debug(f"Steering value: {msg.gamepad.axes[0]}")
                    self.get_logger().debug(f"Throttle value: {msg.gamepad.axes[5]}")
                    self.cam0_queue.put(msg.cam0)
                    self.cam1_queue.put(msg.cam1)
                    # self.get_logger().debug(f"Cam0 Data: {msg.cam0}")
                    # self.get_logger().debug(f"Cam1 Data: {msg.cam1}")
                    pass
                self.get_logger().info("-----Data not recording-----")
                self.get_logger().debug(f"Steering value: {msg.gamepad.axes[0]}")
                self.get_logger().debug(f"Throttle value: {msg.gamepad.axes[5]}")

                

    def logLat(self, lat):
        self.get_logger().debug(f"Lat: {lat}")
        file = open(self.latFile, "a")
        file.write(f"{lat}\n")
        file.close()

    def logLong(self, long):
        file = open(self.longFile, "a")
        file.write(f"{long}\n")
        file.close()
    
    def logGamepad(self, msg):
        # Get throttle and steering values
        throttle_index = 5
        steering_index = 0
        throttle = msg.axes[throttle_index]
        steering = msg.axes[steering_index]
        # Add throttle entry to the current txt file
        file = open(self.throttleFile, "a")
        file.write(f"{throttle}\n")
        file.close()
        # Add steering entry to the current txt file
        file = open(self.steeringFile, "a")
        file.write(f"{steering}\n")
        file.close()
        pass
    
    def logCam0(self, msg):
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
            filename = f"Camera_0_Frame_{self.frameCount}.jpg" 
            filename = os.path.join(self.camera0_dir,filename)
            cv2.imwrite(filename, self.mat)

    def logCam1(self, msg):
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
            filename = f"Camera_1_Frame_{self.frameCount}.jpg" 
            filename = os.path.join(self.camera1_dir,filename)
            cv2.imwrite(filename, self.mat)

    def makeDirectories(self, data_dir):
        timestamp = datetime.now().strftime("%y-%m-%d-%H_%M_%S")

        self.camera0_dir = f"{data_dir}/cam0/"
        self.camera1_dir = f"{data_dir}/cam1/"
        steeringPath = f"{data_dir}/steering"
        throttlePath = f"{data_dir}/throttle"
        latPath = f"{data_dir}/latitude"
        longPath = f"{data_dir}/longitude"

        if not os.path.exists(self.data_dir):
            os.mkdir(data_dir)
            os.mkdir(self.camera0_dir)
            os.mkdir(self.camera1_dir)
            os.mkdir(steeringPath)
            os.mkdir(throttlePath)
            os.mkdir(latPath)
            os.mkdir(longPath)

        if not os.path.exists(self.camera0_dir):
            os.mkdir(self.camera0_dir) 
        if not os.path.exists(self.camera1_dir):
            os.mkdir(self.camera1_dir)
        if not os.path.exists(steeringPath):
            os.mkdir(steeringPath) 
        if not os.path.exists(throttlePath):
            os.mkdir(throttlePath)
        if not os.path.exists(latPath):
            os.mkdir(latPath)
        if not os.path.exists(longPath):
            os.mkdir(longPath)
        
        # Make the camera sub directories
        self.camera0_dir = os.path.join(self.camera0_dir, timestamp)
        if not os.path.exists(self.camera0_dir):
            os.mkdir(self.camera0_dir)
        self.camera1_dir = os.path.join(self.camera1_dir, timestamp)
        if not os.path.exists(self.camera1_dir):
            os.mkdir(self.camera1_dir)

        # Make actuator directories
        self.steeringFile = f"{steeringPath}/{timestamp}_steering.txt"
        self.throttleFile = f"{throttlePath}/{timestamp}_throttle.txt" 
        file = open(self.steeringFile, "x")
        file.close()
        file = open(self.throttleFile, "x")
        file.close()

        # Make GPS directories
        self.latFile = f"{latPath}/{timestamp}_latitude.txt"
        self.longFile = f"{longPath}/{timestamp}_longitude.txt"
        file = open(self.latFile, "x")
        file.close()
        file = open(self.longFile, "x")
        file.close()

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


    def dir(self, x, y):
        if x:
            return (360 + math.degrees((math.atan2(x, y))))%360
        if y > 0:
            return 0
        else:
            return 180
    
    def getVector(self, position):
        nPosition = position[0]                     # Current northing position
        ePosition = position[1]                     # Current easting position
        nWaypoint = self.currWaypoint[0]            # Current waypoint northing position
        eWaypoint = self.currWaypoint[1]            # Current waypoint easting position

        a = nWaypoint - nPosition                   # Difference in northing position
        b = eWaypoint - ePosition                   # Difference in easting position

        distance = math.sqrt(a**2 + b**2)           # Distance from the waypoint in meters
        direction = self.dir(a, b)                  # Direction to the waypoint, 0=north : 90=east : 180=south : 270 : west
        return distance, direction                


def main(args=None):
    os.environ['ROS_LOG_DIR'] = f"/home/{os.getlogin()}/IGVCDev/src/data_collection_ws/log/listener_logs"

    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

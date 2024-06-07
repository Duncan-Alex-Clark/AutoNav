import numpy as np
import cv2


def find_available_cameras(max_tests=20):
    available_cameras = []
    for i in range(max_tests):
        cap = cv2.VideoCapture(i)
        if cap.isOpened():
            available_cameras.append(i)
            cap.release()
    return available_cameras

def main():
    cameras = 0
    while True:
        cameras = find_available_cameras() if not cameras else cameras # 'find_available_cameras()' should only run once
        if not cameras:
            print("No cameras available.")
            return -1
        print(f"Available camera indexes: {cameras}")

        index = input("Input the video index you would like to view: ")

        cap = cv2.VideoCapture(0)
        if not cap.isOpened():
            print("Cannot open camera")
            exit()
        while True:
            # Capture frame-by-frame
            ret, frame = cap.read()

            # if frame is read correctly ret is True
            if not ret:
                print("Can't receive frame (stream end?). Exiting ...")
                break
            # Our operations on the frame come here
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            
            print("Press 'q' to quit the video view")
            # Display the resulting frame
            cv2.imshow('frame', gray)
            if cv2.waitKey(1) == ord('q'):
                break
        result = input("Would you like to view another image (y/n): ")
        if result == 'n':
            break

    
    # When everything done, release the capture
    cap.release()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
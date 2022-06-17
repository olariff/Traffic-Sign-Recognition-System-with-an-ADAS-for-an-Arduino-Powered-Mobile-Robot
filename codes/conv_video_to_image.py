
import cv2
import os
import numpy as np


# save image in a folder in a particular path
image_path = "ImageTest"

# list the videos in the directory where the videos are stored
list_videos = os.listdir("Zoom")
print(list_videos)
count2 = 1

# loop through each video
for i in range(len(list_videos)):
    # path of each video
    video_path = "Zoom/" + list_videos[i]

    # make use of video capture function to read the video
    capture = cv2.VideoCapture(video_path)

    # loop through each frame of the video
    counter = 1
    while(capture.isOpened()):
        ret,frame = capture.read()

        # when frame is null, ret is false, otherwise ret is true
        counter = counter + 1
        if ret == True:
            # save the image shown after every 30 frames of the video
            if(counter%30 == 0):
                #another counter is used to save the image file as a different name and is increased after 30 frames of the video

                cv2.imwrite(image_path + "/" + str(count2) + ".jpg", frame)
                count2 = count2 + 1

        else:
            # stop capturing image from video process
            capture.release()

    
        


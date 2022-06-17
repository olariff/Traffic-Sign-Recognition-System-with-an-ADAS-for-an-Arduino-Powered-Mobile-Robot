# Traffic Sign Recognition System with an Advanced Driver Assistance System for an Arduino Powered Mobile Robot

This project involves the use of ultrasonic sensors and the Arduino Uno microcontroller to design a car that moves autonomously and avoids obstacles without any interference by the user. This project also aims to implement a mobile robot with object recognition functions (in particular traffic signs) using a convolutional neural network. The final product is a four-wheeled obstacle avoidance mobile robot, with traffic sign detection capabilities. Once a traffic sign is detected, the robot receives the information on that traffic sign and takes a particular action based on the sign detected. For example, if a stop sign is detected, the robot is to come to a halt. If no traffic sign is detected, the robot continues to roam about while avoiding obstacles in its way, until it detects a traffic sign. In simple terms, the product is a four-wheeled mobile robot with an ADAS system (traffic sign recognition) put in place. In addition, the camera used in the object detection is a mobile phone using a mobile app developed with android studio.

# Technical achievement

## Build the demo using Android Studio

*   Install
    **[Android Studio](https://developer.android.com/studio/index.html)**,
    following the instructions on the website. version 3.2 or later

*   You need an Android device and Android development environment with minimum
    API 21.

## Write the Convolutional Neural Network (CNN) for Object detection

The [CNN model](https://colab.research.google.com/drive/1zz32806ksvR5BfweIQRhq73ntVd1dWTn?usp=sharing) is written with multiple layers and tested out on google colab. The [dataset](https://cseegit.essex.ac.uk/ce301_21-22/CE301_oladunjoye_sheriff_o/-/blob/master/Dataset/signs.zip) for training and testing the model containing the traffic signs is added to the Jupyter Notebook project. It is obtained by recording videos of the object to be detected  and converting every 20 or 30 frames to images using a [python code](https://github.com/olariff/Traffic-Sign-Recognition-System-with-an-ADAS-for-an-Arduino-Powered-Mobile-Robot/blob/main/codes/conv_video_to_image.py). Once, the tests are successful, the CNN is exported as a [Tensorflow Lite model](https://github.com/olariff/Traffic-Sign-Recognition-System-with-an-ADAS-for-an-Arduino-Powered-Mobile-Robot/blob/main/model.tflite) to be used in the mobile app.

## Development of Android app

The project is added to Android studio and the [Tensorflow Lite model]([https://cseegit.essex.ac.uk/ce301_21-22/CE301_oladunjoye_sheriff_o/-/blob/master/Dataset/model.tflite](https://github.com/olariff/Traffic-Sign-Recognition-System-with-an-ADAS-for-an-Arduino-Powered-Mobile-Robot/blob/main/model.tflite)) is added to the project under the assets folder. This code can then be run on the emulator or even a physical android mobile phone.

## The Mobile Robot

The [simulated design](https://www.tinkercad.com/things/1qIcLglHojo-technical-achievement/editel) of the two-wheeled mobile robot is designed using the tinkerCAD online simulator before it is assembled physically. It is assembled using a 2 DC motors, ultrasonic sensor, jumper wires, breadboard, servo motor, Arduino Uno and a 12 volt power supply. Once assembled, the [code](https://cseegit.essex.ac.uk/ce301_21-22/CE301_oladunjoye_sheriff_o/-/blob/master/Codes/Autonomous_rover.ino) is written on the Arduino IDE and uploaded to the Arduino board using a USB 2.0 cable.

## Android app & Arduino communication

The [android app]([https://cseegit.essex.ac.uk/ce301_21-22/CE301_oladunjoye_sheriff_o/-/blob/master/Codes/app.zip](https://github.com/olariff/Traffic-Sign-Recognition-System-with-an-ADAS-for-an-Arduino-Powered-Mobile-Robot/tree/main/App%20code)) containing an [OpenCV library]([https://cseegit.essex.ac.uk/ce301_21-22/CE301_oladunjoye_sheriff_o/-/blob/master/Codes/openCVLibrary3413.zip](https://github.com/olariff/Traffic-Sign-Recognition-System-with-an-ADAS-for-an-Arduino-Powered-Mobile-Robot/blob/main/codes/openCVLibrary3413.zip)) communicates with the Arduino using a http get protocol via the ESP32 development board. A [code]([https://cseegit.essex.ac.uk/ce301_21-22/CE301_oladunjoye_sheriff_o/-/blob/master/Codes/ESP32_web_server.ino](https://github.com/olariff/Traffic-Sign-Recognition-System-with-an-ADAS-for-an-Arduino-Powered-Mobile-Robot/blob/main/codes/ESP32_web_server.ino) is written to create an ESP32 web server. Therefore, whenever an object is detected, the app sends a message to the arduino serial monitor and then the mobile robot takes a particular action beased on the object detected.

## Future project plans

*	Improving the autonomous nature of the self-driving mobile robot. This will involve training a deep learning model that enables the car to drive around a track, using regression to control the steering of the car and using a camera to obtain real time footage of the road.

*	Integrating odometry into the navigation and localisation of the robot. Odometry is a localisation technique that helps the robot know its position relative to its starting point. This will also improve the autonomous nature of the robot. 

*	Increasing the number of classes in the neural network and the dataset in each of these classes. This will increase the number of traffic signs/objects the CNN model is able to detect. Moreover, the increasing of the number of datasets helps to improve the accuracy of the CNN model. Another way to improve the accuracy is by adding more layers to the custom CNN model.

## References

[1](https://github.com/tensorflow/examples)

[2](https://github.com/tensorflow/examples)




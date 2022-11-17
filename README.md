# Gesture-Recognition-model-Flex-Punch-with-TensrflowLite-for-Embedded-Devices-Arduino-BLE-33-nano-
Arduino BLE 33 Nano is used to train a simple gesture recognition model (using accelerometer and gyroscopic data).  Once the model is created, it is ported to embed with the embedded device itself for real time predictions
Hardware 
-Arduino BLE 33 nano (Arduino TinyML Kit)

** Important to note the Arduino Nano BLE 33 need the following libaries installed
-LSM9DS1 IMU Library
-Harvard_TinyMLx Library

Steps

01) Use the DataCapture.ino file on arduino to capture the data (punch/flex)
02) Use Coolterm software to convert the serial data on COM port to convert to a CSV file.
03) User Filter.ipynb to convert the raw data to data frame which is to be used
04) Use Gesture_recognition.ipynb to develop model, train model, test model and convert the model to .h header file (containing Char array) which is used in embedded device
05) Use gesture-recognition.ino file to capture data and get the real time predictions



# AM_Vehicle
This repository contains source code for Both Arduino and NodeMCU micro controllers for communication
This also contains all the necessary circuit diagrams for connections of Arduino and NodeMCU along with motor drivers 

The Source code for the apk can be obtained by opening the app in Android Studio.

We are using the Software Serial class to make connections from NoddeMCU to Arduino.

We parse the data sent from the app by our NodeMCU and then send appropriate integer to our Arduino by the SoftwareSerial class.

The Arduino recieves the integer and a switch case determines the movement of the motors connected by the motordriver

/* ELEC 498/490 CODE TEMPLATE */
// ROS Code Draft









// ----------------------------------------------------------------------- //

// Arduino Test Code Servo's 

//Include libraries here
...

//Define servo motors and variables
#define servo1 0
...
int response_time = ?;
int sensor1_data = A1;
int sensor2_data = A2;
...



if (Serial.available() > 0) { 
    state = Serial.read(); // Reads the data from the serial port
    Serial.print(state); // Prints out the value sent
    //Motor functionality code block
}

delay (5);

//Below start functional code and smoothing motion
...

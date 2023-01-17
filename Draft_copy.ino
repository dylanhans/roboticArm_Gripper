/* ELEC 498/490 CODE TEMPLATE */
// ROS Code Draft

// Move position to end point
// Consists of file directory and file with simulated environment. 
// References joints included in movement with motion changes
rostopic pub /arm_controller/command trajectory_msgs/JointTrajectory 
'{joint_names: ["arm_base_joint","shoulder_joint", "bottom_wrist_joint", "elbow_joint","top_wrist_joint"], 
points: [{positions: [-0.1, 0.5, 0.02, 0, 0], time_from_start: [1,0]}]}' -1

// Insert above statement back to regular stable position
    
// Assign these to certain functions when pressed or initiated 
    // Ex. Grabbing, Reset, Large object, Normal, etc
    ...

// ----------------------------------------------------------------------- //

// Arduino Test Code Servo's 

//Include libraries here
#include <Servo.h>

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
    
// Finger Movement 1 - Vertical
    finger1.attach(servoPin1);
    finger1.write(pos1);
    
// Finger Movement 2 - Vertical
    finger2.attach(servoPin2);
    finger2.write(pos2);


// Finger Movement 3 - Horizontal
    finger3.attach(servoPin3);
    finger3.write(pos3);

void loop{
    //reads
    
    //set positions
    

}
   

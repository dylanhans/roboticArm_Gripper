// Arduino Test Code Servo's 

//Include libraries here
#include <Servo.h>

//Define servo motors and variables
#define servo1 0

Servo finger1;
Servo finger2;
Servo finger3;

int response_time = ?;
const int finger1_data = A1;
const int finger2_data = A2;
const int finger3_data = 10;
//Store servo position for default
int pos = 0;


//Below start functional code and smoothing motion
...
    
void Setup(){
finger1.attach(finger1_data);
finger2.attach(finger2_data);
finger3.attach(finger3_data);
    
if (Serial.available() > 0) { 
    state = Serial.read(); // Reads the data from the serial port
    Serial.print(state); // Prints out the value sent
    //Motor functionality code block
}
}


//Smooth motion code...

void smooth{}

//Make different positions to assign to fingers for seperate states.
//Figure out wire movement to assign servo motion
void loop{
    // Finger Movement 1 - Vertical
    // ex. 0 to 180
  for(pos = 0; pos <= 180; pos += 1){
    finger1.write(pos);
    delay(15);
  }
    // Finger Movement 2 - Vertical
  // ex. 180 degrees to 0 degrees
  for(pos = 180; pos>=0; pos-=1){
    finger2.write(pos);
    delay(15);
  }
    // Finger Movement 3 - Horizontal
   // ex. 60 degrees to 0 degrees
  for(pos = 60; pos>=0; pos-=1){
    finger3.write(pos);
    delay(15);
  }
}
    
//Introduce button functionality and classes corresponding to situations
   

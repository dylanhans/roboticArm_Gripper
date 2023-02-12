#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 60


uint8_t servonum = 0;
char menuInput;
char menu2Input;

void reset(){
  pwm.setPWM(0, 0, pulseWidth(0));
  pwm.setPWM(1, 0, pulseWidth(0));
  pwm.setPWM(2, 0, pulseWidth(0));
  
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  //Serial.println(analog_value);
  return analog_value;
}

void setup() 
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Panda Gripper Function:");
  Serial.println("(1) Grab | (2) HighFive | (3) First Finger | (4) Second Finger | (5) Third Finger | (6) Exit");
  pwm.begin();
  pwm.setPWMFreq(60);
  reset();
}

void loop() {

  while (Serial.available() == 0) {
  }

  menuInput = Serial.parseInt();
  switch(menuInput){
    case 1:
      Grab();
      afterAction();
    //break;
    
    case 2:
      HighFive();
      afterAction();
    //break;

    case 3:
      First();
      afterAction();
    //break;

    case 4:
      Second();
      afterAction();

    case 5:
      Third();
      afterAction();  
    //break;

    case 6:
      stop();
    break;
  }
}  

void stop(){
  exit(0);
}

void Grab(){
    pwm.setPWM(0, 0, pulseWidth(180));
    pwm.setPWM(1, 0, pulseWidth(180));
    pwm.setPWM(2, 0, pulseWidth(180));
}

void HighFive(){
    pwm.setPWM(0, 0, pulseWidth(-60));
    pwm.setPWM(1, 0, pulseWidth(-60));
    pwm.setPWM(2, 0, pulseWidth(-60));
}

void First(){
    pwm.setPWM(0, 0, pulseWidth(180));
}

void Second(){
    pwm.setPWM(1, 0, pulseWidth(180));
}

void Third(){
    pwm.setPWM(2, 0, pulseWidth(180));
}

void Reset(){
  pwm.setPWM(0, 0, pulseWidth(0));
  pwm.setPWM(1, 0, pulseWidth(0));
  pwm.setPWM(2, 0, pulseWidth(0));
}

void(* resetFunc) (void) = 0;

void afterAction() {
  Serial.println("\n");
  Serial.println("Release Gripper? Release (1) Exit (2)\n");
  while (Serial.available() == 0) {
  }

  menu2Input = Serial.parseInt();
  switch(menu2Input){
    case 1:
      resetFunc();
            
    case 2:
      stop();
    break;

  }
}

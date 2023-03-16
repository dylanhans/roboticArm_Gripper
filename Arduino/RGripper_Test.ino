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
float i;
float j;
float h;
int sensorValue1 = analogRead(A2);
int sensorValue2 = analogRead(A3);


void reset(){
  pwm.setPWM(0, 0, pulseWidth(30));
  pwm.setPWM(1, 0, pulseWidth(30));
  pwm.setPWM(2, 0, pulseWidth(30));
  
}

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void setup() 
{
  Serial.begin(9600);
  delay(2000);
  Serial.println("Panda Gripper Function:");
  Serial.println("(1) Grab | (2) High Five | (3) First Finger | (4) Second Finger | (5) Third Finger | (6) Exit");
  pwm.begin();
  pwm.setPWMFreq(60);
  reset();
  int sensorValue1 = analogRead(A2);
  sensorValue1 = (sensorValue1);
  Serial.println("Initial Pressure Value 1: ");
  Serial.println(sensorValue1);
  int sensorValue2 = analogRead(A3);
  sensorValue2 = (sensorValue2);
  Serial.println("Initial Pressure Value 2: ");
  Serial.println(sensorValue2);
}

void loop() {
  while (Serial.available() == 0) {}
  menuInput = Serial.parseInt();

    if (menuInput == 1){
      Grab();
      afterAction();
    //break;
    }
    if (menuInput == 2){
      HighFive();
      afterAction();
    //break;
    }
    else if (menuInput == 3){
      First();
      afterAction();
    //break;
    }
    else if (menuInput == 4){
      Second();
      afterAction();
    }
    else if (menuInput == 5){
      Third();
      afterAction();  
    //break;
    }
    else if (menuInput == 6){
      stop();
     //break;
  }

}



void stop(){
  exit(0);
}

void Grab(){ 
    for (float i=30;i<=90;i+=0.1)
      pwm.setPWM(0, 0, pulseWidth(i));
      delay(200);
      for (float i=90;i<=160;i+=0.05)
        pwm.setPWM(0, 0, pulseWidth(i));
        delay(200);
          
    for (float j=30;j<=90;j+=0.1)
      pwm.setPWM(1, 0, pulseWidth(j));
      delay(200);
      for (float j=90;j<=160;j+=0.05)
        pwm.setPWM(1, 0, pulseWidth(j));
        delay(200);
          
    for (float h=30;h<=90;h+=0.1)
      pwm.setPWM(2, 0, pulseWidth(h));      
      delay(200);
      for (float h=90;h<=160;h+=0.05)
        pwm.setPWM(2, 0, pulseWidth(h));        
        delay(200);
        
  delay(3000);
    while(Serial.available()==0)
  {
    int sensorValue1 = analogRead(A2);
    int sensorValue2 = analogRead(A3);
    if (sensorValue2>200 && sensorValue1>200){
      Sensor12Active();
    }
    else if (sensorValue1>200 && sensorValue2<150){
      Sensor1Active();
    }
    else if (sensorValue2>200 && sensorValue1<150){
      Sensor2Active();
    }
    else
      Serial.println("No pressure");
  }
}

void ReducePressure(){
    pwm.setPWM(0, 0, pulseWidth(120));
    pwm.setPWM(1, 0, pulseWidth(120));
    delay(200);
    int sensorValue1 = analogRead(A2);
    int sensorValue2 = analogRead(A3);
    // print out the value you read:
    sensorValue2 = (sensorValue2);
    sensorValue1 = (sensorValue1);
    Serial.println("Pressure Value 1: ");
    Serial.println(sensorValue1);
    Serial.println("Pressure Value 2: ");
    Serial.println(sensorValue2);
}

void Sensor1Active(){
    while(Serial.available()==0)
  {
    int sensorValue1 = analogRead(A2);
    sensorValue2 = (sensorValue1);
    sensorValue1 = (sensorValue1);
    Serial.println("Pressure Value 1: ");
    Serial.println(sensorValue1);
    Serial.println("Pressure Value 2: ");
    Serial.println(sensorValue2);
    if (sensorValue1>600 || sensorValue2>600){
     Serial.println("Pressure Exceeded, Reducing now.");
     ReducePressure();
  }
 }
}

void Sensor12Active(){
     while(Serial.available()==0)
  {
    int sensorValue1 = analogRead(A2);
    int sensorValue2 = analogRead(A3);
    sensorValue2 = (sensorValue2);
    sensorValue1 = (sensorValue1);
    Serial.println("Pressure Value 1: ");
    Serial.println(sensorValue1);
    Serial.println("Pressure Value 2: ");
    Serial.println(sensorValue2);
    if (sensorValue1>600 || sensorValue2>600){
      Serial.println("Pressure Exceeded, Reducing now.");
      ReducePressure();
  }
}
}

void Sensor2Active(){
  while(Serial.available()==0)
  {
    int sensorValue2 = analogRead(A3);
    sensorValue1 = (sensorValue2);
    sensorValue2 = (sensorValue2);
    Serial.println("Pressure Value 1: ");
    Serial.println(sensorValue1);
    Serial.println("Pressure Value 2: ");
    Serial.println(sensorValue2);
    if (sensorValue1>600 || sensorValue2>600){
      Serial.println("Pressure Exceeded, Reducing now.");
      ReducePressure();
  }
 }
}
void HighFive(){
    pwm.setPWM(0, 0, pulseWidth(0));
    pwm.setPWM(1, 0, pulseWidth(0));
    pwm.setPWM(2, 0, pulseWidth(0));
    Serial.println("High Five!");
}

void First(){

  for (float i=30;i<=90;i+=0.1)
    pwm.setPWM(0, 0, pulseWidth(i));
    delay(200);
    for (float i=90;i<=160;i+=0.05)
      pwm.setPWM(0, 0, pulseWidth(i));
      delay(200);
        
  delay(3000);
    while(Serial.available()==0)
  {
    int sensorValue1 = analogRead(A2);
    int sensorValue2 = analogRead(A3);
    if (sensorValue2>200 && sensorValue1>200){
      Sensor12Active();
    }
    else if (sensorValue1>200 && sensorValue2<150){
      Sensor1Active();
    }
    else if (sensorValue2>200 && sensorValue1<150){
      Sensor2Active();
    }
    else
      Serial.println("No pressure");
  }
}

void Second(){
  for (float i=30;i<=90;i+=0.1)
    pwm.setPWM(1, 0, pulseWidth(i));
    delay(200);
    for (float i=90;i<=160;i+=0.05)
      pwm.setPWM(1, 0, pulseWidth(i));
      delay(200);
        
  delay(3000);
    while(Serial.available()==0)
  {
    int sensorValue1 = analogRead(A2);
    int sensorValue2 = analogRead(A3);
    if (sensorValue2>200 && sensorValue1>200){
      Sensor12Active();
    }
    else if (sensorValue1>200 && sensorValue2<150){
      Sensor1Active();
    }
    else if (sensorValue2>200 && sensorValue1<150){
      Sensor2Active();
    }
    else
      Serial.println("No pressure");
  }
}

void Third(){
  for (float i=30;i<=90;i+=0.1)
    pwm.setPWM(2, 0, pulseWidth(i));
    delay(200);
    for (float i=90;i<=160;i+=0.05)
      pwm.setPWM(2, 0, pulseWidth(i));
      delay(200);
        
  delay(3000);
    while(Serial.available()==0)
  {
    int sensorValue1 = analogRead(A2);
    int sensorValue2 = analogRead(A3);
    if (sensorValue2>200 && sensorValue1>200){
      Sensor12Active();
    }
    else if (sensorValue1>200 && sensorValue2<150){
      Sensor1Active();
    }
    else if (sensorValue2>200 && sensorValue1<150){
      Sensor2Active();
    }
    else
      Serial.println("No pressure");
  }
}

void Reset(){
  pwm.setPWM(0, 0, pulseWidth(30));
  pwm.setPWM(1, 0, pulseWidth(30));
  pwm.setPWM(2, 0, pulseWidth(30));
}

void(* resetFunc) (void) = 0;

void afterAction() {
  Serial.println("\n");
  Serial.println("Release Gripper? (1) Release | (2) Exit \n");
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

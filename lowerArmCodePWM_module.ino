// Include Wire Library for I2C Communications
#include <Wire.h>

// Include Adafruit PWM Library
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH   500    //650
#define MAX_PULSE_WIDTH   2500    //2350
#define FREQUENCY             50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//Define servo position
int posBase=0;
int posWrist=0;
int posJaw=0;

// Define Motor Outputs on PCA9685 board
int servoPinBase = 0;
int servoPinWrist = 1;
int servoPinJaw = 2;




void setup() {
  Serial.begin(9600);
  // Setup PWM Controller object
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  

pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
pinMode(12, INPUT_PULLUP);
  

}

// Function to move motor to specific position
void moveMotorDeg(int moveDegree, int motorOut)
{
  int pulse_wide, pulse_width;

  // Convert to pulse width
  pulse_wide = map(moveDegree, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  pulse_width = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  
  //Control Motor
  pwm.setPWM(motorOut, 0, pulse_width);
}



void loop() {
  
  int sensorVal1 = digitalRead(7);
  int sensorVal2 = digitalRead(8);
  int sensorVal3 = digitalRead(9);
  int sensorVal4 = digitalRead(10);
  int sensorVal5 = digitalRead(11);
  int sensorVal6 = digitalRead(12);
/*
  Serial.println("sensorVal1");
  Serial.println(sensorVal3);
  Serial.println("pos");
  Serial.println(posWrist);     */
//////////////////////////////////////////////////
   if (sensorVal1 == HIGH) {

    posBase=0;
    moveMotorDeg(posBase,servoPinBase);

  } else {
  
     posBase=90;
     moveMotorDeg(posBase,servoPinBase);
  }
  /*////////////////////////////////////////////////
  if (sensorVal2 == HIGH) {

    posBase=90;


  } else {

    

  }  */
  ///////////////////////////////////////////////////
  if (sensorVal3 == HIGH) {

    

  } else {

   posWrist++;
   moveMotorDeg(posWrist,servoPinWrist);

  }
  //////////////////////////////////////////////////
  if (sensorVal4 == HIGH) {

    

  } else {

    posWrist--;
    moveMotorDeg(posWrist,servoPinWrist);
  }
  ///////////////////////////////////////////////////
  if (sensorVal5 == HIGH) {

   

  } else {

   posJaw++;
moveMotorDeg(posJaw,servoPinJaw);
  }
  if (sensorVal6 == HIGH) {

   

  } else {

   posJaw--;
moveMotorDeg(posJaw,servoPinJaw);
  }

//pwm.setPWM(servoPinBase, 0, posBase);
  
  
   

 delay(60);

}

/*
  TinyCircuits Dual Motor Driver TinySheild Basic Example

  This example code shows basic usage of the ASD2302 Dual Motor Driver TinyShield.
  The library intance is created with the hardware address of the motor driver
  (up to 4 boards/8 motors) and then intialized with begin(maximum PWM value).
  The Dual Motor Driver has 16 bit PWM output capability, but keep in mind the
  output frequency is low when using a large timer value- great for some things,
  like driving servos. To drive the motors, use setMotor(motor, value) to set
  motor 1 or 2 to -maxPWM to +maxPWM.

  The board uses the ATtiny841 microcontroller and has direct register access-
  so just about any of the internal peripherals could be put to use.

  Written 30 July 2015
  By Ben Rose
  Modified 24 May 2019
  By Hunter Hykes

  https://TinyCircuits.com
*/

#include <Wire.h>
#include "MotorDriver.h"
<<<<<<< HEAD:examples/Dual-Motor_TinyShield_example/Dual-Motor_TinyShield_example.ino

#if defined(ARDUINO_ARCH_SAMD)
  #define SerialMonitorInterface SerialUSB
#else
  #define SerialMonitorInterface Serial
#endif

MotorDriver motor(0); //value passed is the address- remove resistor R1 for 1, R2 for 2, R1 and R2 for 3

=======
//#define Serial SerialUSB
MotorDriver motor(2);//value passed is the address- remove resistor R1 for 1, R2 for 2, R1 and R2 for 3

>>>>>>> 467d5e4b7f3e73535a39288ce4db8730d0e94abd:examples/Dual-Motor_TinySheild_example/Dual-Motor_TinySheild_example.ino
int maxPWM = 10000;
int steps = 100;
int stepSize = maxPWM / steps;

void setup() {
<<<<<<< HEAD:examples/Dual-Motor_TinyShield_example/Dual-Motor_TinyShield_example.ino
  SerialMonitorInterface.begin(9600);
=======
  Serial.begin(9600);
>>>>>>> 467d5e4b7f3e73535a39288ce4db8730d0e94abd:examples/Dual-Motor_TinySheild_example/Dual-Motor_TinySheild_example.ino
  Wire.begin();
  //The value passed to begin() is the maximum PWM value, which is 16 bit(up to 65535)
  //This value also determines the output frequency- by default, 8MHz divided by the maxPWM value
  if (motor.begin(maxPWM)) {
<<<<<<< HEAD:examples/Dual-Motor_TinyShield_example/Dual-Motor_TinyShield_example.ino
    SerialMonitorInterface.println("Motor driver not detected!");
=======
    Serial.println("Motor driver not detected!");
>>>>>>> 467d5e4b7f3e73535a39288ce4db8730d0e94abd:examples/Dual-Motor_TinySheild_example/Dual-Motor_TinySheild_example.ino
    while (1);
  }
  //The failsafe turns off motors if a command is not sent in a certain amount of time.
  //Failsafe is set in milliseconds- comment or set to 0 to disable
  motor.setFailsafe(1000);
}

void loop() {
  int i;
  for (i = -maxPWM; i < maxPWM; i += stepSize) {
    delay(10);
    motor.setMotor(1, i);
    motor.setMotor(2, i);
  }
  for (i = maxPWM; i > -maxPWM; i -= stepSize) {
    delay(10);
    motor.setMotor(1, i);
    motor.setMotor(2, i);
  }
}

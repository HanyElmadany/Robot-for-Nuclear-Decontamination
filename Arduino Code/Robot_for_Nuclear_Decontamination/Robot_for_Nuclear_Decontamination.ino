/*===================================================================================*
 |   Title:        Remote-Controlled Robot for Nuclear Decontamination
 |
 |   Purpose:      Removal of Nuclear Pollution, to reduce the risk to humans
 |
 |   Description:  Robot controlled by mobile phone using bluetooth module HC-06,
 |                 that control the direction and the speed of the stepper motors
 |                 that attached to the mecanum wheels which used in our robot,
 |                 also it will control the servo motors that used in the robot arm,
 |                 and for detecting the nuclear radiation we used Gaiger Muller tube
 |                 sensor that controlled with arduino-nano 
  +----------------------------------------------------------------------------------
 |                             By: Hany Elmadany
 *=================================================================================*/
#include <SoftwareSerial.h>
#include <AccelStepper.h>
#include <Servo.h>
Servo motor1;        /*   Waist Servo        */
Servo motor2;        /*   Shoulder Servo     */
Servo motor3;        /*   Elbow Servo        */
Servo motor4;        /*   Wrist Pitch Servo  */
Servo motor5;        /*   wrist Roll Servo   */
Servo motor6;        /*   Gripper Servo      */
SoftwareSerial Bluetooth(A8, 38); // HC-05 Bluetooth (TX, RX)

// Define the stepper motors and the pins the will use
AccelStepper LeftBackWheel(1, 42, 43);        /*   Stepper 1   */
AccelStepper LeftFrontWheel(1, 40, 41);       /*   Stepper 2   */
AccelStepper RightBackWheel(1, 44, 45);       /*   Stepper 3   */
AccelStepper RightFrontWheel(1, 46, 47);      /*   Stepper 4   */
int wheelSpeed = 800;
int motor1PPos, motor2PPos, motor3PPos, motor5PPos, motor4PPos, motor6PPos;        // previous position
int speedDelay = 25;
int index = 0;
int dataIn;
int m = 0;
void setup() {
  
  // Set initial values for the steppers
  
  LeftFrontWheel.setMaxSpeed(3000);
  LeftBackWheel.setMaxSpeed(3000);
  RightFrontWheel.setMaxSpeed(3000);
  RightBackWheel.setMaxSpeed(3000);
  
  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(7);
  motor4.attach(9);
  motor5.attach(8);
  motor6.attach(10);
  Bluetooth.begin(9600);      // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(5);
  delay(20);
  Serial.begin(9600);
  
  // Move robot arm to initial position
  
  motor1PPos = 90;
  motor1.write(motor1PPos);
  motor2PPos = 135;
  motor2.write(motor2PPos);
  motor3PPos = 0;
  motor3.write(motor3PPos);
  motor5PPos = 90;
  motor5.write(motor5PPos);
  motor4PPos = 45;
  motor4.write(motor4PPos);
  motor6PPos = 10;
  motor6.write(motor6PPos);
}
void loop() {
  
  // Check for incoming data
  
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();              // Read the data
    if (dataIn == 0) {
      m = 0;
    }
    if (dataIn == 1) {
      m = 1;
    }
    if (dataIn == 2) {
      m = 2;
    }
    if (dataIn == 3) {
      m = 3;
    }
    if (dataIn == 4) {
      m = 4;
    }
    if (dataIn == 5) {
      m = 5;
    }
    if (dataIn == 6) {
      m = 6;
    }
    if (dataIn == 7) {
      m = 7;
    }
    if (dataIn == 8) {
      m = 8;
    }
    if (dataIn == 9) {
      m = 9;
    }
    if (dataIn == 10) {
      m = 10;
    }
    if (dataIn == 11) {
      m = 11;
    }
    if (dataIn == 12) {
      m = 12;
    }
    if (dataIn == 14) {
      m = 14;
    }
    if (dataIn == 16) {
      m = 16;
    }
    if (dataIn == 17) {
      m = 17;
    }
    if (dataIn == 18) {
      m = 18;
    }
    if (dataIn == 19) {
      m = 19;
    }
    if (dataIn == 20) {
      m = 20;
    }
    if (dataIn == 21) {
      m = 21;
    }
    if (dataIn == 22) {
      m = 22;
    }
    if (dataIn == 23) {
      m = 23;
    }
    if (dataIn == 24) {
      m = 24;
    }
    if (dataIn == 25) {
      m = 25;
    }
    if (dataIn == 26) {
      m = 26;
    }
    if (dataIn == 27) {
      m = 27;
    }
    
    // Move the Mecanum wheels
    
    if (m == 4) {
      moveSidewaysLeft();
    }
    if (m == 5) {
      moveSidewaysRight();
    }
    if (m == 2) {
      moveForward();
    }
    if (m == 7) {
      moveBackward();
    }
    if (m == 3) {
      moveRightForward();
    }
    if (m == 1) {
      moveLeftForward();
    }
    if (m == 8) {
      moveRightBackward();
    }
    if (m == 6) {
      moveLeftBackward();
    }
    if (m == 9) {
      rotateLeft();
    }
    if (m == 10) {
      rotateRight();
    }
    if (m == 0) {
      stopMoving();
    }
    
    // Mecanum wheels speed
    
    if (dataIn > 30 & dataIn < 100) {
      wheelSpeed = dataIn * 20;
    }
    
    // Move robot arm
    
    // Move motor 1 in negative direction
    
    while (m == 16) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor1.write(motor1PPos);
      motor1PPos--;
      delay(speedDelay);
    }
    
    // Move motor 1 in positive direction
    
    while (m == 17) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor1.write(motor1PPos);
      motor1PPos++;
      delay(speedDelay);
    }
    
    // Move motor 2
    
    while (m == 19) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor2.write(motor2PPos);
      motor2PPos--;
      delay(speedDelay);
    }
    while (m == 18) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor2.write(motor2PPos);
      motor2PPos++;
      delay(speedDelay);
    }
    
    // Move motor 3
    
    while (m == 20) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor3.write(motor3PPos);
      motor3PPos++;
      delay(speedDelay);
    }
    while (m == 21) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor3.write(motor3PPos);
      motor3PPos--;
      delay(speedDelay);
    }
    
    // Move motor 5
    
    while (m == 23) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor5.write(motor5PPos);
      motor5PPos--;
      delay(speedDelay);
    }
    while (m == 22) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor5.write(motor5PPos);
      motor5PPos++;
      delay(speedDelay);
    }
    
    // Move motor 4
    
    while (m == 25) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor4.write(motor4PPos);
      motor4PPos--;
      delay(speedDelay);
    }
    while (m == 24) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor4.write(motor4PPos);
      motor4PPos++;
      delay(speedDelay);
    }
    
    // Move motor 6
    
    while (m == 26) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor6.write(motor6PPos);
      motor6PPos++;
      delay(speedDelay);
    }
    while (m == 27) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      motor6.write(motor6PPos);
      motor6PPos--;
      delay(speedDelay);
    }
    
    // If arm speed slider is changed
    
    if (dataIn > 101 & dataIn < 250) {
      speedDelay = dataIn / 10; // Change servo speed (delay time)
    }
  }
  LeftFrontWheel.runSpeed();
  LeftBackWheel.runSpeed();
  RightFrontWheel.runSpeed();
  RightBackWheel.runSpeed();
}

/*******************************************************************
*                                                                  *
*------ Functions To control The Mecanum Wheels Movements ---------*
*                                                                  *
*******************************************************************/

void moveForward() {
  LeftFrontWheel.setSpeed(wheelSpeed);
  LeftBackWheel.setSpeed(wheelSpeed);
  RightFrontWheel.setSpeed(wheelSpeed);
  RightBackWheel.setSpeed(wheelSpeed);
}
void moveBackward() {
  LeftFrontWheel.setSpeed(-wheelSpeed);
  LeftBackWheel.setSpeed(-wheelSpeed);
  RightFrontWheel.setSpeed(-wheelSpeed);
  RightBackWheel.setSpeed(-wheelSpeed);
}
void moveSidewaysRight() {
  LeftFrontWheel.setSpeed(wheelSpeed);
  LeftBackWheel.setSpeed(-wheelSpeed);
  RightFrontWheel.setSpeed(-wheelSpeed);
  RightBackWheel.setSpeed(wheelSpeed);
}
void moveSidewaysLeft() {
  LeftFrontWheel.setSpeed(-wheelSpeed);
  LeftBackWheel.setSpeed(wheelSpeed);
  RightFrontWheel.setSpeed(wheelSpeed);
  RightBackWheel.setSpeed(-wheelSpeed);
}
void rotateLeft() {
  LeftFrontWheel.setSpeed(-wheelSpeed);
  LeftBackWheel.setSpeed(-wheelSpeed);
  RightFrontWheel.setSpeed(wheelSpeed);
  RightBackWheel.setSpeed(wheelSpeed);
}
void rotateRight() {
  LeftFrontWheel.setSpeed(wheelSpeed);
  LeftBackWheel.setSpeed(wheelSpeed);
  RightFrontWheel.setSpeed(-wheelSpeed);
  RightBackWheel.setSpeed(-wheelSpeed);
}
void moveRightForward() {
  LeftFrontWheel.setSpeed(wheelSpeed);
  LeftBackWheel.setSpeed(0);
  RightFrontWheel.setSpeed(0);
  RightBackWheel.setSpeed(wheelSpeed);
}
void moveRightBackward() {
  LeftFrontWheel.setSpeed(0);
  LeftBackWheel.setSpeed(-wheelSpeed);
  RightFrontWheel.setSpeed(-wheelSpeed);
  RightBackWheel.setSpeed(0);
}
void moveLeftForward() {
  LeftFrontWheel.setSpeed(0);
  LeftBackWheel.setSpeed(wheelSpeed);
  RightFrontWheel.setSpeed(wheelSpeed);
  RightBackWheel.setSpeed(0);
}
void moveLeftBackward() {
  LeftFrontWheel.setSpeed(-wheelSpeed);
  LeftBackWheel.setSpeed(0);
  RightFrontWheel.setSpeed(0);
  RightBackWheel.setSpeed(-wheelSpeed);
}
void stopMoving() {
  LeftFrontWheel.setSpeed(0);
  LeftBackWheel.setSpeed(0);
  RightFrontWheel.setSpeed(0);
  RightBackWheel.setSpeed(0);
}

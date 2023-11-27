#include <Arduino.h>
#include <AFMotor.h>
#include <Servo.h>


// servo isnt used, but just in case i need it
Servo myservo;
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char command; 

const int buzzerPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void forward() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}

void back() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255); 
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void left() {
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void right() {
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255); 
  motor2.run(BACKWARD);
  motor3.setSpeed(255); 
  motor3.run(FORWARD); 
  motor4.setSpeed(255); 
  motor4.run(FORWARD);
} 

void Stop() {
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE);
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}

void buzzerON() {
  digitalWrite(buzzerPin, HIGH);
}

void buzzerOFF() {
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  if(Serial.available() > 0) {
    command = Serial.read();
    Stop(); 
    switch(command) {
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'V':
      buzzerON();
      break;
    case 'v':
      buzzerOFF();
      break;
    }
  }
}
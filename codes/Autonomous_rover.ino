#include <Servo.h>
#include <NewPing.h> 


const int trigger = A0;
const int echo = A1;
float dist;
int distance;
long duration;
int frontin1 = 2;
int frontin2 = 8;
int frontin3 = 12;
int frontin4 = 13;
int frontenA = 5;
int frontenB = 6;

int backin1 = 3;
int backin2 = 4;
int backin3 = 7;
int backin4 = 11;
int backenA = 9;
int backenB = 10;
int servo_motor = A2;

Servo servo;
NewPing ultrasonic(trigger, echo, 200);

void setup() {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(frontenA, OUTPUT);
  pinMode(frontenB, OUTPUT);
  pinMode(frontin1, OUTPUT);
  pinMode(frontin2, OUTPUT);
  pinMode(frontin3, OUTPUT);
  pinMode(frontin4, OUTPUT);

  pinMode(backenA, OUTPUT);
  pinMode(backenB, OUTPUT);
  pinMode(backin1, OUTPUT);
  pinMode(backin2, OUTPUT);
  pinMode(backin3, OUTPUT);
  pinMode(backin4, OUTPUT);

  servo.attach(servo_motor);
  
}

void loop() {

  int rightDistance = 0;
  int leftDistance = 0;
  
//  digitalWrite(trigger, LOW);
//  delayMicroseconds(5); 
//  
//  digitalWrite(trigger, HIGH);
//  delayMicroseconds(10); 
//  
//  digitalWrite(trigger, LOW);
//  
//  dist = pulseIn(echo,HIGH);
//  distance = dist/58;
//  Serial.println(distance);

  distance = getDistance();
  Serial.println(distance);

  analogWrite(frontenA, 250);
  analogWrite(frontenB, 250);

  analogWrite(backenA, 250);
  analogWrite(backenB, 250);

  if(distance >= 20){
    moveForward();
    distance = getDistance();
  }

  else {
    halt();
    delay(2000);
    moveBackward();
    delay(2000);
    halt();
    delay(1000);
    
    rightDistance = lookRight();
    delay(1000);

    leftDistance = lookLeft();
    delay(1000);

    if(rightDistance > leftDistance){
      turnRight();
      delay(2000); 
    }

    else if(leftDistance > rightDistance){
      turnLeft();
      delay(2000);
    }

    else if(leftDistance == rightDistance){
      turnRight();
      delay(2000);
    }
    
  }
  
  distance = getDistance();

}

int getDistance(){
  delay(70);
  int range = ultrasonic.ping_cm();
  if (range == 0){
    range = 250;
  }

  return range;
  
}

int lookRight(){  
  servo.write(0);
  delay(500);
  distance = getDistance;
  delay(500);
  servo.write(90);
  return distance;
}

int lookLeft(){  
  servo.write(180);
  delay(500);
  distance = getDistance;
  delay(500);
  servo.write(90);
  return distance;
}

void moveBackward(){

  digitalWrite(frontin1, HIGH);
  digitalWrite(frontin2, LOW);
  digitalWrite(frontin3, LOW);
  digitalWrite(frontin4, HIGH);

//  digitalWrite(backin1, HIGH);
//  digitalWrite(backin2, LOW);
//  digitalWrite(backin3, LOW);
//  digitalWrite(backin4, HIGH);  
  
}

void moveForward(){

  digitalWrite(frontin1, LOW);
  digitalWrite(frontin2, HIGH);
  digitalWrite(frontin3, HIGH);
  digitalWrite(frontin4, LOW);

//  digitalWrite(backin1, LOW);
//  digitalWrite(backin2, HIGH);
//  digitalWrite(backin3, HIGH);
//  digitalWrite(backin4, LOW);
//  
}

void turnRight(){

  digitalWrite(frontin1, HIGH);
  digitalWrite(frontin2, LOW);
  digitalWrite(frontin3, LOW);
  digitalWrite(frontin4, LOW);

//  digitalWrite(backin1, HIGH);
//  digitalWrite(backin2, LOW);
//  digitalWrite(backin3, HIGH);
//  digitalWrite(backin4, LOW);
  
}

void turnLeft(){

  digitalWrite(frontin1, LOW);
  digitalWrite(frontin2, LOW);
  digitalWrite(frontin3, LOW);
  digitalWrite(frontin4, HIGH);

//  digitalWrite(backin1, LOW);
//  digitalWrite(backin2, HIGH);
//  digitalWrite(backin3, LOW);
//  digitalWrite(backin4, HIGH);
}

void halt(){

  digitalWrite(frontin1, LOW);
  digitalWrite(frontin2, LOW);
  digitalWrite(frontin3, LOW);
  digitalWrite(frontin4, LOW);

//  digitalWrite(backin1, LOW);
//  digitalWrite(backin2, LOW);
//  digitalWrite(backin3, LOW);
//  digitalWrite(backin4, LOW);
}

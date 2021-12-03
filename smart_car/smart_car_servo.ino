#include<Servo.h>

int servo = 11;
//Ultrasonic Senosr Interfacing
int trigPin = 12;
int echoPin =13 ;

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

//Servo Motor
Servo Servo1;
// Speed control
int speed = 200;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Ultrasonic Trig, Echo
    Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

/*int ultrasonic()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  Serial.print("Distance: ");
  Serial.println(distance);  
  return distance;
}*/

void forward()
{
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, speed);
  analogWrite(enB, speed);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(700);
  
}

void reverse()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);
}

void leftTurn()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void rightTurn()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
}



int rightServo()
{
  int rightObstacle;
  //right
  Servo1.write(0);
  delay(1000);
  rightObstacle = ultrasonic();
  return rightObstacle;
}

int leftServo()
{
  int leftObstacle
  //left
  Servo1.write(150);  
  delay(1000);
  leftObstacle = ultrasonic();    
  return leftObstacle;
}

void loop()
{
  int fobstacle;
  fobstacle = ultrasonic();
  if(fobstacle<20)
  {
      Stop();
      delay(2000);
      myservo(); 
  }
  
  else
  {
    forward();  
  }
}

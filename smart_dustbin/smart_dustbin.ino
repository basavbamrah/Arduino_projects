#include <Servo.h>

int trigPin = 2;
int echoPin = 3;
int servoMotor = 7;
int angle = 0;
int dis_Value = 0;

// Create a servo object 
Servo Servo1; 

void setup() {
  // Defining the function of pins that are attached
  Serial.begin(9600);
  Servo1.attach(servoMotor);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// This function return the distance as per sensor.
int Ultrasonic()
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
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
  return distance;
}

void loop() {
  dis_Value = Ultrasonic();
  
  if (dis_Value<30)     // person detected
  {
     Serial.println("Opening...");
     for (angle = 90; angle>0; angle--)
     {
        Servo1.write(angle);
        delay(15); 
     }
     delay(8000);         // wait time
     Serial.println("Closing...");
     for (angle = 0; angle<90; angle++)
     {
          Servo1.write(angle);
          delay(50); 
     }
  } 
}

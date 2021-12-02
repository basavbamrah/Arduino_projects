#define buzzer 9
#define echopin 11
#define trigpin 12
#include<Servo.h>

long duration;
int dist;
Servo obj;
int pos;

void sensor()
{
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);

  dist = duration * 0.034 / 2;
  if(dist<40)
  {
 digitalWrite(buzzer,HIGH);
 delay(10);
  }
 else{
 digitalWrite(buzzer,LOW);
 delay(10);
 } 
  Serial.print("DISTANCE: ");
  Serial.print(dist);
  Serial.println(" cm");
}

void setup() {
  pinMode(buzzer, OUTPUT);
  obj.attach(6);
  pinMode(trigpin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echopin, INPUT);
  Serial.begin(9600)  ;
}

void loop() {
/*
  for(pos=0; pos<=180;pos++)
  {
    obj.write(pos);
    sensor();  
  }
  for(pos=180; pos>=0;pos--)
  {
    obj.write(pos);
    sensor();  
  }
  */
  sensor();
}

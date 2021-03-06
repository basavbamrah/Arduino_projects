/**
Application of Ultrasonic sensor
Calculate distance of an object and display it on liquid Crystal Display
*/

#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 3, 4, 5, 6); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
const int trigPin = 8;
const int echoPin = 9;
long duration;
int distanceCm, distanceInch;

void setup() {

lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
//Serial.begin(9600);
}

void loop() {
 // lcd.print("Hello world ");
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration * 0.01330 / 2;
lcd.setCursor(0,0);
lcd.print("Distance "+ (String)distanceCm +"cm");
lcd.setCursor(0,1);
lcd.print("Distance "+ (String)distanceInch +"\"");

delay(500);

lcd.clear();

}

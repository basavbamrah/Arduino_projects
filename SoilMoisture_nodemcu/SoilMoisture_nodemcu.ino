#include "ESP8266WiFi.h"
#include "ThingSpeak.h"
#include "DHT.h"
#define relay 7
// WiFi parameters to be configured
String apiKey = "7A55RZGEWSY7G7ZY";
const char *ssid =  "samsung m10";
const char *pass =  "1234567800";
const char* server = "api.thingspeak.com";   
int WET= 16; // Wet Indicator at Digital pin D0
int DRY= 2;  // Dry Indicator at Digital pin D4
int sense_Pin = 0; // sensor input at Analog pin A0
int value = 0;
DHT dht(D2, DHT11);
unsigned long myChannelid=1741128;
WiFiClient client;

void setup() {
   Serial.begin(9600);
   pinMode(WET, OUTPUT);
   pinMode(DRY, OUTPUT);
   pinMode(sense_Pin,OUTPUT);
   delay(2000);
  dht.begin();
  // Connect to WiFi
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
}
//void sendVal(int n)
//{
//  int x = ThingSpeak.writeField(myChannelid,1,n, server);
//}

void loop() {
  digitalWrite(sense_Pin, HIGH);
   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(sense_Pin);
//   Serial.println(value);
   value= value/10;
   Serial.println(value);
   //sendVal(value);

        if(value<50)
        {
            digitalWrite(WET, HIGH);
            digitalWrite(relay,LOW);
        }
       else
       {
           digitalWrite(DRY,HIGH);
           digitalWrite(relay,HIGH);
       }

       delay(1000);
       digitalWrite(WET,LOW);
       digitalWrite(sense_Pin, LOW);   // Turn the sensor OFF
       digitalWrite(DRY, LOW);
        float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (client.connect(server, 80)) {
    String postStr = apiKey;
    postStr +="&field1=";
    postStr += String(value);
    postStr += "&field2=";
    postStr += String(t);
    postStr += "&field3=";
    postStr += String(h);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("\t");
    Serial.print("Humidity: ");
    Serial.println(h);

  }
  client.stop();
  delay(1000);
}

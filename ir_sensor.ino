int ir = 9;
int bz=5;
void setup() {
   pinMode(ir, INPUT);
   pinMode(bz, OUTPUT);
   Serial.begin(19200);
}

void loop() {
  int status = digitalRead(ir);
  //Serial.print(status);
 if(status==0)
 {
  digitalWrite(bz,HIGH);
  Serial.println("HIGH");
  delay(1000);
  
 } else
 {
  digitalWrite(bz,LOW);
  Serial.println("LOW");
  delay(1000);
  }
 }

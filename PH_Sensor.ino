#define SensorPin 0                            //pH meter Analog output to Arduino analog Input 0
unsigned long int avgValue;               //store the average value of the sensor feedback
float  b; 
int buf [10], temp;

void setup ()
{
       pinMode(13, OUTPUT);
       Serial.begin(9600);
       Serial.println("Ready");                //Test the serial monitor 
}

void loop()
{
  for(int  i=0; i<10; i++)                 //get 10 sample value from the sensor for smooth the value
    {
      buf[i]=analogRead(SensorPin);
      delay(10);
     }
  for(int i=0; i<9; i++)                    // Sort the analog from small to large
      {
        for(int j= i+1;j<10;j++)
            {
              if(buf[i]>buf[j])
                {
                  temp=buf[i];
                  buf[i]=buf[j];
                  buf[j]=temp;
                 }
              }
          } 
avgValue= 0;
for(int i=2; i<8; i++)                                                //take the average value of 6 center sample
  avgValue+=buf[i];
float pHValue = (float)avgValue*5.0/1024/6;        // convert the analog into milivolt
pHValue=3.5*pHValue;                                          //convert the milivolt into pH value
Serial.print("pH:");
Serial.print(pHValue,2);
Serial.println("  ");
digitalWrite(13, HIGH);
delay(800);
digitalWrite(13,LOW);

}

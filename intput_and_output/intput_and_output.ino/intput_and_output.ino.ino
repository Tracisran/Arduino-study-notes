
int outPin = 4;
void setup() {
 pinMode(13,OUTPUT);
 Serial.begin(9600);
 Serial.println("ENTER 1 OR 0");

}

void loop() {
   if(Serial.available()>0)
  {
    char ch = Serial.read();
    if (ch=='1')
    {
      digitalWrite(13,HIGH);
      }
      else if(ch=='0')
      {
        digitalWrite(13,LOW);
        }
    
    }

}

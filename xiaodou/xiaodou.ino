void setup() {
 pinMode(13,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,INPUT);
 Serial.begin(9600);
 Serial.println("ENTER 1 OR 0");


}

void loop() {
  if(Serial.available()>0)
  {
    char ch =Serial.read();
    if(ch='1')
    {
      digitalWrite(4,HIGH);
      }
     else if(ch='0')
     {
      digitalWrite(4,LOW);
      }
    }
  if(digitalRead(5)==HIGH)
  {
    digitalWrite(13,HIGH);
    }
    else if(digitalRead(5)==LOW)
    {
      digitalWrite(13,LOW);
      }
}

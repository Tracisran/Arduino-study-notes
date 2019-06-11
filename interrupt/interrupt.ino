int period=500;


void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
  attachInterrupt(0,goFast,FALLING);// put your setup code here, to run once:

}

void loop() {
  digitalWrite(13,HIGH);
  delay(period);
  digitalWrite(13,LOW);
  delay(period); 

}

void goFast()
{
  period=100;
  }

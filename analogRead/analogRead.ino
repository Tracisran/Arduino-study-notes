int analogPin=0;
void setup() 
{
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  int reading =analogRead(analogPin);
  float voltage=reading/204.6;
  Serial.print("Reading=");
  Serial.print(reading);
  Serial.print("\t\tVolts=");
  Serial.println(voltage);
  delay(500);// put your main code here, to run repeatedly:

}

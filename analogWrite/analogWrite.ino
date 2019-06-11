int analogPin=3;

void setup() {
 // pinMode(3,OUTPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  Serial.println("ENTER VOLTS 0 TO 5");
  // put your setup code here, to run once:
}

void loop() {
  if (Serial.available()>0)
  {
    char ch =Serial.read();
    int volts = (ch-'0')*51;
//int volts = 76.5;
    analogWrite(3,volts);   
    analogWrite(5,volts);  
    }// put your main code here, to run repeatedly:
      int reading =analogRead(analogPin);
  float voltage=reading/204.6;
  Serial.print("Reading=");
  Serial.print(reading);
  Serial.print("\t\tVolts=");
  Serial.println(voltage);
 // delay(500);// put your main code here, to run repeatedly:

}

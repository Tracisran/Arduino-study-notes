void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));// put your setup code here, to run once:

}

void loop() {
  int number=random(1,7);
  Serial.println(number);
  delay(500);// put your main code here, to run repeatedly:

}

const int tx =1 ;
const int rx = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
pinMode(rx,INPUT_PULLUP);
pinMode(tx,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

}

#include <SoftwareSerial.h>
 String comdata = "";
SoftwareSerial mySerial(0, 1); // RX, TX
 
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 
 
  Serial.println("Goodnight moon!");
 
  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  mySerial.println("Hello, world?");
}
 
void loop() { // run over and over
  while (mySerial.available() > 0)
  {
    comdata += int(Serial.read()) - '0';
    delay(2);
  }
  if(comdata.length() > 0)
  {
    for(int i = 0; i < comdata.length(); i++)
    {
      if(comdata[i]=='0'||comdata[i]=='1')
      {
        digitalWrite(i + 2, comdata[i] - '0');
        Serial.print("Pin ");
        Serial.print(i + 2);
        Serial.print(" is ");
        Serial.println(comdata[i]);
      }
    }
    comdata = "";
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

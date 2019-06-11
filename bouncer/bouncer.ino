#include <Bounce2.h>
int inputPin =5;
int ledPin=13;
int ledValue=LOW;
Bounce bouncer =Bounce();



void setup() {
 pinMode(inputPin,INPUT);
 digitalWrite(inputPin,HIGH);
 pinMode(ledPin,OUTPUT);// put your setup code here, to run once:
 bouncer.attach(inputPin);
 bouncer.interval(5);
}

void loop() {
  if (bouncer.update()&&bouncer.read()==LOW)
  {
    ledValue=!ledValue;
    digitalWrite(ledPin,ledValue);
    }// put your main code here, to run repeatedly:

}

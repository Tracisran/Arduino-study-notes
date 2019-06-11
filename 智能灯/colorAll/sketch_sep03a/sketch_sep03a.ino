/**************************************************************

Name:      Gizwits + ArduinoUnoWiFi Library 
Author:   tli@gizwits.com / bing@arduino.org.cn 
Version:  V1.0
Init:     2016-12-23
Modify:   2016-12-23
****************************************************************/
#include <Gizwits.h>
#include <Wire.h>
#include<Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS,PIN,NEO_GRB+NEO_KHZ800);

Gizwits myGizwits;

void setPiexlColorAll(uint8_t r,uint8_t g,uint8_t b)
{
    for(int i = 0; i < pixels.numPixels(); i++)
    {
      pixels.setPixelColor(i,pixels.Color(r,g,b));
      pixels.setPixelColor(i,pixels.Color(r,g,b));
      pixels.show();
      
      } 
  
  }
void setup() {
  // put your setup code here, to run once:
pixels.begin();
pixels.show();  //Initialize all pixels to 'off'
  //Serial.begin(9600);
  //myGizwits.begin();
}

void loop() {  
  
  //Configure network
  //if(XXX) //Trigger Condition
  //myGizwits.setBindMode(0x02);  //0x01:Enter AP Mode;0x02:Enter Airlink Mode
    /*


  bool varR_LED_OnOff = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_ONOFF))
  {
    myGizwits.read(EVENT_LED_ONOFF,&varR_LED_OnOff);//Address for storing data 
  }
  unsigned long varR_LED_Color = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_COLOR))
  {
    myGizwits.read(EVENT_LED_COLOR,&varR_LED_Color);//Address for storing data 
  }
  unsigned long varR_LED_R = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_R))
  {
    myGizwits.read(EVENT_LED_R,&varR_LED_R);//Address for storing data 
  }
  unsigned long varR_LED_G = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_G))
  {
    myGizwits.read(EVENT_LED_G,&varR_LED_G);//Address for storing data 
  }
  unsigned long varR_LED_B = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_B))
  {
    myGizwits.read(EVENT_LED_B,&varR_LED_B);//Address for storing data 
  }


  //binary datapoint handle
  */

setPiexlColorAll(10,0,0);
delay(500);
setPiexlColorAll(0,10,0);
delay(500);
setPiexlColorAll(0,0,10);
delay(500);

  //myGizwits.process();
}

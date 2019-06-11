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
int ledPin = 13;
bool varR_LED_OnOff = 0;
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

#define   KEY1              5
#define   KEY2              7
#define   KEY1_SHORT_PRESS  1
#define   KEY1_LONG_PRESS   2
#define   KEY2_SHORT_PRESS  4
#define   KEY2_LONG_PRESS   8
#define   NO_KEY            0
#define   KEY_LONG_TIMER    3
unsigned long Last_KeyTime = 0;

unsigned long gokit_time_s(void)
{
  return millis() / 1000;
}

char gokit_key1down(void)
{
  unsigned long keep_time = 0;
  if (digitalRead(KEY1) == LOW)
  {
    delay(100);
    if (digitalRead(KEY1) == LOW)
    {
      keep_time = gokit_time_s();
      while (digitalRead(KEY1) == LOW)
      {
        if ((gokit_time_s() - keep_time) > KEY_LONG_TIMER)
        {
          Last_KeyTime = gokit_time_s();
          return KEY1_LONG_PRESS;
        }
      } //until open the key

      if ((gokit_time_s() - Last_KeyTime) > KEY_LONG_TIMER)
      {
        return KEY1_SHORT_PRESS;
      }
      return 0;
    }
    return 0;
  }
  return 0;
}

char gokit_key2down(void)
{
  int unsigned long keep_time = 0;
  if (digitalRead(KEY2) == LOW)
  {
    delay(100);
    if (digitalRead(KEY2) == LOW)
    {
      keep_time = gokit_time_s();
      while (digitalRead(KEY2) == LOW) //until open the key
      {

        if ((gokit_time_s() - keep_time) > KEY_LONG_TIMER)
        {
          Last_KeyTime = gokit_time_s();
          return KEY2_LONG_PRESS;
        }
      }

      if ((gokit_time_s() - Last_KeyTime) > KEY_LONG_TIMER)
      {
        return KEY2_SHORT_PRESS;
      }
      return 0;
    }
    return 0;
  }
  return 0;
}

/*******************************************************
 *    function      : gokit_keydown
 *    Description   : check the gokit key1 or key2 event
 *    return        : KEY1_LONG_PRESS  KEY1_SHORT_PRESS
 *                    KEY2_LONG_PRESS  KEY2_SHORT_PRESS
 *                     0-no keydown event.
 *    Add by Alex.lin    --2014-12-25
******************************************************/
char gokit_keydown(void)
{
  char ret = 0;
  ret |= gokit_key2down();
  ret |= gokit_key1down();
  return ret;

}

void KEY_Handle(void)
{
  /*  Press for over than 3 second is Long Press  */
  switch (gokit_keydown())
  {
    case KEY1_SHORT_PRESS:
      //Serial.println(F("KEY1_SHORT_PRESS , Production Test Mode "));
      myGizwits.setBindMode(WIFI_PRODUCTION_TEST);
      break;
    case KEY1_LONG_PRESS:
     // Serial.println(F("KEY1_LONG_PRESS ,Wifi Reset"));
      myGizwits.setBindMode(WIFI_RESET_MODE);
      break;
    case KEY2_SHORT_PRESS:
      //Serial.println(F("KEY2_SHORT_PRESS Soft AP mode"));
      myGizwits.setBindMode(WIFI_SOFTAP_MODE);
      //Soft AP mode
      break;
    case KEY2_LONG_PRESS:
      //Serial.println(F("KEY2_LONG_PRESS ,AirLink mode"));
      digitalWrite(ledPin,HIGH);
      setPiexlColorAll(5,0,0);
      myGizwits.setBindMode(WIFI_AIRLINK_MODE);
      //AirLink mode
      break;
    default:
      break;
  }
}
void setup() {
  // put your setup code here, to run once:
pixels.begin();
pixels.show();  //Initialize all pixels to 'off'
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

pinMode(KEY1,INPUT_PULLUP);
pinMode(KEY2,INPUT_PULLUP);
  myGizwits.begin();
}
void wifiStatusHandle()
{
  //if(myGizwits.wifiHasBeenSet(WIFI_SOFTAP))
    //Serial.println(F("WIFI_SOFTAP!"));
  
  //if(myGizwits.wifiHasBeenSet(WIFI_AIRLINK))
    //Serial.println(F("WIFI_AIRLINK!"));
  
  //if(myGizwits.wifiHasBeenSet(WIFI_STATION))
    //Serial.println(F("WIFI_STATION!"));
  
  if(myGizwits.wifiHasBeenSet(WIFI_CON_ROUTER))
    digitalWrite(ledPin,LOW);
    //Serial.println(F("WIFI_CON_ROUTER!"));
  
  //if(myGizwits.wifiHasBeenSet(WIFI_DISCON_ROUTER))
    //Serial.println(F("WIFI_DISCON_ROUTER!"));
  
  //if(myGizwits.wifiHasBeenSet(WIFI_CON_M2M))
   // Serial.println(F("WIFI_CON_M2M!"));
  
  //if(myGizwits.wifiHasBeenSet(WIFI_DISCON_M2M))
   // Serial.println(F("WIFI_DISCON_M2M!"));
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
//bool varR_LED_OnOff = 0;
  if(myGizwits.hasBeenSet(EVENT_LED_ONOFF))
  {
    myGizwits.read(EVENT_LED_ONOFF,&varR_LED_OnOff);//Address for storing data 
  }
  
if(varR_LED_OnOff==1)
{
  setPiexlColorAll(5,0,0);
}
else
{
  setPiexlColorAll(0,0,0);
}

  KEY_Handle();//key handle , network configure
  wifiStatusHandle();//WIFI Status Handle
  myGizwits.process();
}

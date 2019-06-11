
#include <Gizwits.h>
#include <Wire.h>
#include<Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 16
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS,PIN,NEO_GRB+NEO_KHZ800);
String comdata = "";
String RR;
String GG;
String BB;
String L="49";
char RRR=0;
char GGG=0;
char BBB=0;
int LL=49;
Gizwits myGizwits;

void setPiexlColorAll(uint8_t r,uint8_t g,uint8_t b)
{
    for(int i = 0; i < pixels.numPixels(); i++)
    {
      pixels.setPixelColor(i,pixels.Color(r,g,b));
      pixels.show();
      
      } 
  
  }
void setup() {
  // put your setup code here, to run once:
pixels.begin();
pixels.show();  //Initialize all pixels to 'off'
  Serial.begin(9600);
  Serial.println("输入1设置颜色，输入2设置亮度");
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
   if(Serial.available()>0)
   {
      char ch = Serial.read();
      if (ch=='1')
      {
        RR="";
        GG="";
        BB="";
        Serial.println("请输入R（0—256）");
        delay(2);
        for(int i=0;i<2000;i++)
        {
           if(Serial.available()>0)
           { 
             comdata += char(Serial.read());             
             Serial.println(comdata);
             RR.concat(comdata); 
             Serial.println(RR);
             comdata = "";
             delay(2);
             if(Serial.available()==0)
             {break;}             
           }
           else
           {
            delay(2);
           }
        }
        if (RR.length()>0)
         {
          Serial.println("R值为");
          Serial.print(RR);
          Serial.println("请输入G");
          delay(2);
          for(int i=0;i<2000;i++)
          {
            if(Serial.available()>0)
            { 
             comdata += char(Serial.read());             
             Serial.println(comdata);
             GG.concat(comdata); 
             Serial.println(GG);
             comdata = "";
             delay(2);
             if(Serial.available()==0)
             {
              break;
             }             
            }
            else
            {
            delay(2);
            }
          }
          if (GG.length()>0)
          {
           Serial.println("G值为");
           Serial.print(GG);
           Serial.println("请输入B");
           delay(2);
           for(int i=0;i<2000;i++)
           {
            if(Serial.available()>0)
            { 
             comdata += char(Serial.read());             
             Serial.println(comdata);
             BB.concat(comdata); 
             Serial.println(BB);
             comdata = "";
             delay(2);
             if(Serial.available()==0)
             {
              break;
             }             
           }
           else
           {
            delay(2);
           }
          }
         if (BB.length()>0)
         {
          Serial.println("B值为");
          Serial.print(BB);          
          }
          else
          {
           Serial.println("错误");
           }          
          }
          else
          {
           Serial.println("错误");
           }
         }
         else
          {
           Serial.println("错误");
         }
      }
      else if (ch=='2')
      {
       Serial.println("请输入亮度1,2,3,4,5");
        delay(2);
        for(int i=0;i<2000;i++)
        {
           if(Serial.available()>0)
           { 
              L = Serial.read();
             break;
           }
           else
          {
           delay(2);
         }
        } 
        Serial.println(L);      
        }
   }

 RRR =RR.toInt();
  GGG =GG.toInt();
   BBB =BB.toInt();
   LL=L.toInt();
LL=LL-48;
float temp = 256.0/(RRR*LL+GGG*LL+BBB*LL); 
setPiexlColorAll((RRR*temp/20.0),(GGG*temp/20.0),(BBB*temp/20.0));


  //myGizwits.process();
}

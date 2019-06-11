//在esp32和nodemcu使用
#define BLYNK_PRINT Serial

//nodemcu
//#include <ESP8266WiFi.h>
//#include <BlynkSimpleEsp8266.h>
//esp32s
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "474f9b8c46df4f03a5bd8f3b9a4e733f";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "RAN";
char pass[] = "123456123";
#define left_Zheng 12   
#define left_Fan 13
#define right_Fan 32
#define right_Zheng 33

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  if (pinValue1 == 1)
  {//直走
     Serial.println("Forward");
    digitalWrite(left_Zheng,1);      
    digitalWrite(right_Zheng,1);
    digitalWrite(left_Fan,0);    //关闭反转
    digitalWrite(right_Fan,0);
   }
  
}
BLYNK_WRITE(V2)
{
  int pinValue2 = param.asInt();
  if (pinValue2 == 1)
  { Serial.println("Right");
    //右转，左轮正转右轮反转
    digitalWrite(left_Zheng,1);//左轮正转
    digitalWrite(right_Zheng,0);//关闭右轮正转      
    digitalWrite(left_Fan,0);    //关闭反转
    digitalWrite(right_Fan,1); //右轮反转
   }
  
}BLYNK_WRITE(V3)
{
  int pinValue3 = param.asInt();
  if (pinValue3 == 1)
  { Serial.println("Left");
    //左转，右轮正转左轮反转
    digitalWrite(left_Zheng,0);      //关闭左轮正转      
    digitalWrite(right_Zheng,1);   //右轮正转
    digitalWrite(left_Fan,1);      //左轮反转    
    digitalWrite(right_Fan,0);       //关闭右轮反转
   }
  
}BLYNK_WRITE(V4)
{
  int pinValue4 = param.asInt();
  if (pinValue4 == 1)
  {Serial.println("back");
    //后退 
    digitalWrite(left_Zheng,0);      
   digitalWrite(right_Zheng,0);
   digitalWrite(left_Fan,1);    //关闭反转
    digitalWrite(right_Fan,1);
   }
  
}
BLYNK_WRITE(V5)
{
  int pinValue5 = param.asInt();
  if (pinValue5 == 1)
  {//直走
     Serial.println("stop");
    digitalWrite(left_Zheng,0);      
    digitalWrite(right_Zheng,0);
    digitalWrite(left_Fan,0);    //关闭反转
    digitalWrite(right_Fan,0);
   }
  
}
void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(32,OUTPUT);
pinMode(33,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

}

void loop()
{
  Blynk.run();
}


//再arduino uno下编译通过，其它没试
//*****引脚定义**********8
#define left_Zheng 3   
#define left_Fan 5
#define right_Fan 6
#define right_Zheng 10
void setup() {
  // put your setup code here, to run once:
//输入输出模式定义

pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() 
{
   while(Serial.available())
     {
       char c=Serial.read();
         switch (c) {
    case 1:
       Serial.println("Forward");
    analogWrite(left_Zheng,200);      
    analogWrite(right_Zheng,200);
    analogWrite(left_Fan,0);    //关闭反转
    analogWrite(right_Fan,0);
      break;
    case 2:
       Serial.println("Right");
    //右转，左轮正转右轮反转
    analogWrite(left_Zheng,200);//左轮正转
    analogWrite(right_Zheng,0);//关闭右轮正转      
    analogWrite(left_Fan,0);    //关闭反转
    analogWrite(right_Fan,200); //右轮反转
      break;
      case 3:
      Serial.println("Left");
    //左转，右轮正转左轮反转
    analogWrite(left_Zheng,0);      //关闭左轮正转      
    analogWrite(right_Zheng,200);   //右轮正转
    analogWrite(left_Fan,200);      //左轮反转    
    analogWrite(right_Fan,0);       //关闭右轮反转
    case 4:
       Serial.println("Forward");
    //直走 
    analogWrite(left_Zheng,0);      
    analogWrite(right_Zheng,0);
    analogWrite(left_Fan,200);    //关闭反转
    analogWrite(right_Fan,200);
    default:
     analogWrite(left_Zheng,0);      
    analogWrite(right_Zheng,0);
    analogWrite(left_Fan,0);    //关闭反转
    analogWrite(right_Fan,0);
      break;
  }
          }
     }




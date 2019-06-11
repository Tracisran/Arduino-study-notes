 long Password[]= {5325425,123,123,2134,12344,4532};

int flag=0,RX_Flag=0;//串口标志
char Code[14]; //用于存放读到串口数据
long Num=0;//解码数据
int serpin=7;//舵机引脚定义
int Door=0;

void Read_ID(void)
{
    int i=0;
    char temp;
    for(i=0;(Serial.available()>0);i++)
    {
      temp=Serial.read();
      Serial.print(temp);
      delay(2);
      Serial.println(i);
      if(temp==0X02)  //接收起始位
        {
         flag=1;i=0;RX_Flag=0;//
        }
      if(flag==1)//检测到起始位,开始接收数据
      {
        if(temp==0X03)//检测到结束码,
        {
         flag=0;  //标志清零
         if(i==13) RX_Flag=1;//第13位为结束码，收到数据，标志置1
         else RX_Flag=0;
       break;
        }
         Code[i]=temp;
      } 
    }       
     flag=0;//标志清零
}


void setup() {
  pinMode(13,OUTPUT);
  pinMode(serpin,OUTPUT);
  Serial.begin(9600);
  Serial.println("This is a test for access control system");
  delay(100);
  for(int i;i<sizeof(Password)/sizeof(Password[0]);i++)
  {Serial.println(Password[i]);} // put your setup code here, to run once:

}

void loop() {
    int i;
  long temp=0,time=0;
  RX_Flag=0;
  while(1)
  {
   Read_ID();
  if(RX_Flag==1)
  {
    for(i=5;i<11;i++)//数据解码，6位字符转为十六进制数,对应十进制卡号
    {
      Num<<=4;
        if(Code[i]>64)  Num+=((Code[i])-55);
        else Num+=((Code[i])-48);
        Serial.println(Num);
    }    
    Serial.println(Num);    
  
     if((Num==Password[0])||(Num==Password[1]))//识别成功
  {
      digitalWrite(13,HIGH);
      delay(5);
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
      delay(100);
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
     Serial.println("开启");
      delay(2000);
      while(analogRead(Door)>400);
      delay(1000);
      Serial.println("关闭");
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
      delay(5);
      
   }
  else  
   {
      digitalWrite(13,LOW);
      digitalWrite(7,HIGH);
      delay(500);
      digitalWrite(7,LOW);
    }
  
    while(Serial.read()>0);//清除缓存区
    RX_Flag=0;//标志位清零
    Num=0;//数据清零
   }   
  }  // put your main code here, to run repeatedly:

}

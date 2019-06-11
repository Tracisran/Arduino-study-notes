void setup() {
 pinMode(32,OUTPUT);
pinMode(35,OUTPUT);
pinMode(34,OUTPUT);
pinMode(33,OUTPUT); // put your setup code here, to run once:

}

void loop() {
  digitalWrite(32,HIGH);      
    digitalWrite(35,LOW);
    digitalWrite(33,HIGH);    //关闭反转
    digitalWrite(34,LOW);// put your main code here, to run repeatedly:

}

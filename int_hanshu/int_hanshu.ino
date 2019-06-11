void setup() {
 Serial.begin(9600);

}

void loop() {
 
  int a = 100;
  Serial.println(f(a)); 

}


int f(int c)
{
  int a = 1 + c;
  return a;
  
  }

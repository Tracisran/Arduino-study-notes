

// the setup function runs once when you press reset or power the board
void setup() {
Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
 
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
f(10);
while(1);
}


void f(int a)
{
  while(1)

  {
    digitalWrite(4,HIGH);
    delay(a);
    digitalWrite(4,LOW);
    delay(a);
    }
  }

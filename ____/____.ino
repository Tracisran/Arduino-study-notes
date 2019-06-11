

// the setup function runs once when you press reset or power the board
void setup() {
Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13,HIGH);
  digitalWrite(13,LOW);
f(10);
while(1);
}


void f(int a)
{
  while(1)

  {
    digitalWrite(13,HIGH);
    delay(a);
    digitalWrite(13,LOW);
    delay(a);
    }
  }

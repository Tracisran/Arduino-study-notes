int a[]={1,2,3,4,5,6};int n;
void setup() {
  Serial.begin(9600); 

}

void loop() {
  
 Serial.println(a[n]) ;
 n=n+1;
 delay(1000);
 if(n=5)
 {n=0;}

}

 

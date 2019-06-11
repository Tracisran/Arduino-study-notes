#include <WiFi.h>
const char* ssid = "RAN";//修改为你的WiFi名字
const char* password = "123456123";//修改为你的WiFi密码
WiFiServer server(80);//80号端口为浏览器默认使用的端口
void setup()
 {
  Serial.begin(115200);
  delay(10);
  pinMode(5, OUTPUT);//定义四个引脚作为点击的控制引脚
  pinMode(4, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(15, LOW);
  digitalWrite(13, LOW);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void loop() {
  // Check if a client has connected
  WiFiClient client = .available();
  if (!client) {
    return;
  }
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  // Match the request
  if (request.indexOf("/forward") > 0)  {
    digitalWrite(5, HIGH);
     digitalWrite(15, HIGH);
     digitalWrite(4, LOW);
     digitalWrite(13, LOW);
  }
  
   if (request.indexOf("/back") > 0)  {
    digitalWrite(4, HIGH);
    digitalWrite(13, HIGH);
     digitalWrite(15, LOW);
     digitalWrite(5, LOW);
  }
 
    if (request.indexOf("/left") >0)  {
   digitalWrite(4, HIGH);
     digitalWrite(15, HIGH);
     digitalWrite(5, LOW);
     digitalWrite(13, LOW);
  }
  
   if (request.indexOf("/right") > 0)  {
   digitalWrite(13, HIGH);
     digitalWrite(15, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, HIGH);
  }
   if (request.indexOf("/stop") > 0)  {
   digitalWrite(13, LOW);
     digitalWrite(15, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, LOW);
  }//5个按钮对应的功能
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
  client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
 client.println("</head>");
  client.println("<body bgcolor = \"#f7e6ec\">");
 
  client.println("<hr/><hr>");
  client.println("<h4><center> SOCCER BALL </center></h4>");
  client.println("<hr/><hr>");
  client.println("<br><br>");
  client.println("<br><br>");
  client.println("<center>");
  
  client.println("<a href=\"/forward\"\"><button>forward</button></a>");
   
  client.println("</center>");   
  client.println("<br><br>");
   client.println("<center>");
  
  client.println("<a href=\"/back\"\"><button>back </button></a>");
  
client.println("</center>");
  client.println("<br><br>");
    client.println("<center>");
   
  client.println("<a href=\"/left\"\"><button>left</button></a>");
  
client.println("</center>");
  client.println("<br><br>");
   client.println("<center>");
   
  client.println("<a href=\"/right\"\"><button>right </button></a>");
  
client.println("</center>");
  client.println("<br><br>");
   client.println("<center>");
   
  client.println("<a href=\"/stop\"\"><button>stop </button></a>");
  
client.println("</center>");
  client.println("<br><br>");
  
  client.println("</html>"); //输出HTML页面，作为上位机
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
} 

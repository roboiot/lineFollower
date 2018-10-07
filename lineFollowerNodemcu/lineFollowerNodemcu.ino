#include <ESP8266WiFi.h>

#define delayTime 1000
const char* ssid = "robotics";
const char* password = "987654321";

WiFiServer server(80);//Service Port


 void setup() {
  // put your setup code here, to run once)
  
 // Connect to WiFi network
  Serial.println();
Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
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
  WiFiClient client = server.available();
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
 
//Set ledPin according to the request
  //digitalWrite(ledPin, value);
   
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("Click <button type=\"button\" onclick=\"location.href='http://192.168.43.74/MOVE=FORWARD'\">FORWARD</button><br/><br/><br/>");
  client.println("<br><br>");
  client.println("<h1>Click <a href=\"/MOVE=FORWARD\">FORWARD</a> </h1> <br>");
  client.println("<h1>Click <a href=\"/MOVE=STOP\">STOP</a>  </h1> <br>");
  client.println("<h1>Click <a href=\"/MOVE=BACKWARD\">BACKWARD</a>  </h1> <br>");
  client.println("<h1>Click <a href=\"/MOVE=LEFT\">LEFT</a>  </h1> <br>");
  client.println("<h1>Click <a href=\"/MOVE=RIGHT\">RIGHT</a>  </h1> <br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client refreshed/disconnected");
  Serial.println("");
 }

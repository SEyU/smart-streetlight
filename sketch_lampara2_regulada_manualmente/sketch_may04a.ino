#include <ESP8266WiFi.h>

#include <ESP8266WiFi.h>

const char* ssid = "Aquaris M5";
const char* password = "calimero79";
IPAddress ip(192,168,1,222);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
int ledPin = 13; //Lo conectamos a D7
WiFiServer server(80);

void setup() {
 Serial.begin(115200);
 delay(10);

 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);

 WiFi.begin(ssid, password);
 WiFi.config(ip, gateway, subnet);
 
 server.begin(); 
}

void loop() {

 WiFiClient client = server.available();
 if (!client) {
   return;
 }


 Serial.println("new client");
 while(!client.available()){
   delay(1);
 }

 String request = client.readStringUntil('\r');
 client.flush();


 int value = digitalRead(ledPin);
 if (request.indexOf("/LED=ON") != -1)  {
   digitalWrite(ledPin, HIGH);
   value = HIGH;
 }
 if (request.indexOf("/LED=OFF") != -1)  {
   digitalWrite(ledPin, LOW);
   value = LOW;
 }


 client.println("HTTP/1.1 200 OK");
 client.println("Content-Type: text/html");
 client.println("");
 client.println("<!DOCTYPE HTML>");
 client.println("<html>");

 client.print("El led esta ahora: ");

 if(value == HIGH) {
   client.print("Encendido");
   client.println("<br><br>");
   client.println("<a href=\"/LED=OFF\"\"><button>Apagar</button></a><br />");  
 } else {
   client.print("Apagado");
client.println("<br><br>");
 client.println("<a href=\"/LED=ON\"\"><button>Encender</button></a>");
 } 
 client.println("</html>");

 delay(1);

}


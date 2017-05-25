

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

 
// Connect to the WiFi
//const char* ssid = "MIWIFI_2G_SxcJ";                           //!!!!!!!!!!!!!!!!!!!!!
//const char* password = "4dd4q3km7mbb";   
const char* ssid = "Aquaris M5";                           //!!!!!!!!!!!!!!!!!!!!!
const char* password = "calimero79"; //!!!!!!!!!!!!!!!!!!!!!
const char* mqtt_server = "broker.hivemq.com";                 //!!!!!!!!!!!!!!!!!!!!!
 
WiFiClient espClient;
PubSubClient client(espClient);
 
int ledPin = 15; 
 
void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived [");
 Serial.print(topic);
 Serial.print("] ");
 String recibido="";
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
 
  recibido += (String) receivedChar;

 }
 Serial.println(recibido);
 analogWrite(ledPin, recibido.toInt()); 
  /*if (receivedChar == '1')
  digitalWrite(ledPin, HIGH);
  if (receivedChar == '0')
   digitalWrite(ledPin, LOW);*/
  
  Serial.println();
}
 
 
void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {
 Serial.print("Attempting MQTT connection...");
 // Attempt to connect
 if (client.connect("ESP8266 Client")) {
  Serial.println("connected");
  // ... and subscribe to topic
  client.subscribe("intensidadtarik");
 } else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
  }
 }
}
 
void setup()
{
 Serial.begin(9600);
 
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback);
 
 
 analogWrite(ledPin, 1024);
 delay(5000);
 analogWrite(ledPin, 0);
}
 
void loop()
{
 if (!client.connected()) {
  reconnect();
 }
 client.loop();
}

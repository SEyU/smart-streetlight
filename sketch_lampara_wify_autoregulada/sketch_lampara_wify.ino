
#include "ESP8266WiFi.h"
#include "PubSubClient.h"
//4dd4q3km7mbb

// WiFi parameters to be configured
const char* ssid = "Aquaris M5";
const char* password = "calimero79";
int lightPin = 0;// A0 pin analógico de entrada para el LDR
int led= 15; //D1 donde se conecta el led

int valorLDR=0; //Valor que recibiremos de los sensores
int sum=0;// Contador de prueba 



//**************Mqtt Setup******************************
// Aquí lo que hacemos es definir el servidor al que se conecta para enviar los mensajes

const char* mqtt_server = "broker.hivemq.com";

//****Definimos nuestro cliente****//
WiFiClient espClient;
PubSubClient client(espClient);



// Conexión con la red wifi
void setup_wifi()
{

 WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());
  delay(1000);
}


// Conectando con el servicio mqtt
void reconnect(){



while(!client.connected()){
  Serial.print("Esperando para conectar..");

  //Creamos un usuario aleatorio cada vez que nos reconectamos, por si el servicio nos echa fuera 
  //por estar conectados muchas veces con el mismo usuario
  
  String clientId= "3b8bb6b902604c8e8cff2625ebea40f5";  
  clientId =String(random(0xffff), HEX)+ clientId;
  

//Nos conectamos con el método connect. Si nos devuelve TRUE imprimimos conectar
if(client.connect(clientId.c_str())){
  Serial.println("connected");
}

//Si el método connect nos devuelve FALSE, intentamos reconectar en unos 5 segundos
else{
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds, usuario"+clientId);
  delay(5000);
  
}

  
}




  
}  //end reconnect




void setup(){
  Serial.begin(115200);
  setup_wifi();
 
    client.setServer(mqtt_server, 1883);  //Nos conectamos al servidor
  
  
}






void loop()
{

//Si no está conectado, lo reconectamos
  if(!client.connected()){
    
   reconnect();
  }


//Valor que nos devuelve el sensor
valorLDR= analogRead(lightPin); //valor analógico , mas alto 1024


// Definimos una variable de luminosidad
int reading = 1024- valorLDR; //1023*4 //Variable que almacena el valor del LDR

//Establecemos la potencia del led en funcion de la variable de luminosidad
analogWrite(led ,reading);
int valorbombilla= analogRead(led);
delay(2000);


float voltagesensor= valorLDR*(33.3/1023);

/****PUBLICANDO*****/
// Enviamos los string a nuestro servicio de mqtt

//client.publish("TarikLum", String(reading).c_str());
client.publish("contador", String(sum).c_str());
client.publish("luminosidad", String(reading).c_str());
client.publish("voltagesensor", String(voltagesensor).c_str());


// Añadimos una unidad a nuestra
sum++;
//intensidad(reading);
delay(2000);



}

//Método intensidad
void intensidad(int x){
  analogWrite(led, x);
}


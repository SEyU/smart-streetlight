<h1>Proyecto Farola Inteligente</h1>
<h2>I)	Descripción del Proyecto Básico</h2>
Para la parte de IoT(Internet of Things) se pretende fabricar una “Farola Inteligente” que pueda ser monitorizada y regulada a través de Internet. 
Dicha farola dispondrá como característica básica el incrementar la intensidad de luz en función del nivel de oscuridad presente en el ambiente, es decir, 
cuanta menos luz haya en la calle, más luz desprenderá el foco de la farola. 
Los datos de intensidad se reflejarán de forma automática a través de un cuadro de mandos en forma de gráficas. A su vez, estos datos quedarán reflejados en un histórico.


<h2>II)	Descripción del Proyecto Avanzado</h2>


Nuestra Farola podrá hacer lo siguiente:
-	Medir la luz ambiental
-	Regular la intensidad del foco en función de la luz ambiental
-	Enviar dichos datos a internet
Por otro lado, nuestra aplicación de monitorización podrá:
-	Mostrar Gráficas de Niveles de Luminosidad e histórico.
-	Mostrar Voltajes de Sensores.
-	Enviar emails a los Técnicos de Mantenimiento en respuesta de eventos inesperados del sistema (sensores rotos, luminosidad extrema)
-	Avisar de dichos eventos por medio de mensajes de voz automatizados
-	Regular la luminosidad manualmente de una Segunda Farola para comprobar que la comunicación llegaría a ser bidireccional

<h2>III)	Descripción del Proyecto Avanzado</h2>
Por un lado, se necesitan los siguientes materiales para el desarrollo:
-	2 x NodeMCUv3 (Uno para una farola regulada automáticamente y otro para una regulada manualmente).
-	2 x LED.
-	1 x KOhmn.
-	2 x Cables MiniUsb-USB.
-	1 x Sensor de Luminosidad.
-	1 x ProtoBoard y varios cables macho para conectar pines.
Y por otro, utilizaremos los siguientes Software:
-	Fritzing para el diseño y presentación de nuestro circuito
-	ARDUINO Versión: v1.8.2 para programar nuestros NodeMCU
-	Node-RED Versión: v0.16.2 para diseñar e implementar nuestro Dashboard de 
-	HiveMqTT para la comunicación de nuestros dispositivos físicos y nuestra aplicación de monitorización


<h2>IV)	Diseño del Circuito en Fritzing</h2>
Los esquemas en Fritzing serían los siguientes:
![Farola Regulada Manualmente](IMG/imagen1.jpg)
En este primer circuito solo vamos a necesitar un LED que controlaremos 
manualmente desde nuestra aplicación a través de internet.
![Farola Regulada Automaticamente](IMG/imagen2.jpg)
En este segundo circuito añadiremos un sensor de luminosidad junto 
con una resistencia para que se regule la intensidad de la luz del LED automáticamente. Los valores de ese sensor conjunto algunos 
datos más serán monitorizados a través de nuestra aplicación remota.

<h2>VI)	Servicio Mqtt</h2>

En este punto lo que haremos será explicar a grandes rasgos cual va 
a ser el servidor que nos va a brindar el intercambio de mensaje Mqtt 
para que nuestros dispositivos y programas puedan transmitirse información 
entre sí.
En este proyecto hemos usado el servidor público que se nos oferta en la página,


![HiveMqTT](IMG/imagen3.jpg)
![HiveMqTT](IMG/imagen4.jpg)


<h2>VI)	Programación en Arduino</h2>
Vamos a mostrar ejemplos de los métodos y trozos de código más relevantes 
que han sido usados para programar los dos circuitos de las dos farolas 
respectivamente.
Para más detalle, en este misma entrega del proyecto se adjuntan los códigos de Arduino utilizados.
<h2>Inclusión de Librerías y Declaración de variables Globales</h2>


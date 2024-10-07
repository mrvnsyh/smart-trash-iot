#include "PubSubClient.h"
#include "ESP8266WiFi.h"
#include <Servo.h>

const char* ssid = "";
const char* password = "";

#define TOKEN "ahoAc7Flc9TFMG0JYfpB" //Ambil dari device thingsboard di atas
char ThingsboardHost[] = "thingsboard.cloud";

int inputPin = 16; // choose input pin (for PIR) 
const int trigPin = 12;
const int echoPin = 13;
// defines variables
long duration;
int distance;

Servo servo;

WiFiClient wifiClient;
PubSubClient client(wifiClient);
int status = WL_IDLE_STATUS;
unsigned long lastSend;

void setup() {
  // put your setup code here, to run once:
  lastSend = 0;
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(inputPin, INPUT);  // pir sensor
  servo.attach(2); //D4
  servo.write(0);
  delay(2000);
  

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("connected to");
  Serial.println(ssid);
  client.setServer( ThingsboardHost, 1883 );

}

void loop() {
  // put your main code here, to run repeatedly:
  if ( !client.connected() ) 
    { 
      reconnect();
    }

  if ( millis() - lastSend > 5000 ) { // kirim data suhu tiap 1 detik
    getAndSendCountingData();
    lastSend = millis();
  }

}


void getAndSendCountingData(){
    long state = digitalRead(inputPin);
  // Clears the trigPin  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034/2;
  // Calculating the distance
   if (distance < 15){  
     Serial.println("Full Capacity!");
     delay(1000);

  }
  if (state == LOW){
      servo.write(180);

      delay(8000);  
      
      servo.write(0);

      delay(1000); 
  }
  delay(200);
      Serial.println("Collecting distance data.");
      Serial.print("Distance: ");
      Serial.print(distance);
      // Prepare a JSON payload string
      String payload = "{";
      payload += "\"Capacity\":";
      payload += String(distance); 
      payload += "}";

      char attributes[1000];
      payload.toCharArray( attributes, 1000 );
      client.publish( "v1/devices/me/telemetry",attributes);
      Serial.println( attributes );
    }

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("Connected to AP");
    }
    Serial.print("Connecting to ThingsBoard node ...");
    // Attempt to connect (clientId, username, password)
    if ( client.connect("Esp8266", TOKEN, NULL) ) {
      Serial.println( "[DONE]" );
    } else {
      Serial.print( "[FAILED] [ rc = " );
      Serial.println( " : retrying in 5 seconds]" );
      delay( 500 );
    }
  }
}
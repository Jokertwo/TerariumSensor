#include <Arduino.h>
#include "constants.h"
#include "display.h"
#include "dhtSensor.h"
#include "soilMoisture.h"
#include <WiFi.h>
#include <PubSubClient.h>



WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup_wifi();

void setup()
{

  // komunikace přes sériovou linku rychlostí 9600 baud
  Serial.begin(9600);
  Serial.print("Connecting to ");
  delay(1000);

  // display inicialization
  initDisplay();
  
  // dht inicialization
  initDHT();
  
  // soil moisture inicialization
  initSoilMoisture();

  // setup wifi connection
  setup_wifi();

  // setup mqtt
  client.setServer(MQTT_SERVER, MQTT_SERVER_PORT);

  char clientID[] = "Muje super id";
  client.connect(clientID);

  Serial.println(client.state());
}

void loop()
{
  float dhtValue[2] = {0,0};
  readDHT(dhtValue);

  char airTempeture[5]; 
  dtostrf(dhtValue[0], 2, 2, airTempeture); // Leave room for too large numbers!
  client.publish(MQTT_AIR_TEMPETURE,airTempeture);

  char airHumidity[5];
  dtostrf(dhtValue[1], 2, 2, airHumidity); // Leave room for too large numbers!
  client.publish(MQTT_AIR_HUMIDITY,airHumidity);


  delay(2000);
}

void setup_wifi()
{
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(SSID_WIFI);
  WiFi.begin(SSID_WIFI, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}



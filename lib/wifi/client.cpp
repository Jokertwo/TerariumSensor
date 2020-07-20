#include "client.h"
#include <WiFi.h>
#include "dhtSensor.h"
#include <PubSubClient.h>

const char *ssid = "Madagaskar";
const char *password = "bylijsmevdjktdo2017";
const char* mqtt_server = "192.168.1.9";

const char *host = "192.168.1.9";
int value = 0;

const char *TOPIC_WR = "home/test/write";
const char *TOPIC_READ = "home/test/read";

WiFiClient espClient;
PubSubClient client(espClient);

void initWifi()
{

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    delay(1000);

    WiFi.begin(ssid, password);

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


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(),"","")) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      client.publish(TOPIC_WR, "hello world");
      // ... and resubscribe
      client.subscribe(TOPIC_READ);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte *payload, unsigned int length) {
    Serial.println("-------new message from broker-----");
    Serial.print("channel:");
    Serial.println(topic);
    Serial.print("data:");  
    Serial.write(payload, length);
    Serial.println();
}

void publishSerialData(char *serialData){
  if (!client.connected()) {
    reconnect();
  }
  client.publish(TOPIC_WR, serialData);
}


void runWifi()
{
client.loop();
    WiFiClient client;
    const int httpPort = 8080;
    if (!client.connect(host, httpPort))
    {
        Serial.println("connection failed");
        return;
    }

    float dht[2] = {0, 0};
    readDHT(dht);

    String url = "/demo/";
    url += dht[0];

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0)
    {
        if (millis() - timeout > 5000)
        {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server and print them to Serial
    while (client.available())
    {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }

    Serial.println();
    Serial.println("closing connection");
}

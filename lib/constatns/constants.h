#ifndef FUNCTIONS_H_CONSTANTS
#define FUNCTIONS_H_CONSTANTS

#include <Arduino.h>

#define OLED_RST 16
#define OLED_ADDRESS 0x3C
#define OLED_SDA 4
#define OLED_SCL 15
#define OLED_RST 16
#define PIN_DHT 17
#define CONFIG_NSS 18
#define CONFIG_RST 14
#define CONFIG_DIO0 26
#define CONFIG_MOSI 27
#define CONFIG_MISO 19
#define CONFIG_CLK 5

/* dht sensor*/
#define typDHT DHT22 // DHT 11

/* soil maisture sensor*/
#define SOIL_MOISTURE_POWER 23
#define SOIL_MOISTURE_DATA 36

/** this two lines are for wifi setting*/
#define SSID_WIFI "SET_SSID_WIFI"
#define WIFI_PASSWORD "SET_WIFI_PASSWORD"

/* setting for MQTT server */
#define MQTT_SERVER "192.168.1.5"
#define MQTT_SERVER_PORT 1883

#define MQTT_SOIL_HUMIDITY "/terrarium/humidity/soil"
#define MQTT_AIR_HUMIDITY "/terrarium/humidity/air"
#define MQTT_AIR_TEMPETURE "/terrarium/tempeture/air"

#endif
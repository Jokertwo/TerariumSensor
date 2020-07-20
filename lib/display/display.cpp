#include "display.h"
#include <Wire.h>
#include "SSD1306Wire.h"
#include <DHT.h>

SSD1306Wire display(OLED_ADDRESS, OLED_SDA, OLED_SCL);

static String dhtStatus = "";
static String logStatus = "";
static String soilMoisture = "";
static boolean inicialized = false;
static void repaintDisplay();

void initDisplay()
{
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, HIGH);
  delay(100);
  digitalWrite(OLED_RST, LOW);
  delay(100);
  digitalWrite(OLED_RST, HIGH);
  display.init();
  display.flipScreenVertically();
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  updateStatus("Init display done");
  display.display();
  inicialized = true;
}

void updateSoil(int humidity)
{
  String buf = "Soil ";
  buf += humidity;
  Serial.println(buf);
  soilMoisture = buf;
  repaintDisplay();
}

void updateDHT(float temp, float humidity)
{
  String buf;
  buf += String(temp, 1);
  buf += "°C, ";
  buf += String(humidity, 0);
  buf += "%H";
  dhtStatus = buf;
  String log = "Updating dht display status: ";
  log += dhtStatus;
  Serial.println(log);
  repaintDisplay();
}

void updateStatus(String status)
{
  logStatus = status;
  String log = "Updating log display status: ";
  log += status;
  Serial.println(log);
  repaintDisplay();
}

void repaintDisplay()
{
  if (inicialized)
  {
    display.clear();
    display.drawString(20, 0, soilMoisture);
    display.drawString(display.getWidth() / 2, display.getHeight() / 2 - 8, dhtStatus);
    display.drawString(display.getWidth() / 2, display.getHeight() - 16, logStatus);
    display.display();
  }
}
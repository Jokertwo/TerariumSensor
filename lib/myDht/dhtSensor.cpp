#include "dhtSensor.h"
#include <DHT.h>
#include "display.h"

DHT myDHT(PIN_DHT, typDHT);

void initDHT()
{
    myDHT.begin();
    updateStatus("DHT started");
    Serial.println("DHT started");
}

void readDHT(float *values)
{

    float tep = myDHT.readTemperature();
    float hum = myDHT.readHumidity();
    if (isnan(tep) || isnan(hum))
    {
        // při chybném čtení vypiš hlášku
        updateStatus("DHT error");
        Serial.println("Chyba při čtení z DHT senzoru!");
    }
    else
    {
        values[0] = tep;
        values[1] = hum;

        Serial.print("Teplota: ");
        Serial.print(tep);
        Serial.print(" stupnu Celsia, ");
        Serial.print("vlhkost: ");
        Serial.print(hum);
        Serial.println("  %");
        updateDHT(tep, hum);
        updateStatus("");
    }

}
#include "soilMoisture.h"
#include "display.h"

void initSoilMoisture()
{

    Serial.println("Inicialization of soil moisture");

    pinMode(SOIL_MOISTURE_DATA, INPUT);
    String message = "Pin ";
    message += SOIL_MOISTURE_DATA;
    message += "was set as data for soil moisture";
    Serial.println(message);

    pinMode(SOIL_MOISTURE_POWER, OUTPUT);
    message = "Pin ";
    message += SOIL_MOISTURE_POWER;
    message += "was set as power for soil moisture";
    Serial.println(message);

    // turn off the pin
    digitalWrite(SOIL_MOISTURE_POWER, LOW);
}


void readSoilMoisture(int* value){

    // turn on power
    digitalWrite(SOIL_MOISTURE_POWER, HIGH);
    delay(100);

    // read data
    int analog = analogRead(SOIL_MOISTURE_DATA);
    Serial.println(analog);
    // update display value
    updateSoil(analog);

    // store return value
    value = &analog;

    // turn off senzor
    digitalWrite(SOIL_MOISTURE_POWER, LOW);
}

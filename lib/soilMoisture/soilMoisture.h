

#ifndef FUNCTIONS_H_SOIL_MOISTURE_SENSOR
#define FUNCTIONS_H_SOIL_MOISTURE_SENSOR

#include "constants.h"


/**
 * Inicialization of soil moisture senzor
 */
void initSoilMoisture();

/**
 * Read value from senzor
 */ 
void readSoilMoisture(int* value);

#endif
#ifndef FUNCTIONS_H_DHT_11_SENSOR
#define FUNCTIONS_H_DHT_11_SENSOR

#include "constants.h"

/**
 * Inicialization of dht sensor
 */ 
void initDHT();

/**
 * Read values from dht senzor
 * float[0] = tempeture
 * float[1] = humidity
 */ 
void readDHT(float * values);

#endif
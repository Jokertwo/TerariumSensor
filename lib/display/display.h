#ifndef FUNCTIONS_H_DISPLAY
#define FUNCTIONS_H_DISPLAY

#include "constants.h"

/**
 * Inicialization of display
 */ 
void initDisplay();

/**
 * Update information soil moisture
 */ 
void updateSoil(int humidity);

/**
 * Update values dht values on display
 */
void updateDHT(float temp, float humidity);


/**
 * Update log status of device
 */ 
void updateStatus(String status);


#endif
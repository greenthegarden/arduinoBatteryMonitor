#pragma once

#include "Arduino.h" 

/*
 *************** Configure Arduino MKRZero ***************
 */

const float MKRZERO_REF_VOLTAGE = 3.3;
const unsigned int MKRZERO_ADC_RESOLUTION = 12; // 12-bit resolution
const unsigned int MKRZERO_ADC_RANGE = 4096;
#if SD_IN_MKRZERO
  const unsigned int chipSelect = SDCARD_SS_PIN;
#else
  const unsigned int chipSelect = 4;
#endif

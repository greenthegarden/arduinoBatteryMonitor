#pragma once

#include "Arduino.h"

// Based on https://how2electronics.com/interfacing-0-25v-dc-voltage-sensor-with-arduino/
// voltage sensor configuration

class VoltageDivider
{
  public:
    VoltageDivider(uint8_t analogPin, float r1, float r2, float refV = 3.3, uint16_t maxADC = 1023);

    float voltageMeasurement();

    float adcValueToVoltage(float adc_value);

    float voltageDividerInput(float adc_value);

  private:
    uint8_t _pin;
    float _r1;   // resistor value in Ohms
    float _r2;   // resistor value in Ohms
    float _refV;
    uint16_t _maxADC;
};

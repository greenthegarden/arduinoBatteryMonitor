#pragma once

#include "Arduino.h"

// Based on https://forum.arduino.cc/t/hall-sensor-wcs1700-current-module-dc-70a-non-invasive-method/469669/15
// WCS1700 Hall Effect Current sensor

// I = (readA0 - 508) * 78 / 512

class HallEffectSensor
{
  public:
    HallEffectSensor(
      uint8_t analogPin,
      uint16_t zeroCurrentInput,
      uint16_t sensorMaxCurrent,
      uint16_t maxADC = 1023
    );

    float currentMeasurement();

    float adcValueToVoltage(float adc_value);

    float hallEffectSensorInput(float adc_value);

  private:
    uint8_t _pin;
    uint16_t _zeroCurrentInput; // analogue reading with no current
    uint16_t _sensorMaxCurrent; // sensor 
    uint16_t _maxADC;
};

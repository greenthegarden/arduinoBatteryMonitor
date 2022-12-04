#include "HallEffectSensor.h"

/// @brief 
/// @param analogPin
/// @param r1 
/// @param r2 
/// @param refV 
/// @param maxADC 
HallEffectSensor::HallEffectSensor(
  uint8_t analogPin,
  uint16_t zeroCurrentInput,
  uint16_t sensorMaxCurrent,
  uint16_t maxADC
)
{
  _pin = analogPin;
  _zeroCurrentInput = zeroCurrentInput;
  _sensorMaxCurrent = sensorMaxCurrent;
  _maxADC = maxADC;
}

float HallEffectSensor::currentMeasurement()
{
  // Read the analog input`
  float adc_value = analogRead(_pin);

  float current = (adc_value - 508) * (78 / 512.0);

  return current;
}

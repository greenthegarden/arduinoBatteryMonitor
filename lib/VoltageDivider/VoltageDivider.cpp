#include "VoltageDivider.h"

/// @brief 
/// @param analogPin
/// @param r1 
/// @param r2 
/// @param refV 
/// @param maxADC 
VoltageDivider::VoltageDivider(uint8_t analogPin, float r1, float r2, float refV, uint16_t maxADC)
{
  _pin = analogPin;
  _r1 = r1;
  _r2 = r2;
  _refV = refV;
  _maxADC = maxADC;
}

float VoltageDivider::voltageMeasurement()
{
  // Read the analog input`
  float adc_value = analogRead(_pin);

  // Determine voltage at ADC input
  float adc_voltage = adcValueToVoltage(adc_value);

  float in_voltage = voltageDividerInput(adc_voltage);

  return in_voltage;
}

float VoltageDivider::adcValueToVoltage(float adc_value)
{
  // Determine voltage at ADC input
  float adc_voltage = (adc_value * _refV) / float(_maxADC);

  return adc_voltage;
}

float VoltageDivider::voltageDividerInput(float adc_voltage)
{
  // Calculate voltage at divider input
  float in_voltage = adc_voltage / (_r2 / (_r1 + _r2));

  return in_voltage;
}

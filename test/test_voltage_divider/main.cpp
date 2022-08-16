#include <unity.h>
#include "ArduinoMKRZero.h"
#include "VoltageDivider.h"

void setUp(void)
{
  // set stuff up here
}

void tearDown(void)
{
  // clean stuff up here
}

VoltageDivider voltageDivider3v10bit(A0, 30000.0, 7500.0, MKRZERO_REF_VOLTAGE, MKRZERO_ADC_RANGE);

void test_voltageDivider3v10bit_adc_voltage(void)
{
  TEST_ASSERT_EQUAL((MKRZERO_REF_VOLTAGE / 2.0), voltageDivider3v10bit.adcValueToVoltage(MKRZERO_ADC_RANGE / 2));
}

void setup()
{
  UNITY_BEGIN(); // IMPORTANT LINE!


  RUN_TEST(test_voltageDivider3v10bit_adc_voltage);

  UNITY_END(); // stop unit testing
}

void loop()
{
}

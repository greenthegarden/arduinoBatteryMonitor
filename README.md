# Arduino Solar Power Monitor

Uses the following sensors to monitor voltage and current for a 12 volt solar panel.

Voltage: [Binary DC Voltage Sensor Module](https://www.ebay.com.au/itm/224447035297)
Current: [Hall Current Sensor Module WCS1700](https://www.ebay.com.au/itm/313976907322)

## Voltage Reading

The voltage sensor is a voltage divider with R1 = 30k and R2 = 7.5k. A [voltage divider library](lib/VoltageDivider/) has been created which provides a contructor to define the resistor values, in the form

```cpp
VoltageDivider(uint8_t analogPin, float r1, float r2, float refV = 3.3, uint16_t maxADC = 1023);
```

In addition, a method is provided to get the source voltage based on the measured voltage, as

```cpp
float voltageMeasurement();
```

## Current Reading

The current sensor uses a Winson WCS Hall Effect Current Sensor to measure current. Information about the sensor measurement can be found from in an [Arduino forum post](https://forum.arduino.cc/t/hall-sensor-wcs1700-current-module-dc-70a-non-invasive-method/469669/15).

Logic to calculate reading is `I = (readA0 - 508) * 78 / 512`.

```cpp

```

## Additional references


JSON Test Project

To determine the JSONObject size use the [ArduinoJson Assistant](https://arduinojson.org/v6/assistant/#/step1). The ArduinoJson assistant also computes the number of bytes required for the duplication of strings. It shows this value in the “String” row in step 3.


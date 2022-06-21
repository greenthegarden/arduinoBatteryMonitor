#include <ArduinoJson.h>
#include <SPI.h>
#include <SD.h>

#define SERIAL_SPEED 115200 // serial baud rate

#if SD_IN_MKRZERO
const unsigned int chipSelect = SDCARD_SS_PIN;
#else
const unsigned int chipSelect = 4;
#endif

void read_config()
{
  // Open file
  File file = SD.open("config.txt");

  if (file)
  {
    DeserializationError error = deserializeJson(doc, file);

    if (error)
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
  }
  else
  {
    Serial.println("Failed to open file");
  }
}

void setup()
{
  Serial.begin(115200); // open the serial port at 115200 bps:

  Serial.print("\nInitializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect))
  {
    Serial.println("Card initialization failed, or not present");
    // don't do anything more:
    while (1)
      ;
  }
  Serial.println("Card is present and initialized.");

  read_config();
}

void loop()
{}

#include <Ethernet.h>
#include <ArduinoHA.h>

const unsigned int RELAY_1_PIN = 1;
const unsigned int RELAY_2_PIN = 2;

#define BROKER_ADDR IPAddress(192, 168, 1, 186)

byte mac[] = {0x00, 0x10, 0xFA, 0x6E, 0x38, 0x4A};
unsigned long lastReadAt = millis();
unsigned long lastAvailabilityToggleAt = millis();
bool lastInputState = false;

EthernetClient client;
HADevice device(mac, sizeof(mac));
HAMqtt mqtt(client, device);

// Define relays as switches
// Set initial state of off (false)
HASwitch relay_1("relay_1", false);
HASwitch relay_2("relay_2", false);
// HASensor sensor("current");

void onBeforeSwitchStateChanged(bool state, HASwitch *s)
{
  // this callback will be called before publishing new state to HA
  // in some cases there may be delay before onStateChanged is called due to network latency
}

void relay1onSwitchStateChanged(bool state, HASwitch *s)
{
  digitalWrite(RELAY_1_PIN, (state ? HIGH : LOW));
}

void relay2onSwitchStateChanged(bool state, HASwitch *s)
{
  digitalWrite(RELAY_2_PIN, (state ? HIGH : LOW));
}

void setup()
{
  pinMode(RELAY_1_PIN, OUTPUT);
  // relay_1_lastInputState = digitalRead(RELAY_1_PIN);
  pinMode(RELAY_2_PIN, OUTPUT);
  // relay_2_lastInputState = digitalRead(RELAY_2_PIN);

  // you don't need to verify return status
  Ethernet.begin(mac);

  // set device's details (optional)
  device.setName("Battery Manager");
  device.setModel("MKR ZERO");
  device.setManufacturer("Arduino");
  device.setSoftwareVersion("0.1.0");

  // This method enables availability for all device types registered on the device.
  // For example, if you have 5 sensors on the same device, you can enable
  // shared availability and change availability state of all sensors using
  // single method call "device.setAvailability(false|true)"
  device.enableSharedAvailability();

  // Optionally, you can enable MQTT LWT feature. If device will lose connection
  // to the broker, all device types related to it will be marked as offline in
  // the Home Assistant Panel.
  device.enableLastWill();

  // Configuratin for sensor INA3221
  // sensor.setName("12 volt system"); // optional

  // Configure relay_1 specifics
  relay_1.setName("Relay 1");
  relay_1.setRetain(true);
  // handle switch state
  relay_1.onBeforeStateChanged(onBeforeSwitchStateChanged);
  relay_1.onStateChanged(relay1onSwitchStateChanged);

  // Configure relay_2 specifics
  relay_2.setName("Relay 2");
  relay_2.setRetain(true);
  // handle switch state
  relay_2.onBeforeStateChanged(onBeforeSwitchStateChanged);
  relay_2.onStateChanged(relay2onSwitchStateChanged);

  mqtt.begin(BROKER_ADDR);

  lastReadAt = millis();
  lastAvailabilityToggleAt = millis();
}

void loop()
{
  Ethernet.maintain();
  mqtt.loop();

  if ((millis() - lastAvailabilityToggleAt) > 5000)
  {
    device.setAvailability(!device.isOnline());
    lastAvailabilityToggleAt = millis();
  }
}

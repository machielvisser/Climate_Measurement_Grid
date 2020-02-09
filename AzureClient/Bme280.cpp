#include "Bme280.h"

bool Bme280::initialise()
{
  if (initialised)
  {
    return true;
  }

  int result = bme280.begin(BME280_ADDRESS_ALTERNATE);
  if (!result) {
    Serial.println("Check wiring");
  }
  delay(100);
  bme280.setSampling(
        Adafruit_BME280::MODE_FORCED,
        Adafruit_BME280::SAMPLING_X1,
        Adafruit_BME280::SAMPLING_X1,
        Adafruit_BME280::SAMPLING_X1,
        Adafruit_BME280::FILTER_OFF);
        
  delay(100);
  initialised = result;

  return initialised;
}

bool Bme280::measure()
{
  int result = initialise();
  if (!result)
    return false;

  bme280.takeForcedMeasurement();
  
  temperature = bme280.readTemperature();  
  pressure = bme280.readPressure() / 100.0;
  humidity = bme280.readHumidity();

  return true;
}

#include "Bme280.h"

void Bme280::initialise()
{
  if (initialised)
  {
    return;
  }

  int result = bme280.begin(BME280_ADDRESS_ALTERNATE);
  if (!result) {
    Serial.println("Check wiring" );
  }
  delay(100);
  bme280.setSampling(
        Adafruit_BME280::MODE_FORCED,
        Adafruit_BME280::SAMPLING_X1,
        Adafruit_BME280::SAMPLING_X1,
        Adafruit_BME280::SAMPLING_X1,
        Adafruit_BME280::FILTER_OFF);
        
  delay(100);
  initialised = true;
}

void Bme280::measure()
{
  initialise();

  bme280.takeForcedMeasurement();
  
  temperature = bme280.readTemperature();  
  pressure = bme280.readPressure() / 100.0;
  humidity = bme280.readHumidity();
}

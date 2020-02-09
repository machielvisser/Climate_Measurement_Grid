#ifndef Bme280_h
#define Bme280_h

#include "Sensor.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class Bme280 : public Sensor
{
public:
  Bme280() {};
  bool measure();
  bool initialise();

protected:
  Adafruit_BME280 bme280; // I2C
};

#endif

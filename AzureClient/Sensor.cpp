#include "Sensor.h"

void Sensor::measure()
{
  temperature = 20 + random(-1, 1);
  humidity = 50 + random(-20, 40);
  pressure = 1000 + random(-100, 100);
}

char *Sensor::toJSON()
{
  StaticJsonDocument<JSON_OBJECT_SIZE(16)> root;

  root["deviceId"] = deviceId;
  root["timestamp"] = getISODateTime();
  root["temperature"] = temperature;
  root["humidity"] = humidity;
  root["pressure"] = pressure;
  root["light"] = light;
  root["geo"] = geo;

  //root["WiFi"] = telemetry->WiFiConnectAttempts;
#ifdef ARDUINO_ARCH_ESP8266
  //root["Mem"] = ESP.getFreeHeap();
#endif

  root["messageId"] = ++msgId;

  serializeJson(root, buffer);

  return buffer;
}

char *Sensor::getISODateTime()
{
  snprintf(isoTime, sizeof(isoTime), "%4d-%02d-%02dT%02d:%02d:%02dZ", year(), month(), day(), hour(), minute(), second());
  return isoTime;
}

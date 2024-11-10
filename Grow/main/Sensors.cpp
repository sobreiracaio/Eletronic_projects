#include "Arduino.h"
/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

void Sensors::setTempHum(DHT11 dht11)
{
  dht11.readTemperatureHumidity(this->_temperature, this->_humidity);
  Serial.print("Temperature: ");
  Serial.println(this->_temperature);
  Serial.print("Humidity: ");
  Serial.println(this->_humidity);
  
}

void Sensors::setSoilMoisture(int pin)
{
  this->_soil = map(analogRead(pin),270, 1000, 0, 99);
  Serial.print("Soil Moisture: ");
  Serial.println(this->_soil);
}

int Sensors::getHumid(void)
{
  return (this->_humidity);
}

int Sensors::getTemp(void)
{
  return (this->_temperature);
}

int Sensors::getSoil(void)
{
  return (this->_soil);
}
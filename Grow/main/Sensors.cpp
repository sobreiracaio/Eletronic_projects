#include "Arduino.h"
/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Sensors::Sensors(void)
{
  this->targetTemp = 25;
  this->targetHumid = 50;
  this->targetSoil = 99;
}

void Sensors::setTempHum(DHT11 dht11)
{
  dht11.readTemperatureHumidity(this->_temperature, this->_humidity);
}

void Sensors::setSoilMoisture(int pin)
{
  
  this->_soil = map(analogRead(pin),0, 4095, 0, 99);
  if (this->_soil < 0)
    this->_soil = 0;
}

int Sensors::getHumid(void)
{
  if(this->_humidity == 100)
    this->_humidity = 99;
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








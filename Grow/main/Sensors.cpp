#include "Arduino.h"
/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Sensors::Sensors(void)
{
  this->_targetTemp = 25;
  this->_targetHumid = 50;
  this->_targetSoil = 99;
}

void Sensors::setTempHum(DHT11 dht11)
{
  dht11.readTemperatureHumidity(this->_temperature, this->_humidity);
}

void Sensors::setSoilMoisture(int pin)
{
  this->_soil = map(analogRead(pin),9, 1018, 0, 99);
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

int Sensors::getTargetTemp(void)
{
  return (this->_targetTemp);
}
int Sensors::getTargetHumid(void)
{
  return (this->_targetHumid);
}
int Sensors::getTargetSoil(void)
{
  return (this->_targetSoil);
}

void Sensors::setTargetTemp(int temp)
{
  if(temp <= 50)
    this->_targetTemp = temp;
  else
    return;
  
}
void Sensors::setTargetHumid(int humid)
{
  if(humid <= 99)
    this->_targetHumid = humid;
  else
    return;
}
void Sensors::setTargetSoil(int soil)
{
  if(soil <= 99)
    this->_targetSoil = soil;
  else
    return;

}






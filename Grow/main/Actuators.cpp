/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Actuators::Actuators(int pin)
{
  this->dayTime = 12;
  this->nightTime = 12;
  this->pumpFreq = 1;
  this->pumpPeriod = DAY;
  this->pumpTime = 5;
  this->soilMoisture = 80;
  this->_pin = pin;
}


/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Pump::Pump(int pin, Sensor *sensor)
{
  this->pumpFreq = 1;
  this->pumpPeriod = DAY;
  this->pumpTime = 5;
  this->soilMoisture = sensor->targetSoil;
  this->_pin = pin;
}

void Pump::setPumpSwitch(int startFlag, Sensor *sensor)
{
    this->soilMoisture = sensor->targetSoil;

    if(startFlag == 1)
    {
          
    }
}
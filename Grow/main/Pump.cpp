/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Pump::Pump(int pin, Sensors *sensor)
{
  this->pumpFreq = 150;
  this->pumpPeriod = DAY;
  this->pumpTime = 5;
  this->pumpLastState = 0;
  this->pumpLastWateringState = 0;
  this->_pin = pin;
}

void Pump::setPumpSwitch(int startFlag, Sensors *sensor)
{
    
  unsigned long intervalDay = ONE_DAY / this->pumpFreq;
  unsigned long intervalWeek = ONE_WEEK / this->pumpFreq;
    

  if(startFlag == 1)
    {
      if(this->pumpPeriod == DAY)
      {
        if ((millis() - this->pumpLastState) < intervalDay)
          digitalWrite(PUMP, LOW);
        else
          digitalWrite(PUMP, HIGH);
        if ((millis() - this->pumpLastState) >= intervalDay + (this->pumpTime * ONE_SECOND)) 
          this->pumpLastState = millis();
      }

      else if(this->pumpPeriod == WEEK)
      {
        if ((millis() - this->pumpLastState) < intervalWeek)
          digitalWrite(PUMP, LOW);
        else
          digitalWrite(PUMP, HIGH);
        if ((millis() - this->pumpLastState) >= intervalWeek + (this->pumpTime * ONE_SECOND)) 
          this->pumpLastState = millis();
      }
      
      if(sensor->getSoil() < sensor->targetSoil && (millis() - this->pumpLastState) > (ONE_HOUR / 12))
        digitalWrite(PUMP, HIGH);
      else
        digitalWrite(PUMP, LOW);
      if ((millis() - this->pumpLastState) >= (ONE_HOUR / 12) + (this->pumpTime * ONE_SECOND))
      {
        digitalWrite(PUMP, LOW); 
        this->pumpLastState = millis();
      } 
  }
  else
    digitalWrite(PUMP, LOW);
}
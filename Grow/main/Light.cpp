/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Light::Light(int pin)
{
  this->dayTime = 1;
  this->nightTime = 12;
  this->lightLastState = 0;
  this->_pin = pin;
}

void Light::setLightSwitch(int startFlag)
{
  if(this->dayTime > 24)
    this->dayTime = 0;
  if(this->dayTime < 0)
    this->dayTime = 24;

  if(this->nightTime > 24)
    this->nightTime = 0;
  if(this->nightTime < 0)
    this->nightTime = 24;


  if(startFlag == 1)
  {
    if ((millis() - this->lightLastState) < (this->dayTime * ONE_HOUR))
      digitalWrite(LIGHT, HIGH);
    else
      digitalWrite(LIGHT, LOW);
    if ((millis() - this->lightLastState) >= ((this->dayTime + this->nightTime) * ONE_HOUR))
      this->lightLastState = millis();
  }
  else 
    digitalWrite(LIGHT, LOW);
}
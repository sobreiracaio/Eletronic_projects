/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

void FanAndHumidifier::setSwitch(int startFlag, Sensors *sensor)
{
  if(startFlag == 1)
  {
    if(sensor->getTemp() > sensor->targetTemp + 1)
      digitalWrite(FAN, HIGH);
    else
      digitalWrite(FAN, LOW);

    if(sensor->getHumid() > sensor->targetHumid + 1)
      digitalWrite(HUMIDIFIER, HIGH);
    else
      digitalWrite(HUMIDIFIER, LOW);
  }
  else
  {
    digitalWrite(FAN, LOW);
    digitalWrite(HUMIDIFIER, LOW);
  }
}







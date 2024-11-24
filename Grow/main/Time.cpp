/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Time::Time(Light *light)
{
    this->decreasingHourDay = light->dayTime;
    this->decreasingHourNight = light->nightTime;
    this->minutes = 0;
    this->debounceMin = 0;
}

void Time::getTime(int startFlag, Light *light)
{
    if(startFlag == 1)
    {
        if (this->decreasingHourDay > 0)
        {
            if(millis() - this->debounceMin > ONE_MINUTE)
            {
                this->minutes--;
                if(this->minutes < 0)
                {
                this->decreasingHourDay -= 1;
                this->minutes = 59;
                }
                this->debounceMin = millis();
            }
        }
        else if (this->decreasingHourNight > 0)
        {
            if(millis() - this->debounceMin > ONE_MINUTE)
            {
                this->minutes--;
                if(this->minutes < 0)
                {
                this->decreasingHourNight -= 1;
                this->minutes = 59;
                }
                this->debounceMin = millis();
            }
        }
        if (this->decreasingHourDay < 0 && this->decreasingHourNight < 0)
        {
            this->decreasingHourDay = light->dayTime;
            this->decreasingHourNight = light->nightTime;
            this->minutes = 0;
        }
    }
    else 
    {
            this->decreasingHourDay = light->dayTime;
            this->decreasingHourNight = light->nightTime;
            this->minutes = 0;
    }
}
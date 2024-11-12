/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Controls::Controls(int buttonPin)
{
      this->_buttonPin = buttonPin;
      this->_debounceDelay = 50;
      this->_buttonState = LOW;
      this->_lastButtonState = LOW;
      this->_lastDebounceTime = 0;
}


void Controls::buttons(int *value)
{
      int reading = digitalRead(this->_buttonPin);
                  Serial.print("Value reading: ");
                  Serial.println(digitalRead(reading));
                  Serial.print("Value buttonState: ");
                  Serial.println(this->_buttonState);
      
                  

      // if (reading != this->_lastButtonState) 
      // {
      // if ((millis() - this->_lastDebounceTime) > this->_debounceDelay) 
      // {    
      //             this->_lastDebounceTime = millis();

      // }
      //     if (reading != this->_buttonState) 
      //     {
      //         this->_buttonState = reading;
      //         if (this->_buttonState == HIGH)
      //         {
      //             (*value)++;
      //         }
      //     }
      // this->_lastButtonState = reading;
      // }

      }
      
      
















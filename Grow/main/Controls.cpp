#include "Adafruit_ST77xx.h"
/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

Controls::Controls(int buttonPin)
{
      this->_buttonPin = buttonPin;
      this->_debounceDelay = 100;
      this->_buttonState = HIGH;
      this->_lastButtonState = HIGH;
      this->_lastDebounceTime = 0;
}

void Controls::buttons(int *value, int operation, int newValue, Adafruit_ST7735 tft, int screenState)
{
      int reading = digitalRead(this->_buttonPin);

      if ((!reading && this->_lastButtonState) && (millis() - this->_lastDebounceTime > this->_debounceDelay)) 
      {
        if(operation == INCREMENT)
            (*value) += newValue;
        else if(operation == DECREMENT)
            (*value) -= newValue;
        else if(operation == ASSIGMENT)
            *value = newValue;
        if (screenState == CLEAR_SCR)
            tft.fillScreen(ST77XX_BLACK);
        this->_lastDebounceTime = millis();
      }

      this->_buttonState = this->_lastButtonState;
}        



      
















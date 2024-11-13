/* *************************************************************************************












*************************************************************************************** */

#ifndef GROW_HPP
# define GROW_HPP

//Sensor Pins
# define DHT_PIN A1
# define SOIL_PIN A0

//Display Pins
# define SCL_PIN 13
# define SDA_PIN 11
# define RES_PIN 8
# define DC_PIN 9
# define CS_PIN 10

//Controls Pins
# define BT0 A0
# define BT1 A5
# define BT2 A4
# define BT3 A3

//Output Pins
# define PUMP 2
# define LIGHT 3
# define FAN 4
# define HUMIDIFIER 5

//Operations

# define INCREMENT 0
# define DECREMENT 1
# define ASSIGMENT 3
# define CLEAR_SCR 0
# define KEEP_SCR  1

# include <DHT11.h>
# include <Adafruit_GFX.h>    
# include <Adafruit_ST7735.h> 
#include "Adafruit_ST77xx.h"
# include <SPI.h>




class Sensors{

  public:
      Sensors();
      void setTempHum(DHT11 dht11);
      void setSoilMoisture(int pin);
      int getTemp(void);
      int getHumid(void);
      int getSoil(void);
      int getTargetTemp(void);
      int getTargetHumid(void);
      int getTargetSoil(void);

      void setTargetTemp(int temp);
      void setTargetHumid(int humid);
      void setTargetSoil(int soil);
  private:
       int _temperature;
       int _humidity;
       int _soil;
       int _targetTemp;
       int _targetHumid;
       int _targetSoil;
  
};


class Controls{

  private:
    int _buttonPin;
    int _buttonState;
    int _lastButtonState;
    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;

  public:
    Controls(int buttonPin);
    void buttons(int *value, int operation, int newValue, Adafruit_ST7735 tft, int screenState);

};

class Actuators{

  public:
    void setPumpSwitch(int state);
    void setLightSwitch(int state);
    void setFanSwitch(int state);
    void setHumidSwitch(int state);
};

class Display{

  public:
      void initDisplay(Adafruit_ST7735 tft);
      void displayAdjusts(Adafruit_ST7735 tft, Sensors *sensor);
      void displayAdjusts2(Adafruit_ST7735 tft);
      void displayCalibration(Adafruit_ST7735 tft);
      void mainDisplay(Adafruit_ST7735 tft, Sensors *sensor, int* value, Controls *buttons);


};



#endif
/* *************************************************************************************












*************************************************************************************** */

#ifndef GROW_HPP
# define GROW_HPP

//Sensor Pins
# define DHT_PIN 32
# define SOIL_PIN 13

//Display Pins
# define SCL_PIN 18
# define SDA_PIN 21
# define RES_PIN 4
# define DC_PIN 17
# define CS_PIN 5

//Controls Pins
# define BT0 25
# define BT1 26
# define BT2 27
# define BT3 14

//Output Pins
# define PUMP 33
# define LIGHT 15
# define FAN 2
# define HUMIDIFIER 16

//Operations

# define INCREMENT 0
# define DECREMENT 1
# define ASSIGMENT 3
# define DRAW_LINE  1
# define CLEAR_SCR 0
# define KEEP_SCR  1

//LIGHT

# define DAY 0
# define NIGHT 1

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
     
       int targetTemp;
       int targetHumid;
       int targetSoil;
  private:
       int _temperature;
       int _humidity;
       int _soil;
  
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
    void buttons(int *value, int operation, int newValue, Adafruit_ST7735 tft, int screenState, int hasLine, 
                     void (*drawLine)(Adafruit_ST7735, int, int, int, int),int x, int y, int x1, int color);
    

};

class Light{

  public:
    void setDayTime(int hour, int min, int dayOrNight);
  
  private:
    int _hour;
    int _min;
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
      void displayAdjusts2(Adafruit_ST7735 tft, Sensors *sensor);
      void lightMenu(Adafruit_ST7735 tft);
      void pumpMenu(Adafruit_ST7735 tft);
      void displayCalibration(Adafruit_ST7735 tft, Sensors *sensor);
      void mainDisplay(Adafruit_ST7735 tft, Sensors *sensor);
      void buttonsMenu(Adafruit_ST7735 tft, String options[4]);
      static void displayLine(Adafruit_ST7735 tft, int x, int y, int x1, int color);
  private:

};



#endif
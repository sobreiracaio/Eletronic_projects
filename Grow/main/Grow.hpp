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
# define RES_PIN 5
# define DC_PIN 7
# define CS_PIN 6

//Controls Pins
# define BT1 A5
# define BT2 A2
# define ROT_SW A6
# define ROT_DT A4
# define ROT_CLK 10

//Output Pins
# define PUMP 2
# define LIGHT 3
# define FAN 4

# include <DHT11.h>
# include <Adafruit_GFX.h>    
# include <Adafruit_ST7735.h> 
# include <SPI.h>



class Sensors{

  public:
      void setTempHum(DHT11 dht11);
      void setSoilMoisture(int pin);
      int getTemp(void);
      int getHumid(void);
      int getSoil(void);
  private:
       int _temperature;
       int _humidity;
       int _soil;
  
};

class Display{

  public:
      void initDisplay(Adafruit_ST7735 tft);
      void displayTopInfo(Adafruit_ST7735 tft);
      void displayMidScreen(Adafruit_ST7735 tft);
      void mainDisplay(Adafruit_ST7735 tft, Sensors *sensor);


};

class Controls{

  public:

};

class Actuators{

  public:
    void setPumpSwitch(bool state);
    void setLightSwitch(bool state);
    void setFanSwitch(bool state);
};




#endif
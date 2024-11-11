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
# define ROT_SW A3
# define ROT_DT A4
# define ROT_CLK A6

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

class Display{

  public:
      void initDisplay(Adafruit_ST7735 tft);
      void displayAdjusts(Adafruit_ST7735 tft, Sensors *sensor);
      void displayAdjusts2(Adafruit_ST7735 tft);
      void displayCalibration(Adafruit_ST7735 tft);
      void mainDisplay(Adafruit_ST7735 tft, Sensors *sensor);


};

class Controls{


  public:
  int buttonOne(int value);

};

class Actuators{

  public:
    void setPumpSwitch(int state);
    void setLightSwitch(int state);
    void setFanSwitch(int state);
};




#endif
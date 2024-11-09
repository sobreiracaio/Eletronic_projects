/* *************************************************************************************












*************************************************************************************** */

#ifndef GROW_HPP
# define GROW_HPP

//Sensor Pins
# define DHT_PIN 4
# define SOIL_PIN A0

//Display Pins
# define SCL_PIN 14
# define SDA_PIN 13
# define RES_PIN 2
# define DC_PIN 0
# define CS_PIN 15

//Controls Pins
# define BT1 16
# define BT2 5
# define ROT_SW 9
# define ROT_DT 8
# define ROT_CLK 10

//Output Pins
# define PUMP 11
# define LIGHT 7
# define FAN 6

# include <DHT11.h>



class Sensors{

  public:
      void getTempHum(DHT11 dht11);
      unsigned int   getSoilMoisture();
  private:
       int _temperature;
       int _humidity;
       int   _soil;
  
};

class Display{

  public:
      Display();

};

class Controls{

  public:

};
















#endif
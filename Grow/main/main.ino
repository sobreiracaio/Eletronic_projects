/* *************************************************************************************












*************************************************************************************** */
#include "Grow.hpp"

DHT11 dht11(DHT_PIN);
Adafruit_ST7735 tft = Adafruit_ST7735(CS_PIN, DC_PIN, SDA_PIN, SCL_PIN, RES_PIN);

int menu = 3;





Controls Button[4] = {Controls(BT0), Controls(BT1), Controls(BT2), Controls(BT3)};
Sensors Sensor;
Display Screen;


void setup() {

  
  
  //Serial.begin(115200);

  pinMode(DHT_PIN, INPUT);
   pinMode(SOIL_PIN, INPUT);

   pinMode(PUMP, OUTPUT);
   pinMode(LIGHT, OUTPUT);
   pinMode(FAN, OUTPUT);

  pinMode(BT1, INPUT_PULLUP);
  pinMode(BT2, INPUT_PULLUP);
  pinMode(BT3, INPUT_PULLUP);
  pinMode(BT0, INPUT_PULLUP);
  
  Screen.initDisplay(tft);



  

}
  

void loop() 
{
  

  switch (menu) 
  {
      case 0:
        Screen.mainDisplay(tft, &Sensor, &menu, Button);
        break;
      case 1:
        Screen.displayAdjusts(tft, &Sensor, &menu, Button);
        break;
      case 2:
        Screen.displayAdjusts2(tft, &Sensor, &menu, Button);
        break;
      case 3:
        Screen.displayCalibration(tft, &Sensor, &menu, Button);
        break;
      default:
        menu = 0;
  }
  //Serial.println(menu);
  
  Sensor.setTempHum(dht11);
  Sensor.setSoilMoisture(SOIL_PIN);
  
  
  

}

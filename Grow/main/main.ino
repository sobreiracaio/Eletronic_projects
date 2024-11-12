/* *************************************************************************************












*************************************************************************************** */
#include "Grow.hpp"

DHT11 dht11(DHT_PIN);
Adafruit_ST7735 tft = Adafruit_ST7735(CS_PIN, DC_PIN, SDA_PIN, SCL_PIN, RES_PIN);

int value = 0;





Controls Button1(BT1);
Sensors Sensor;
Display Screen;


void setup() {

  
  
  Serial.begin(9600);

  pinMode(DHT_PIN, INPUT);
   pinMode(SOIL_PIN, INPUT);

   pinMode(PUMP, OUTPUT);
   pinMode(LIGHT, OUTPUT);
   pinMode(FAN, OUTPUT);

  pinMode(BT1, INPUT_PULLUP);
  pinMode(BT2, INPUT_PULLUP);
  pinMode(BT3, INPUT_PULLUP);
  pinMode(BT4, INPUT_PULLUP);
  
  Screen.initDisplay(tft);



  

}
  

void loop() 
{
  Button1.buttons(&value);
  
  

  
 




  Sensor.setTempHum(dht11);
  Sensor.setSoilMoisture(SOIL_PIN);
  //Screen.displayAdjusts(tft, &Sensor);
  Screen.mainDisplay(tft, &Sensor);
  
  

}

/* *************************************************************************************












*************************************************************************************** */
#include "Grow.hpp"

DHT11 dht11(DHT_PIN);
Adafruit_ST7735 tft = Adafruit_ST7735(CS_PIN, DC_PIN, SDA_PIN, SCL_PIN, RES_PIN);

int menu = 0;

Sensors Sensor;
Display Screen;
Controls Button[4] = {Controls(BT0), Controls(BT1), Controls(BT2), Controls(BT3)};

String options[4] = {"Set", "   ", "   ", " <"};
String options1[4] = {"Set", "Adj", "Cal", "  "};
String options2[4]= {" > ", " - ", " + ", " v"};
String options3[4]= {"   ", " - ", " + ", " v"};


void setup() 
{
  
  Serial.begin(115200);
  Screen.initDisplay(tft);

  pinMode(DHT_PIN, INPUT);
  pinMode(SOIL_PIN, INPUT);
  pinMode(PUMP, OUTPUT);
  digitalWrite(PUMP, LOW);

  pinMode(LIGHT, OUTPUT);
  digitalWrite(LIGHT, LOW);
  
  pinMode(FAN, OUTPUT);
  digitalWrite(FAN, LOW);
  
  pinMode(HUMIDIFIER, OUTPUT);
  digitalWrite(HUMIDIFIER, LOW);
   

  pinMode(BT1, INPUT_PULLUP);
  pinMode(BT2, INPUT_PULLUP);
  pinMode(BT3, INPUT_PULLUP);
  pinMode(BT0, INPUT_PULLUP);
}
  

void loop() 
{
  switch (menu) 
  {
      case 0:
        Screen.mainDisplay(tft, &Sensor);
        Screen.buttonsMenu(tft, options1);
        Button[0].buttons(&menu, ASSIGMENT, 1, tft, CLEAR_SCR);
        Button[1].buttons(&menu, ASSIGMENT, 5, tft, CLEAR_SCR);
        Button[2].buttons(&menu, ASSIGMENT, 6, tft, CLEAR_SCR);
        break;
      case 1:
        Screen.displayAdjusts(tft, &Sensor);
        Screen.buttonsMenu(tft, options);
        Button[0].buttons(&menu, ASSIGMENT, 2, tft, KEEP_SCR);
        Button[3].buttons(&menu, ASSIGMENT, 0, tft, CLEAR_SCR);
        break;

      case 2:
        Screen.displayAdjusts(tft, &Sensor);
        Screen.buttonsMenu(tft, options2);
        Button[0].buttons(&menu, ASSIGMENT, 3, tft, KEEP_SCR);
        Button[1].buttons(&Sensor.targetTemp, DECREMENT, 1, tft, KEEP_SCR);
        Button[2].buttons(&Sensor.targetTemp, INCREMENT, 1, tft, KEEP_SCR);
        Screen.displayLine(tft, 13, 75, 39, 75);
        Button[3].buttons(&menu, ASSIGMENT, 0, tft, CLEAR_SCR);
        break;

      case 3:
        Screen.displayAdjusts(tft, &Sensor);
        Screen.buttonsMenu(tft, options2);
        Button[0].buttons(&menu, ASSIGMENT, 4, tft, KEEP_SCR);
        Button[1].buttons(&Sensor.targetHumid, DECREMENT, 1, tft, KEEP_SCR);
        Button[2].buttons(&Sensor.targetHumid, INCREMENT, 1, tft, KEEP_SCR);
        Screen.displayLine(tft, 63, 75, 89, 75);
        Button[3].buttons(&menu, ASSIGMENT, 0, tft, CLEAR_SCR);
        break;

      case 4:
        Screen.displayAdjusts(tft, &Sensor);
        Screen.buttonsMenu(tft, options3);
        Button[1].buttons(&Sensor.targetSoil, DECREMENT, 5, tft, KEEP_SCR);
        Button[2].buttons(&Sensor.targetSoil, INCREMENT, 5, tft, KEEP_SCR);
        Screen.displayLine(tft, 113, 75, 139, 75);
        Button[3].buttons(&menu, ASSIGMENT, 0, tft, CLEAR_SCR);
        break;

      case 5:
        Screen.displayAdjusts2(tft, &Sensor);
        Screen.buttonsMenu(tft, options);
        Button[3].buttons(&menu, ASSIGMENT, 0, tft, CLEAR_SCR);
        break;
      case 6:
        Screen.displayCalibration(tft, &Sensor);
        Screen.buttonsMenu(tft, options);
        Button[3].buttons(&menu, ASSIGMENT, 0, tft, CLEAR_SCR);
        break;
      default:
        menu = 0;
  }
  
  Serial.println(menu);
  Sensor.setTempHum(dht11);
  Sensor.setSoilMoisture(SOIL_PIN);
  
  
  

}

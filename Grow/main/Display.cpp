#include "Adafruit_ST7735.h"
#include "soc/touch_sensor_periph.h"
#include "Adafruit_ST77xx.h"

/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

void Display::initDisplay(Adafruit_ST7735 tft)
{
  tft.initR(INITR_MINI160x80);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);
  tft.invertDisplay(true);
  tft.setCursor(0, 0);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("LOGO");
  //delay(2000);
  tft.fillScreen(ST77XX_BLACK);
 
}

void Display::displayAdjusts(Adafruit_ST7735 tft, Sensors *sensor)
{
 
  int temp_temp = sensor->targetTemp;
  int temp_humid = sensor->targetHumid;
  int temp_soil = sensor->targetSoil;
   
    tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);
    tft.setCursor(63, 26);
    tft.print("Adjust");
    tft.setCursor(0, 40);
    tft.print(" TEMP(C) HUMID(%) SOIL(%)");
    tft.setTextSize(2);
    tft.setCursor(15, 57);
    tft.print(temp_temp);
    tft.setCursor(66, 57);
    tft.print(temp_humid);
    tft.setCursor(116, 57);
    tft.print(temp_soil);

    
    
}

void Display::displayAdjusts2(Adafruit_ST7735 tft, Sensors *sensor)
{
  
 
    tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);
    tft.setCursor(33, 26);
    tft.print("More Adjustments");
    tft.setCursor(10, 50);
    tft.setTextSize(2);
    tft.print("Light");
    tft.setCursor(105, 50);
    tft.print("Pump");
        
}

void Display::lightMenu(Adafruit_ST7735 tft)
{
    tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);
    tft.setCursor(65, 26);
    tft.print("Light");
}

void Display::pumpMenu(Adafruit_ST7735 tft)
{
    tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);
    tft.setCursor(68, 26);
    tft.print("Pump");
}

void Display::displayCalibration(Adafruit_ST7735 tft, Sensors *sensor)
{
    
    tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);
    tft.setCursor(47, 26);
    tft.print("Calibration");
    
    
}

void Display::mainDisplay(Adafruit_ST7735 tft, Sensors *sensor)
{
  
  tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);

  tft.setCursor(3, 26);
  tft.print((String)sensor->getTemp());
  tft.drawCircle(17, 27, 1, ST77XX_WHITE);
  tft.setCursor(26, 26);
  tft.print(sensor->getHumid());
  tft.print("%");
 
  tft.setCursor(51, 26);
  tft.print(sensor->getSoil());
  tft.print("%");


  tft.setCursor(5, 96);
  tft.print("T");
  tft.setCursor(31, 96);
  tft.print("H");
  tft.setCursor(56, 96);
  tft.print("S");
  
  tft.drawRect(2, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(3, 90, 10, ((sensor->getTemp()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(3, 41, 10, 50 -(sensor->getTemp()/2), ST77XX_BLACK);
  tft.drawChar(16, map(sensor->targetTemp, 0, 99, 89, 39), '<',ST77XX_RED, ST77XX_BLACK, 1);
  

  tft.drawRect(27, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(28, 90, 10, ((sensor->getHumid()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(28, 41, 10, 50 -(sensor->getHumid()/2), ST77XX_BLACK);
  tft.drawChar(41, map(sensor->targetHumid, 0, 99, 89, 39), '<',ST77XX_RED, ST77XX_BLACK, 1);

  tft.drawRect(52, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(53, 90, 10, ((sensor->getSoil()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(53, 41, 10, 50 -(sensor->getSoil()/2), ST77XX_BLACK);
  tft.drawChar(66, map(sensor->targetHumid, 0, 99, 89, 39), '<',ST77XX_RED, ST77XX_BLACK, 1);

  tft.drawLine(74, 0, 74, 120, 0x2108);

  tft.setCursor(79, 26);
  tft.print("LIGHT-> ");
  tft.print("OFF");

  tft.setCursor(79, 39);
  tft.print("TIME-> ");
  tft.print("00:00");
  
  

  
}

void Display::buttonsMenu(Adafruit_ST7735 tft, String options[4])
{
  tft.setTextSize(1);
  int i = 0;
  int j = 1;
  while(j < 5)
  {
    tft.drawCircle(85 + i, 85, 6, ST77XX_WHITE);
    tft.setCursor(83 + i, 82);
    tft.setTextColor(ST77XX_WHITE);
    tft.print(j);
    i += 22;
    j++;
  }
  
  i = 0;
  j = 0;
  while (j < 4)
  {
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    if(options[j][1] == 'v')
      tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
    if(options[j][1] == 'x')
      tft.setTextColor(ST77XX_YELLOW, ST77XX_BLACK);
    tft.setCursor(77 + i, 95);
    tft.print(options[j]);
    i += 22;
    j++;
  }
}
  

void Display::displayLine(Adafruit_ST7735 tft, int x, int y, int x1, int color)
{
  
  tft.setCursor(0, 0);
  tft.drawLine(x, y, x1, y, color);
  tft.drawLine(x, y + 1, x1, y + 1, color);
  

  

}

















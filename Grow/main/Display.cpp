
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
    
    tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);
    tft.setCursor(63, 26);
    tft.print("Adjust");
    tft.setCursor(0, 40);
    tft.print(" TEMP(C) HUMID(%) SOIL(%)");
    tft.setTextSize(2);
    tft.setCursor(11, 57);
    tft.print(sensor->getTargetTemp());
    tft.setCursor(66, 57);
    tft.print(sensor->getTargetHumid());
    tft.setCursor(116, 57);
    tft.print(sensor->getTargetSoil());

    tft.setTextSize(1);
    tft.setCursor(89, 85);
    tft.print("<-      ->");
    tft.setCursor(89, 95);
    tft.print("Prev  Next");
}

void Display::displayAdjusts2(Adafruit_ST7735 tft)
{

}

void Display::displayCalibration(Adafruit_ST7735 tft)
{

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
  tft.drawChar(16, map(sensor->getTargetTemp(), 0, 99, 89, 39), '<',ST77XX_RED, ST77XX_BLACK, 1);
  

  tft.drawRect(27, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(28, 90, 10, ((sensor->getHumid()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(28, 41, 10, 50 -(sensor->getHumid()/2), ST77XX_BLACK);
  tft.drawChar(41, map(sensor->getTargetHumid(), 0, 99, 89, 39), '<',ST77XX_RED, ST77XX_BLACK, 1);

  tft.drawRect(52, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(53, 90, 10, ((sensor->getSoil()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(53, 41, 10, 50 -(sensor->getSoil()/2), ST77XX_BLACK);
  tft.drawChar(66, map(sensor->getTargetSoil(), 0, 99, 89, 39), '<',ST77XX_RED, ST77XX_BLACK, 1);

  tft.setCursor(83, 26);
  tft.print("LIGHT-> ");
  tft.print("OFF");
  tft.setCursor(83, 39);
  
  tft.print("TIME-> ");
  tft.print("00:00");
  tft.setCursor(89, 85);
  tft.print("<-      ->");
  tft.setCursor(89, 95);
  tft.print("Cal    Adj");



  }
  




















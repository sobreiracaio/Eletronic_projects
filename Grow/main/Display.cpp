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
  delay(2000);
  tft.fillScreen(ST77XX_BLACK);
 
}

void Display::displayTopInfo(Adafruit_ST7735 tft)
{

}

void Display::displayMidScreen(Adafruit_ST7735 tft)
{

}

void Display::mainDisplay(Adafruit_ST7735 tft, Sensors *sensor)
{
  tft.setTextColor(ST77XX_WHITE,ST77XX_BLACK);

  tft.setCursor(3, 26);
  tft.print(sensor->getTemp());
  tft.setCursor(29, 26);
  tft.print(sensor->getHumid());
  tft.setCursor(54, 26);
  tft.print(sensor->getSoil());


  tft.setCursor(5, 96);
  tft.print("T");
  tft.setCursor(31, 96);
  tft.print("H");
  tft.setCursor(56, 96);
  tft.print("S");
  
  tft.drawRect(2, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(3, 90, 10, ((sensor->getTemp()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(3, 41, 10, 50 -(sensor->getTemp()/2), ST77XX_BLACK);

  tft.drawRect(27, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(28, 90, 10, ((sensor->getHumid()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(28, 41, 10, 50 -(sensor->getHumid()/2), ST77XX_BLACK);

  tft.drawRect(52, 40, 12, 52, ST77XX_WHITE);
  tft.fillRect(53, 90, 10, ((sensor->getSoil()/2)* (- 1)), ST77XX_GREEN);
  tft.fillRect(53, 41, 10, 50 -(sensor->getSoil()/2), ST77XX_BLACK);

  tft.setCursor(93, 26);
  tft.print("LIGHT");
  tft.setCursor(102, 38);
  tft.print("ON");
  tft.setCursor(95, 50);
  tft.print("TIME");
  tft.setCursor(93, 62);
  tft.print("00:00");

  tft.setCursor(85, 95);
  tft.print("CONF ->");



  }
  




















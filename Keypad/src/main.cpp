/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:20:29 by crocha-s          #+#    #+#             */
/*   Updated: 2025/03/09 21:24:18 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Keypad.hpp"
#include "Parser.hpp"
#include "SPIFFS.hpp"
#include "Conf.hpp"

 

const int _pinCol[5] = {COL0, COL1, COL2, COL3, COL4};
const int _pinRow[3] = {ROW0, ROW1, ROW2};

std::deque<std::string> commandTable;
std::deque<std::string> typesTable;

BleKeyboard bt("ESP32 Keyboard", "ESP32", 100);
Keypad keypad(&bt);
int button;
String rawData;

void generateMatrix()
{
    for (int i = 0; i < 5; i++) {
        pinMode(_pinCol[i], OUTPUT);
        digitalWrite(_pinCol[i], HIGH);
    }
    
    for (int i = 0; i < 3; i++) {
        pinMode(_pinRow[i],INPUT_PULLDOWN);
    }
}

int buttonNumber()
{
  int buttonNbr = -1;
  for (int col = 0; col < 5; col++)
  {
    digitalWrite(_pinCol[col], HIGH);
    for (int row = 0; row < 3; row++)
    {
      if (digitalRead(_pinRow[row]) == HIGH)
        buttonNbr = (1 + (row * 5) + col);
    }
    digitalWrite(_pinCol[col], LOW);
  }
  if(buttonNbr >= 1 && buttonNbr <= 15)
    return (buttonNbr);
  return (-1);
}


void fadeLed()
{
  static int brightness = 0;
  static int fadeAmount = 5;
  ledcWrite(0, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  
}


void setup() 
{
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
  ledcSetup(0, 5000, 8); // Configura PWM
  ledcAttachPin(STATUS_LED, 0);         // Associa o canal ao pino do LED
  Serial.begin(115200);

  rawData = getSPIFFS();
  generateMatrix();
  Parser parser(rawData);
  typesTable = parser.readFromFile(TYPE);
  commandTable = parser.readFromFile(VALUE); 
  
  keypad.setCmdMatrix(commandTable, typesTable);
  bt.begin();
  

}

void loop() 
{
  while (!bt.isConnected())
  {
     fadeLed();
  }
  if(bt.isConnected())
  ledcWrite(0, 0);
  button = buttonNumber();
    if(button != -1)
    {
      
      keypad.execute(button);
    }
    delay(50);
    Serial.print("\033c");
}


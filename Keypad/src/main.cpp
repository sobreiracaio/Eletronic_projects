
#include "Keypad.hpp"
#include "Parser.hpp"

 #include <SPIFFS.h>
 #include <FS.h>

#define COL0 4
#define COL1 16
#define COL2 17
#define COL3 18
#define COL4 19
#define ROW0 21
#define ROW1 22
#define ROW2 23



const int _pinCol[5] = {COL0, COL1, COL2, COL3, COL4};
const int _pinRow[3] = {ROW0, ROW1, ROW2};




//std::deque<std::string> commandTable[BUTTON_NBR];
std::deque<int> typesTable;



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
String getSPIFFS()
{
  File file;
  String contents;

  if (!SPIFFS.begin(true)) 
  {
    Serial.println("Erro ao montar o SPIFFS!");
    return ("ERROR");
  }
  Serial.println("SPIFFS montado com sucesso!");

  
  if (!SPIFFS.exists("/conf.txt")) 
  {
    Serial.println("Arquivo /conf.txt não encontrado no SPIFFS!");
    return ("ERROR");
  }
  Serial.println("Arquivo existe!");

  file = SPIFFS.open("/conf.txt");
  if(!file)
  {
    Serial.println("Erro ao abrir o arquivo!");
    return ("ERROR");
  }
  Serial.println("Arquivo Aberto");

  contents = file.readString();
  
  
  file.close();

  return (contents);
}
 
String rawData = getSPIFFS();

void setup() 
{
  
  Serial.begin(115200);
  generateMatrix();
  Serial.println(rawData);
  Parser parser(rawData);
  
   typesTable = parser.parseType();
  
  for (int i = 0; i < BUTTON_NBR; i++)
  {
    Serial.println(typesTable[i]);
  }
  
}
 

//Keypad keypad(commandTable, typesTable);

void loop() {

//Serial.println(buttonNumber());
  // int button = buttonNumber();
  // //keypad.execute(button);
  // delay(50);
  // Serial.print("\033c");
}


/* *************************************************************************************












*************************************************************************************** */
#include "Grow.hpp"

DHT11 dht11(DHT_PIN);

Sensors DHT;


void setup() {

  //digitalWrite(PUMP, LOW);
  Serial.begin(9600);

  //pinMode(DHT_PIN, INPUT);
   pinMode(SOIL_PIN, INPUT);

  //  pinMode(PUMP, OUTPUT);
  //  pinMode(LIGHT, OUTPUT);
  //  pinMode(FAN, OUTPUT);

  // pinMode(BT1, INPUT);
  // pinMode(BT2, INPUT);
  // pinMode(ROT_SW, INPUT);





}

void loop() {
  DHT.getTempHum(dht11);
  delay(200);

}

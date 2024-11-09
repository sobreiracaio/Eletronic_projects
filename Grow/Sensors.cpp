/* *************************************************************************************












*************************************************************************************** */

#include "Grow.hpp"

void Sensors::getTempHum(DHT11 dht11)
{
  dht11.readTemperatureHumidity(this->_temperature, this->_humidity);
  Serial.println(this->_temperature);
  Serial.println(this->_humidity);
  
}
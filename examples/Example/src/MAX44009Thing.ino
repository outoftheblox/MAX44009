#include "MAX44009.h"

MAX44009 sensor;

void setup() 
{
  Serial.begin(230400);
  Serial.println();
}

void loop()
{
  Serial.println(sensor.lux());
}

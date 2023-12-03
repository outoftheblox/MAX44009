#include "MAX44009.h"

using namespace ootb;

MAX44009 sensor(0,2);

void setup() 
{
  Serial.begin(MONITOR_SPEED);
  Serial.println();
}

void loop()
{
  Serial.println(sensor.lux());
}

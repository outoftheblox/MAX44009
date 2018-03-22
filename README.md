# MAX44009
A MAX44009 driver for measuring lux.


# Example #
```
#include "MAX44009.h"

using namespace ootb;

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
```

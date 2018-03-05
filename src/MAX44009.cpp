#include "MAX44009.h"
#include <Wire.h>
#include <math.h>

#define ADDRESS 0x4A
 
MAX44009::MAX44009()
{
  Wire.begin();
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x02);
  Wire.write(0x40);
  Wire.endTransmission();  
}


MAX44009::MAX44009(int sda, int scl)
{
  Wire.begin(sda, scl);
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x02);
  Wire.write(0x40);
  Wire.endTransmission();  
}

float MAX44009::lux() const
{
  unsigned int data[2];
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x03);
  Wire.endTransmission();
   
  // Request 2 bytes of data
  Wire.requestFrom(ADDRESS, 2);
   
  // Read 2 bytes of data luminance msb, luminance lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
   
  // Convert the data to lux
  int exponent = (data[0] & 0xF0) >> 4;
  int mantissa = ((data[0] & 0x0F) << 4) | (data[1] & 0x0F);
  return pow(2, exponent) * mantissa * 0.045;
}

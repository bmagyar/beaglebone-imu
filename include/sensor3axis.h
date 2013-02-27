#pragma once
#ifndef ACCELEROMETER_H__
#define ACCELEROMETER_H__

#include "i2c.h"

class Sensor3Axis
{
protected:
  I2C *_i2c;
  short _x, _y, _z;
  float _temp;
public:
  Sensor3Axis(){ _i2c = 0; _x = _y = _z = _temp = 0; }
  virtual void init(I2C *i2c) = 0;
  virtual void read() = 0;
  short x(){ return _x; }
  short y(){ return _y; }
  short z(){ return _z; }
  float temp(){ return _temp; }
};

#endif

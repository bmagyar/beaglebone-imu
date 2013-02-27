#pragma once
#ifndef ACCELEROMETER_H__
#define ACCELEROMETER_H__

#include "i2c.h"

class AcceleroMeter
{
protected:
  I2C *_i2c;
  short accX, accY, accZ, accTemp;
public:
  AcceleroMeter(){ _i2c = 0; }
  virtual void init(I2C *i2c) = 0;
  virtual void read() = 0;
  short x(){ return accX; }
  short y(){ return accY; }
  short z(){ return accZ; }
  short temp(){ return accTemp; }
};

#endif

#pragma once
#ifndef ITG3205_H__
#define ITG3205_H__

#define ITG3205_ADDRESS 0x68

#include "sensor3axis.h"

class ITG3205 : public Sensor3Axis
{
public:
  virtual void init(I2C *i2c);
  virtual void read();
private:
  short offX, offY, offZ;
};


#endif

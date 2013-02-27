#pragma once
#ifndef BMA180_H__
#define BMA180_H__

#define BMA180_ADDRESS 0x40

#include "sensor3axis.h"

enum BMA180_RANGE {
  PLUSMINUS_1_G     = 0,
  PLUSMINUS_1POINT5_G = 1,
  PLUSMINUS_2G    = 2,
  PLUSMINUS_3G    = 3,
  PLUSMINUS_4G    = 4,
  PLUSMINUS_8G    = 5,
  PLUSMINUS_16G     = 6
};

enum BMA180_BANDWIDTH {
  BW_10HZ   = 0,
  BW_20HZ   = 1,
  BW_40HZ   = 2,
  BW_75HZ   = 3,
  BW_150HZ  = 4,
  BW_300HZ  = 5,
  BW_600HZ  = 6,
  BW_12OOHZ   = 7,
  BW_HIGHPASS = 8,
  BW_BANDPASS = 9
};

enum BMA180_MODECONFIG {
  MODE_LOW_NOISE = 0,
  MODE_LOW_POWER = 3
};


class BMA180 : public Sensor3Axis
{
public:
   virtual void init(I2C *i2c);
  virtual void read();
private:
  short convertAcceleration(int msb_reg_addr, int lsb_reg_addr);
};

#endif

#pragma once
#ifndef GY_81__H
#define GY_81__H

#define ITG3205_ADDRESS 0x68

#include "i2c.h"
#include "bma180.h"
#include "imu.h"

/* Class for GY-81 IMU board
 * The board features a BMA180, ITG3205, HMC5883L, BMP085
 */
class GY_81 : public IMU
{
  public:
    GY_81();
    ~GY_81();

    virtual void print();
    virtual void update();
  protected:
    BMA180 acc;
//    ITG3205 gyro;
//    HMC5883L compass;
//    BMP085 baro;
        
};

#endif

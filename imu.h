#include "i2c.h"

/* Interface class for Integrated Measurement Unit boards
*/

class IMU
{
  public:
/*  
    short gx() const { return gyro_x; }
    short gy() const { return gyro_y; }
    short gz() const { return gyro_z; }
*/
    virtual void print() = 0;
    virtual void update() = 0;
  protected:
    I2C *i2c;
/*
    short g_offx, g_offy, g_offz;
    short gyro_x, gyro_y, gyro_z, gyro_temp;
*/

  protected:
/*
    virtual void initGyro(){}
    virtual void readGyro(){}

    virtual void initAcc(){}
    virtual void readAcc(){}

    virtual void initBaro(){}
    virtual void readBaro(){}

    virtual void initCompass(){}
    virtual void readCompass(){}
*/
};

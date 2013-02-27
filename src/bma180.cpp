#include "bma180.h"
#include <assert.h>

#define ACC_X_LSB   0x02
#define ACC_X_MSB   0x03
#define ACC_Y_LSB   0x04
#define ACC_Y_MSB   0x05
#define ACC_Z_LSB   0x06
#define ACC_Z_MSB   0x07
#define TEMP      0x08  //Temperature
#define RANGE     0x35  //bits 3,2,1
#define BANDWIDTH   0x20  //bits 7,6,5,4
#define MODE_CONFIG 0x30  //bits 1,0

void BMA180::init(I2C *i2c)
{
  assert(i2c != 0);
  _i2c = i2c;

  _i2c->send(BMA180_ADDRESS, 0x10, 0xB6); // reset acc
  usleep(10000); // sleep 100ms to let it reset

  _i2c->send(BMA180_ADDRESS, 0x0D, 0x10); // low pass filter, range settings
  unsigned char data = _i2c->readByte(BMA180_ADDRESS, 0x20);

  _i2c->send(BMA180_ADDRESS, 0x20, data & 0x0F); // low pass filter to 10hz
  data = _i2c->readByte(BMA180_ADDRESS, 0x35);

  _i2c->send(BMA180_ADDRESS, 0x35, (data & 0xF1) | 0x04); // range +/- 2g
}

void BMA180::read()
{
  _i2c->readMultiBytes(BMA180_ADDRESS, 0x00);
  _x = convertAcceleration(ACC_X_MSB, ACC_X_LSB);
  _y = convertAcceleration(ACC_Y_MSB, ACC_Y_LSB);
  _z = convertAcceleration(ACC_Z_MSB, ACC_Z_LSB);
}

short BMA180::convertAcceleration(int msb_reg_addr, int lsb_reg_addr)
{
  short temp = _i2c->readBuf[msb_reg_addr];
  temp = (temp<<8) | _i2c->readBuf[lsb_reg_addr];
  temp = temp>>2;
  temp = ~temp + 1;
  return temp;
}

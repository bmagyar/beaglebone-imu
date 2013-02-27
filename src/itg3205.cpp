#include "itg3205.h"
#include <assert.h>

void ITG3205::init(I2C *i2c)
{
  assert(i2c != 0);
  _i2c = i2c;

  _i2c->send(ITG3205_ADDRESS, 0x3E, 0x00);
  _i2c->send(ITG3205_ADDRESS, 0x15, 0x07);
  _i2c->send(ITG3205_ADDRESS, 0x16, 0x1E);// +/- 2000 dgrs/sec, 1KHz, 1E, 19
  _i2c->send(ITG3205_ADDRESS, 0x17, 0x00);

  //somewhat ugly averaging
  int tmpx = 0;
  int tmpy = 0;
  int tmpz = 0;

  offX = 0;
  offY = 0;
  offZ = 0;

  for (char i = 0;i<10;i++)
  {
    usleep(10000);  // sleep 10msecs
    read();
    tmpx += _x;
    tmpy += _y;
    tmpz += _z;
  }

  offX = tmpx/10;
  offY = tmpy/10;
  offZ = tmpz/10;
}

void ITG3205::read()
{
  _i2c->readMultiBytes(ITG3205_ADDRESS, 0x1B);

  // get 8 bytes
  _x = (((_i2c->readBuf[4]) << 8) | _i2c->readBuf[5]) - offX;
  _y = (((_i2c->readBuf[2]) << 8) | _i2c->readBuf[3]) - offY;
  _x = (((_i2c->readBuf[6]) << 8) | _i2c->readBuf[7]) - offZ;
  _temp = ((_i2c->readBuf[0]) << 8) | _i2c->readBuf[1]; // check datasheet for more
}

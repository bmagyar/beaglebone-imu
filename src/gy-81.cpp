#include "gy-81.h"
#include <iostream>

GY_81::GY_81()
{
  i2c = new I2C();

  acc.init(i2c);
  //  gyro.init(i2c);
  //  compass.init(i2c);
  //  baro.init(i2c);
}

GY_81::~GY_81()
{
  delete i2c;
}

void GY_81::print()
{
  std::cout << "A: [" << acc.x() << ", " << acc.y()
            << ", " << acc.z() << "]" << std::endl;
}

void GY_81::update()
{
  acc.read();
  //  gyro.read();
  //  compass.read();
  //  baro.read();
}

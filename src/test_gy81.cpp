#include <iostream>
#include "gy-81.h"
#include <sys/time.h>
#include <cstdio>

using namespace std;

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}


int main(int argc, char* argv[])
{
  GY_81 imu;
  while(true)
  {
    timestamp_t t0 = get_timestamp();

    imu.update();	
    imu.print();

    timestamp_t t1 = get_timestamp();
    std::cout << (t1 - t0) / 1000000.0L << std::endl; // time to take sample
  }
  return 0;
}

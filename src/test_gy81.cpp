#include <iostream>
#include "gy-81.h"


using namespace std;

int main(int argc, char* argv[])
{
    GY_81 imu;
    while(true)
    {
        imu.print();
        imu.update();	
        sleep(1);
    }
    return 0;
}

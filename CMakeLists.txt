cmake_minimum_required (VERSION 2.6)
project (beaglebone-imu)

INCLUDE_DIRECTORIES(.)

SET(headers imu.h
            accelerometer.h
            gy-81.h
            i2c.h
            )

add_library(i2c i2c.cpp)

add_library(sensors bma180.cpp
                    itg3205.cpp
                    hmc588l.cpp
                    bmp085.cpp
                    )
target_link_libraries(sensors i2c)

add_library(imus gy-81.cpp)
target_link_libraries(imus sensors
                           i2c)


add_executable(test_gy81 test_gy81.cpp)
target_link_libraries(test_gy81 sensors
                                imus
                                i2c)

cmake_minimum_required (VERSION 2.6)
project (beaglebone-imu)

INCLUDE_DIRECTORIES(./include)

SET(headers include/i2c.h
            include/imu.h
            include/accelerometer.h
            include/bma180.h
            include/itg3205.h
            include/hmc588l.h
            include/bmp085.h
            include/gy-81.h)

# added ${headers} here to force qt creator to list them
add_library(i2c src/i2c.cpp ${headers})

add_library(sensors src/bma180.cpp
                    src/itg3205.cpp
                    src/hmc588l.cpp
                    src/bmp085.cpp
                    )
target_link_libraries(sensors i2c)

add_library(imus src/gy-81.cpp)
target_link_libraries(imus sensors
                           i2c)


add_executable(test_gy81 src/test_gy81.cpp)
target_link_libraries(test_gy81 sensors
                                imus
                                i2c)

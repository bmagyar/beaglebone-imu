#pragma once
#ifndef I2C_H__
#define I2C_H__

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>

#define MAX_BUFFER_SIZE					16

//refactored code from https://github.com/ajaykumarkannan/Beaglebone-I2Chttps://github.com/ajaykumarkannan/Beaglebone-I2C
// original author: Ajaykumar Kannan

class I2C {
	int g_i2cFile;
public:
	I2C();
	~I2C();
	
	// Public Variables
	unsigned char I2C_WR_Buf[MAX_BUFFER_SIZE];			// Contains data you want to send
	unsigned char readBuf[MAX_BUFFER_SIZE];			// Contains data which was read
	
	// Initialize Functions
	void i2cOpen();										// Opens i2cbus 3, done at the beginning
	void i2cClose();									// Closes i2cbus 3, done at the ending
	void i2cSetAddress(int address);					// Changes device address
	
	// Sends a single byte <Data> to <DEVICE_ADDR> on the register <Reg_ADDR>
	void send(unsigned char DEVICE_ADDR, unsigned char Reg_ADDR, unsigned char Data);	

	// Reads and returns a single byte from <DEVICE_ADDR> on the register <Reg_ADDR>
	unsigned char readByte(unsigned char DEVICE_ADDR,unsigned char Reg_ADDR);
	
	// Reads multipes byte from <DEVICE_ADDR> starting from the register address <Reg_ADDR>.
	// Read the output from i2cptr->I2C_RD_Buf
	unsigned char readMultiBytes(unsigned char DEVICE_ADDR, unsigned char Reg_ADDR);
};

#endif

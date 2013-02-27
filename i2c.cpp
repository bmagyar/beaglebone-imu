#include "i2c.h"

I2C::I2C(){
	this->i2cOpen();
}

I2C::~I2C(){
	this->i2cClose();
}

// open the Linux device
void I2C::i2cOpen()
{
	g_i2cFile = open("/dev/i2c-3", O_RDWR);
	if (g_i2cFile < 0) {
		perror("i2cOpen");
		exit(1);
	}
}

// close the Linux device
void I2C::i2cClose()
{
	close(g_i2cFile);
}

// set the I2C slave address for all subsequent I2C device transfers
void I2C::i2cSetAddress(int address)
{
	if (ioctl(g_i2cFile, I2C_SLAVE, address) < 0) {
		perror("i2cSetAddress");
		exit(1);
	}
}


void I2C::send(unsigned char DEVICE_ADDR, unsigned char Reg_ADDR, unsigned char Data){
	i2cSetAddress(DEVICE_ADDR);
	
	I2C_WR_Buf[0] = Reg_ADDR;
	I2C_WR_Buf[1] = Data;

	if(write(g_i2cFile, I2C_WR_Buf, 2) != 2) {
		perror("Write Error");
	}
}


unsigned char I2C::readByte(unsigned char DEVICE_ADDR,unsigned char Reg_ADDR){
	I2C_WR_Buf[0] = Reg_ADDR;
	
	i2cSetAddress(DEVICE_ADDR);
	if(write(g_i2cFile, I2C_WR_Buf, 1) != 1) {
		perror("Write Error");
	}
	i2cSetAddress(DEVICE_ADDR);	
	if(read(g_i2cFile, readBuf, 1) !=1){
		perror("Read Error");
	}
	
	return readBuf[0];
}

unsigned char I2C::readMultiBytes(unsigned char DEVICE_ADDR, unsigned char Reg_ADDR){
	I2C_WR_Buf[0] = Reg_ADDR;
	
	i2cSetAddress(DEVICE_ADDR);
	if(write(g_i2cFile, I2C_WR_Buf, 1) != 1) {
		perror("Write Error");
	}
	i2cSetAddress(DEVICE_ADDR);	
	if(read(g_i2cFile, readBuf, 7) !=7){
		perror("Read Error");
	}
		
	return readBuf[0];
}

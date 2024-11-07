#pragma once
class Register
{

	const int size = 16;
	unsigned char memory[16];
public:
	unsigned char getCell(unsigned char  address);
	void setCell(unsigned char  address, unsigned char  val);
};


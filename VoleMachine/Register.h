#pragma once
class Register
{

	const int size = 16;
	int memory[16];
public:
	int getCell(int address);
	void setCell(int address, int val);
};


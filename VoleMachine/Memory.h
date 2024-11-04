#pragma once
#include <string>


using namespace std;

class Memory
{
	string memory[256];
public:
	const int size = 256;
	Memory();
	string getCell(unsigned char  address);
	void setCell(unsigned char  address, string val);
};


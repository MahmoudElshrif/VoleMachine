#pragma once
#include <string>


using namespace std;

class Memory
{
	string memory[256];
public:
	const int size = 256;
	Memory();
	string getCell(int address);
	void setCell(int address, string val);
};


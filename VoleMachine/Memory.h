#pragma once
#include <string>


using namespace std;

class Memory
{
	const int size = 256;
	string memory[256];
public:
	string getCell(int address);
	void setCell(int address, string val);
};


#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Memory;
class Register;
class ALU;
class CU;


class CPU {
	unsigned char programCounter = 10;
	Register* reg;
	Memory* mem;
	CU* cu;
public:
	CPU(Memory* mem);
	~CPU();
	bool execute();
	void halt() {};
	void setMemory(Memory* mem);
	void printRegister();
	void clearReg();
};
#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Memory;
class Register;
class CU;


class CPU {
	unsigned char programCounter = 10;
	Register* reg;
	Memory* mem;
	CU* cu;
public:
	CPU(Memory* mem);
	~CPU();
	bool execute(bool step);
	void setMemory(Memory* mem);
	void printRegister();
	void clearReg();
};
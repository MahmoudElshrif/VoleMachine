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
	int programCounter = 1;
	Register* reg;
	Memory* mem;
	ALU* alu;
	CU* cu;
public:
	CPU(Memory* mem);
	~CPU();
	void runNextStep();
	bool execute(string s);
	void halt() {};
	void setMemory(Memory* mem);
	void printRegister();
};
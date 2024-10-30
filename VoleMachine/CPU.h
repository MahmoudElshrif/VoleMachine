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
	string intructionRegister;
	Register* reg;
	Memory* mem;
	ALU* alu;
	CU* cu;
public:
	CPU();
	~CPU();
	void runNextStep();
	void fetch();
	vector<int> decode();
	void execute(vector<int> vec);
	void halt();
	void setMemory(Memory* mem);
};
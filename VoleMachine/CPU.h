#pragma once
#include <string>
#include <vector>

using namespace std;

class Memory;
class Register;
class ALU;
class CU;


class CPU {
	int programCounter = 0;
	string intructionRegister;
	Register& reg;
	Memory& mem;
	ALU& ALU;
	CU& CU;
public:
	void runNextStep(Memory& mem);
	void fetch(Memory& mem);
	vector<int> decode();
	void execute(vector<int> vec);
	void halt();
};
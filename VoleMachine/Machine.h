#pragma once
#include <string>


class CPU;
class Memory;

using namespace std;

class Machine
{
	CPU* processor;
	Memory* memory;

public:
	Machine();
	~Machine();
	void loadProgramFile(string file);
	void printMemory();
	void printReg();
};


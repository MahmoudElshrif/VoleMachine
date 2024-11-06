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
	void loadFromFile(string file);
	void writeFile(string file);
	void printMemory();
	void printReg();
	void clearMemory();
	void clearReg();
	void start(bool step);
};


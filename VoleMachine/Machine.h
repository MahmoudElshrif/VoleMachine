#pragma once
#include <string>


class CPU;
class Memory;

using namespace std;

class Machine
{
	CPU& processor;
	Memory& memory;

public:
	Machine(string file);
	void loadProgramFile();
	void outputState();
};


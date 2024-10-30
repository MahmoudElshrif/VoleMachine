#include "Machine.h"
#include <fstream>
#include "Memory.h"
#include "CPU.h"

Machine::Machine(){
	memory = new Memory();
	processor = new CPU();
	processor->setMemory(memory);

}

Machine::~Machine() {
	delete memory;
	delete processor;
}

void Machine::loadProgramFile(string file) {
	ifstream f(file);
	int counter = 1;
	while (!f.eof()) {
		string s = "00";
		memory->setCell(counter++, s);
		if (counter > 255)
			break;
	}
}
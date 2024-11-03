#include "Machine.h"
#include <fstream>
#include "Memory.h"
#include "CPU.h"
#include "ALU.h"

Machine::Machine(){
	memory = new Memory();
	processor = new CPU(memory);
	//processor->setMemory(memory);

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
		f >> s[0];
		f >> s[1];
		memory->setCell(counter++, s);
		if (counter > 256)
			break;
	}
}


void Machine::printMemory() {
	cout << endl;
	string vals = "0123456789ABCDEF";

	cout << "  ";
	for (int i = 0; i < 16; i++) {
		cout << vals[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < memory->size;i++) {
		if (i % 16 == 0) {
			cout << vals[i / 16] << " ";
		}
		string val = memory->getCell(i);
		val[0] = toupper(val[0]);
		val[1] = toupper(val[1]);
		cout << val << " ";
		if ((i + 1) % 16 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}

void Machine::printReg() {
	this->processor->printRegister();
}
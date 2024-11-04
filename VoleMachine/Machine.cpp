#include "Machine.h"
#include <fstream>
#include "Memory.h"
#include "CPU.h"
#include <string>

Machine::Machine(){
	memory = new Memory();
	processor = new CPU(memory);

}

Machine::~Machine() {
	delete memory;
	delete processor;
}

void Machine::loadFromFile(string file) {
	ifstream f(file);
	if (!f.good()) {
		cout << "\nSomething went wrong\n\n";
		return;
	}
	int counter = 10;
	while (!f.eof()) {
		string s = "00";
		do {
		f >> s[0];

		} while (!isalpha(s[0]) && !isdigit(s[0]));

		do {
			f >> s[1];

		} while (!isalpha(s[0]) && !isdigit(s[0]));
		memory->setCell(counter++, s);
		if (counter > 256)
			break;
	}
}

void Machine::writeFile(string file){
	ofstream f(file);

	int program = 0;
	while (program < 256) {
		f << memory->getCell(program++) << memory->getCell(program++) << "\n";

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

void Machine::start() {
	processor->execute();
}

void Machine::clearMemory() {
	for (int i = 10; i < 256; i++) {
		this->memory->setCell(i, "00");
	}
}

void Machine::clearReg() {
	this->processor->clearReg();
}
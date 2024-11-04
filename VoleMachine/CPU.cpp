#include "CPU.h"
#include "Memory.h"
#include "Register.h"
#include "cu.h"
#include "CU.h"


CPU::CPU(Memory* mem){
	reg = new Register();
	cu = new CU();
	this->setMemory(mem);
}

CPU::~CPU() {
	delete reg;
	delete cu;
}


bool CPU::execute() {
	programCounter = 10;
	while (true) {
		string op = this->mem->getCell(programCounter++);
		string cell2 = this->mem->getCell(programCounter++);
		int regcell = cu->hexToDec("" + op[1]);
		switch (op[0]) {
		case '0':
		case 'c':
			return false;
			break;
		case '1':
			cu->load(regcell, cu->hexToDec(cell2), *reg, *mem);
			break;
		case '2':
			cu->load(regcell, cu->hexToDec(cell2), *reg);
			break;
		case'3':
			cu->store(regcell, cu->hexToDec(cell2),*reg,*mem);
			break;
		case '4':
			cu->move(cu->hexToDec("" + cell2[0]), cu->hexToDec("" + cell2[1]), *reg);
			break;
		case '5':
			cu->add(regcell, cu->hexToDec("" + cell2[0]), cu->hexToDec("" + cell2[1]), *reg);
			break;
		case '6':
			break;
		case 'b':
			cu->jump(regcell,cu->hexToDec(cell2),*reg, *mem, programCounter);
			break;
		}
	}
}

void CPU::setMemory(Memory* mem) {
	this->mem = mem;
}


void CPU::printRegister() {
	cout << endl;
	for (int i = 0; i < 16; i++) {
		cout << this->reg->getCell(i) << endl;
	}
	cout << endl;
}

void CPU::clearReg() {
	for (int i = 0; i < 16; i++) {
		reg->setCell(i, 0);
	}
}
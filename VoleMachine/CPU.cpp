#include "CPU.h"
#include "Memory.h"
#include "Register.h"
#include "ALU.h"
#include "CU.h"


CPU::CPU(Memory* mem){
	reg = new Register();
	alu = new ALU();
	cu = new CU();
	this->setMemory(mem);
}

CPU::~CPU() {
	delete reg;
	delete alu;
	delete cu;
}


void CPU::runNextStep() {
	string s = mem->getCell(programCounter) + mem->getCell(programCounter);
	this->execute(s);

	programCounter += 2;
}


void CPU::execute(string s) {
	string op = ("" + s[0]) + s[1];
	string cell2 = ("" + s[2]) + s[3];
	int regcell = alu->hexToDec("" + op[1]);
	switch (op[0]) {
	case 'c':
		halt();
		break;
	case '1':
		cu->load(regcell, programCounter + 1, *reg, *mem);
		break;
	case '2':
		cu->load(regcell, alu->hexToDec(cell2), *reg);
		break;
	case'3':
		cu->store(regcell, alu->hexToDec(cell2),*reg,*mem);
		break;
	case '4':
		cu->move(alu->hexToDec("" + cell2[0]), alu->hexToDec("" + cell2[1]), *reg);
		break;
	case '5':
		alu->add(regcell, alu->hexToDec("" + cell2[0]), alu->hexToDec("" + cell2[1]), *reg);
		break;
	case '6':
		break;
	case 'b':
		cu->jump(regcell,alu->hexToDec(cell2),*reg, programCounter);
		break;
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
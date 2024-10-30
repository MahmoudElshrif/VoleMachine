#include "CPU.h"
#include "Memory.h"
#include "Register.h"
#include "ALU.h"
#include "CU.h"


CPU::CPU(){
	reg = new Register();
	alu = new ALU();
	cu = new CU();
}


CPU::~CPU() {
	delete reg;
	delete alu;
	delete cu;
}


void CPU::runNextStep() {
	this->execute(this->decode());

	programCounter += 2;
}


vector<int> CPU::decode() {
	string op = mem->getCell(programCounter);
	string cell2 = mem->getCell(programCounter + 1);
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
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
	cout << "//////////////\n\n";
	while (true) {
		string op = this->mem->getCell(programCounter++);
		string cell2 = this->mem->getCell(programCounter++);
		unsigned char regcell = cu->hexToDec(op[1]);
		switch (op[0]) {
		case 'c':
			cout << "\n\n//////////////\n";
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
			cu->move(cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
			break;
		case '5':
			cu->add(regcell, cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
			break;
		case '6':
			cu->add(regcell, cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
			break;
		case '7':
			cu->bitwiseor(regcell, cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
			break;
		case '8':
			cu->bitwiseand(regcell, cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
			break;
		case '9':
			cu->bitwisexor(regcell, cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
			break;
		case 'a':
			cu->rotate(regcell,cell2[1], *reg);
			break;
		case 'b':
			cu->jumpIfEqual(regcell,cu->hexToDec(cell2),*reg, *mem, programCounter);
			break;
		case 'D':
			cu->jumpIfGreater(regcell, cu->hexToDec(cell2), *reg, *mem, programCounter);
			break;
		}
	}
}

void CPU::setMemory(Memory* mem) {
	this->mem = mem;
}


void CPU::printRegister() {
	cout << endl;
	for (unsigned char i = 0; i < 16; i++) {

		string val = cu->decToHex(this->reg->getCell(i));
		val[0] = toupper(val[0]);
		val[1] = toupper(val[1]);
		cout << (char)toupper(cu->decToHex(i)[1]) << ": " << val << endl;
	}
	cout << endl;
}

void CPU::clearReg() {
	for (unsigned char i = 0; i < 16; i++) {
		reg->setCell(i, 0);
	}
}
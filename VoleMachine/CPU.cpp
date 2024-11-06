#include "CPU.h"
#include "Memory.h"
#include "Register.h"
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

string captialHex(string s) {
	s[0] = toupper(s[0]);
	s[1] = toupper(s[1]);
	return s;
}

string MCell(string s) {
	return "M" + captialHex(s);
}

string RCell(char c) {
	return ("R" + string(1,c));
}

string RCell(unsigned char c) {
	const string chars = "0123456789ABCDEF";
	return ("R" + string(1,chars[c]));
}

bool CPU::execute(bool step) {
	programCounter = 10;
	cout << '\n';
	
	cu->resetState();

	while (true) {
		string op = this->mem->getCell(programCounter++);
		string cell2 = this->mem->getCell(programCounter++);
		unsigned char regcell = cu->hexToDec(op[1]);

		switch (op[0]) {
		case 'c':
			if(step)
				cout << "Halt" << endl;
			cout << "\n\n//////////////\n\n";
			cu->outputState();
			cout << "\n//////////////\n\n";
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
			cu->addFloat(regcell, cu->hexToDec(cell2[0]), cu->hexToDec(cell2[1]), *reg);
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
		case 'd':
			cu->jumpIfGreater(regcell, cu->hexToDec(cell2), *reg, *mem, programCounter);
			break;
		}

		if (step) {
			cout << captialHex(cu->decToHex(programCounter - 2)) << ") ";
			switch (op[0]) {
			case '1':
				cout << "Loaded " << MCell(cell2) << " into " << RCell(regcell) << endl;
				break;
			case '2':
				cout << "Loaded number " << captialHex(cell2) << " into " << RCell(regcell) << endl;
				break;
			case'3':
				cout << "Stored " << RCell(regcell) << " into " << MCell(cell2) << endl;
				break;
			case '4':
				cout << "Copied " << RCell(cell2[0]) << " to " << RCell(cell2[1]) << endl;
				break;
			case '5':
				cout << "Added values of " << RCell(cell2[0]) << " and " << RCell(cell2[1]) << " into " << RCell(regcell) << endl;
				break;
			case '6':
				cout << "Added values of " << RCell(cell2[0]) << " and " << RCell(cell2[1]) << " into " << RCell(regcell) << " as floats" << endl;
				break;
			case '7':
				cout << "Bitwise or values of " << RCell(cell2[0]) << " and " << RCell(cell2[1]) << " into " << RCell(regcell) << endl;
				break;
			case '8':
				cout << "Bitwise and values of " << RCell(cell2[0]) << " and " << RCell(cell2[1]) << " into " << RCell(regcell) << endl;
				break;
			case '9':
				cout << "Bitwise xor values of " << RCell(cell2[0]) << " and " << RCell(cell2[1]) << " into " << RCell(regcell) << endl;
				break;
			case 'a':
				cout << "Rotate " << RCell(regcell) << " by " << toupper(cell2[1]) << " steps\n";
				break;
			case 'b':
				cout << "Compare " << RCell(regcell) << " and to R0 jump to " << MCell(cell2) << " if equal\n";
				break;
			case 'd':
				cout << "Compare " << RCell(regcell) << " and to R0 jump to " << MCell(cell2) << " if greater\n";
				break;
			}
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
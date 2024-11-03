#include "Memory.h"


Memory::Memory() {
	for (int i = 0; i < 254; i++) {
		this->setCell(i, "00");
	}
	this->setCell(254, "c0");
	this->setCell(255, "00");
}

string Memory::getCell(int cell) {
	return this->memory[cell];
}


void Memory::setCell(int cell, string val) {
	val[0] = tolower(val[0]);
	val[1] = tolower(val[1]);
	this->memory[cell] = val;
}
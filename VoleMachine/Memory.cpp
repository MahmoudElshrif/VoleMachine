#include "Memory.h"


Memory::Memory() {
	for (unsigned char i = 0; i < 254; i++) {
		this->setCell(i, "00");
	}
	this->setCell(254, "c0");
	this->setCell(255, "00");
}

string Memory::getCell(unsigned char cell) {
	return this->memory[cell];
}


void Memory::setCell(unsigned char cell, string val) {
	val[0] = tolower(val[0]);
	val[1] = tolower(val[1]);
	this->memory[cell] = val;
	if (cell == 256 - 2)
		this->memory[cell] = "c0";
}
#include "Register.h"


unsigned char Register::getCell(unsigned char  cell) {
	return this->memory[cell];
}


void Register::setCell(unsigned char cell, unsigned char val) {
	this->memory[cell] = val;
}
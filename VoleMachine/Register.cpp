#include "Register.h"


int Register::getCell(int cell) {
	return this->memory[cell];
}


void Register::setCell(int cell, int val) {
	this->memory[cell] = val;
}
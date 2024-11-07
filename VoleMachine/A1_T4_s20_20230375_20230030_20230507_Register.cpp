#include "A1_T4_s20_20230375_20230030_20230507_Register.h"


unsigned char Register::getCell(unsigned char  cell) {
	return this->memory[cell];
}


void Register::setCell(unsigned char cell, unsigned char val) {
	this->memory[cell] = val;
}
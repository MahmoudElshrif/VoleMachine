#include <iostream>
#include "CU.h"
#include "Register.h"
#include "Memory.h"



void CU::load(unsigned char idxreg, unsigned char idxmem, Register& reg, Memory& mem) {
	reg.setCell(idxreg, hexToDec(mem.getCell(idxmem)));
}

void CU::load(unsigned char idxreg, unsigned char val, Register& reg) {
	reg.setCell(idxreg, val);
}

void CU::store(unsigned char idxreg, unsigned char idxmem, Register& reg, Memory& mem) {
	mem.setCell(idxmem, decToHex(reg.getCell(idxreg)));
	if (idxmem == 0) {
		cout << (unsigned char)reg.getCell(idxreg);
	}
}

void CU::move(unsigned char  idx1, unsigned char  idx2, Register& reg) {
	reg.setCell(idx2, reg.getCell(idx1));
}

void CU::add(unsigned char  idx1, unsigned char  idx2, unsigned char  idx3, Register& reg) {
	reg.setCell(idx1, reg.getCell(idx2) + reg.getCell(idx3));
}

void CU::jump(unsigned char idxReg, unsigned char IdxMem, Register& reg, Memory& mem, unsigned char& PC) {
	if (reg.getCell(0) == reg.getCell(idxReg)) {
		PC = IdxMem;
	}
}
unsigned char CU::hexToDec(char c) {
	return hexToDec(string(1, c));
}

unsigned char CU::hexToDec(string s) {
	unsigned char total = 0;

	if (s.length() == 1) {
		s = "0" + s;
	}

	if (isalpha(s[0])) {
		total += s[0] - 'a' + 10;
	}
	else {
		total += s[0] - '0';
	}

	total <<= 4;
	if (isalpha(s[1])) {
		total += s[1] - 'a' + 10;
	}
	else {
		total += s[1] - '0';
	}

	return total;
}

string CU::decToHex(unsigned char i) {
	string s = "00";
	const string chars = "0123456789abcedf";
	
	s[1] = chars[i & 15];
	i >>= 4;

	s[0] = chars[i & 15];

	return s;
}

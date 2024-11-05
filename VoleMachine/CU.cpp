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

void CU::addFloat(unsigned char  idx1, unsigned char  idx2, unsigned char  idx3, Register& reg) {
	auto val1 = reg.getCell(idx1);
	auto val2 = reg.getCell(idx2);

	double n1 = 0;
	double n2 = 0;

	for (int i = 0; i < 4; i++) {
		n1 /= 2.;
		n2 /= 2.;

		n1 += val1 & 1;
		n2 += val2 & 1;
	}

	n1 *= pow(2, val1 & 0b111);
	n2 *= pow(2, val1 & 0b111);
	
	val1 >>= 3;
	val1 >>= 3;
	if (val1) {
		n1 *= -1;
	}
	if (val2) {
		n2 *= -1;
	}

	auto n3 = n1 + n2;
	int exp = 0;

	while (n3 > 0) {
		exp++;
		n3 /= 2;
	}

	while (n3 != (int)n3) {
		n3 *= 2;
	}


	unsigned char f = 0;
	if (n3 < 0) {
		f += 1;
	}
	f <<= 3;
	
	f += exp;

	f <<= 4;
	
	f += n3;


	reg.setCell(idx1, f);


}

void CU::bitwiseor(unsigned char  idx1, unsigned char  idx2, unsigned char  idx3, Register& reg) {
	reg.setCell(idx1, reg.getCell(idx2) | reg.getCell(idx3));
}

void CU::bitwiseand(unsigned char  idx1, unsigned char  idx2, unsigned char  idx3, Register& reg) {
	reg.setCell(idx1, reg.getCell(idx2) & reg.getCell(idx3));
}

void CU::bitwisexor(unsigned char  idx1, unsigned char  idx2, unsigned char  idx3, Register & reg) {
	reg.setCell(idx1, reg.getCell(idx2) ^ reg.getCell(idx3));
}

void CU::rotate(unsigned char idx, unsigned char steps, Register& reg) {
	unsigned char val = reg.getCell(idx);
	for (int i = 0; i < steps; i++) {
		int c = val & 1;
		val >>= 1;
		val += 0x80 * c;
	}
}

void CU::jumpIfEqual(unsigned char idxReg, unsigned char IdxMem, Register& reg, Memory& mem, unsigned char& PC) {
	if (reg.getCell(0) == reg.getCell(idxReg)) {
		PC = IdxMem;
	}
}

void CU::jumpIfGreater(unsigned char idxReg, unsigned char IdxMem, Register& reg, Memory& mem, unsigned char& PC) {
	if ((char)reg.getCell(0) > (char)reg.getCell(idxReg)) {
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

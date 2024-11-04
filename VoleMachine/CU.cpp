#include <iostream>
#include "CU.h"
#include "Register.h"
#include "Memory.h"



void CU::load(int idxreg, int idxmem, Register& reg, Memory& mem) {
	reg.setCell(idxreg, hexToDec(mem.getCell(idxmem)));
}

void CU::load(int idxreg, int val, Register& reg) {
	reg.setCell(idxreg, val);
}

void CU::store(int idxreg, int idxmem, Register& reg, Memory& mem) {
	mem.setCell(idxmem, decToHex(reg.getCell(idxreg)));
	if (idxmem == 0) {
		cout << (char)reg.getCell(idxreg);
	}
}

void CU::move(int idx1, int idx2, Register& reg) {
	reg.setCell(idx1, reg.getCell(idx2));
}

void CU::add(int idx1, int idx2, int idx3, Register& reg) {
	reg.setCell(idx3, reg.getCell(idx1) + reg.getCell(idx2));
}

void CU::jump(int idxReg, int IdxMem, Register& reg, Memory& mem, int& PC) {
	if (reg.getCell(0) == reg.getCell(idxReg)) {
		PC = IdxMem;
	}
}


int CU::hexToDec(string s) {
	int total = 0;

	for (auto c : s) {
		total *= 16;
		if (isalpha(c)) {
			total += c - 'a' + 10;
		}
		else {
			total += c - '0';
		}
	}

	return total;
}

string CU::decToHex(int i) {
	string s = "";

	i %= 256;
	if (i == 0) {
		return "00";
	}

	const string chars = "0123456789abcedf";
	while (i) {
		s += chars[i % 16];
		i /= 16;
	}

	reverse(s.begin(), s.end());
	if (s.length() == 1) {
		return "0" + s;
	}
	return s;
}
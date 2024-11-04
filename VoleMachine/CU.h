#pragma once


class Register;

class Memory;

using namespace std;

class CU
{
public:
	CU() {};
	void load(int idxReg, int idxMem, Register& reg, Memory& mem);
	void load(int idxReg, int val, Register& reg);
	void store(int idxReg, int idxMem, Register& reg, Memory& mem);
	void move(int idxReg1, int idxReg2, Register& reg);
	void jump(int idxReg, int IdxMem, Register& reg,Memory& mem, int& PC);
	int hexToDec(string num);
	string decToHex(int num);
	void add(int idx1, int idx2, int idx3, Register& reg);
};


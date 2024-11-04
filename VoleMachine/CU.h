#pragma once


class Register;

class Memory;

using namespace std;

class CU
{
public:
	CU() {};
	void load(unsigned char idxReg, unsigned char idxMem, Register& reg, Memory& mem);
	void load(unsigned char idxReg, unsigned char val, Register& reg);
	void store(unsigned char idxReg, unsigned char idxMem, Register& reg, Memory& mem);
	void move(unsigned char idxReg1, unsigned char idxReg2, Register& reg);
	void jumpIfEqual(unsigned char idxReg, unsigned char IdxMem, Register& reg, Memory& mem, unsigned char& PC);
	void jumpIfGreater(unsigned char idxReg, unsigned char IdxMem, Register& reg,Memory& mem, unsigned char& PC);
	unsigned char hexToDec(char c);
	unsigned char hexToDec(string num);
	string decToHex(unsigned char num);
	void add(unsigned char idx1, unsigned char idx2, unsigned char idx3, Register& reg);
	void addFloat(unsigned char idx1, unsigned char idx2, unsigned char idx3, Register& reg);
	void bitwiseor(unsigned char idx1, unsigned char idx2, unsigned char idx3, Register& reg);
	void bitwiseand(unsigned char idx1, unsigned char idx2, unsigned char idx3, Register& reg);
	void bitwisexor(unsigned char idx1, unsigned char idx2, unsigned char idx3, Register& reg);
	void rotate(unsigned char idx, unsigned char steps, Register& reg);
};


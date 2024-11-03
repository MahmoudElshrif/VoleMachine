#pragma once


class Register;

class Memory;

class CU
{
public:
	CU() {};
	void load(int idxReg, int idxMem, Register& reg, Memory& mem) {};
	void load(int idxReg, int val, Register& reg) {};
	void store(int idxReg, int idxMem, Register& reg, Memory& mem) {};
	void move(int idxReg1, int idxReg2, Register& reg) {};
	void jump(int& PC,int idx) {};
};


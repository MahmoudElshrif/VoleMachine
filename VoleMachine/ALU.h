#pragma once
#include <string>

class Register;

using namespace std;

class ALU
{
public:
	ALU();
	int hexToDec(string num);
	string decToHex(int num);
	bool isValid(string num);
	void add(int idx1, int idx2, int idx3, Register& reg);
};


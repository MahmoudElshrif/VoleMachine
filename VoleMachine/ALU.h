#pragma once
#include <string>

class Register;

using namespace std;

class ALU
{
public:
	ALU() {};
	int hexToDec(string num) { return 0; };
	string decToHex(int num) { return "01"; };
	bool isValid(string num) { return true; };
	void add(int idx1, int idx2, int idx3, Register& reg) {};
};


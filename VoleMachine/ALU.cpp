#include "ALU.h"



int ALU::hexToDec(string s) {
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

string ALU::decToHex(int i) {
	string s = "";

	const string chars = "0123456789abcedf";
	while (i) {
		s += chars[i % 16];
		i /= 16;
	}

	return s;
}
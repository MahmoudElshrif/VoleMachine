#pragma once
#include <iostream>
using namespace std;

class Machine;

class MachineUI
{
	Machine* machine;
public:
	MachineUI();
	void displayOptions();
	void readFromFile();
	void writeToFile();
};


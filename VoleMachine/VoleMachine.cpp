#include <iostream>
#include "Machine.h"

int main()
{
	Machine m;
	m.loadProgramFile("test.txt");

	m.printMemory();
	m.printReg();
}

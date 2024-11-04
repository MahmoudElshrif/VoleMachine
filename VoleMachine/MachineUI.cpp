#include "MachineUI.h"
#include "Machine.h"


MachineUI::MachineUI() {
	machine = new Machine();
	displayOptions();
}

void MachineUI::displayOptions() {
	while (true){
		cout << "---------Vole Machine---------\n" << endl;
		cout << "1) Read file into memory\n";
		cout << "2) Execute";
		cout << "3) Print Memory\n";
		cout << "4) Print Register\n";
		cout << "5) Clear Memory\n";
		cout << "6) Clear Register\n";
		cout << "7) Write memory into file\n";
		cout << "0) Exit\n";

		char c;
		cin >> c;

		switch (c) {
			case '0':
				return;
				break;
			case '1':
				readFromFile();
				break;
			case '2':
				machine->start();
				break;
			case '3':
				machine->printMemory();
				break;
			case '4':
				machine->printReg();
				break;
			case '5':
				machine->clearMemory();
				break;
			case '6':
				machine->clearReg();
				break;
			case '7':
				writeToFile();
				break;
			default:
				cout << "/////////invalid operation/////////\n";
				break;

		}
	}
}



void MachineUI::readFromFile() {
	machine->loadFromFile("test.txt");
}
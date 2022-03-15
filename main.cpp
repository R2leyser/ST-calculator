#include <string>		// Angle brackets because i didn't write it 
#include <iostream>		// Angle brackets because i didn't write it 
#include "formulas.h"	// Double quotes because i wrote it

int main() 
{
top:
	std::cout << "What do you want to do? \n"
			"1. Furnace array hopper speed calculator \n"
			"2. Hopper clock timing \n"
			"3. Amount of comaparators on a pulse exender\n"
			"Type 'Exit' to  exit \n\n";

	std::string optionInput{};
	std::cin >> optionInput;

	if (optionInput == "1") {
		hsPerModule();
	}
	else if (optionInput == "2") {
		hcTiming();
	}
	else if (optionInput == "3") {
		compNumPE();
	}
	else if (optionInput == "Exit") {
		return 0;
	}
	else {
		std::cout << "\n ERROR: Not a valid command \n \n";
		goto top;
	}
}

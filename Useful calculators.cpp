#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() 
{
	//forward declaration
	void compNumPE();
	void hcTiming();
	void hsPerModule();


top:
	cout << "What do you want to do? \n"
			"1. Furnace array hopper speed calculator \n"
			"2. Hopper clock timing \n"
			"3. Amount of comaparators on a pulse exender\n"
			"Type 'Exit' to  exit \n\n";

	string optionInput{};
	cin >> optionInput;

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
		cout << "\n ERROR: Not a valid command \n \n";
		goto top;
	}

}

void hsPerModule()	// hopper speed per furnace array module
{
	float furnaces{};
	cout << "How many furnaces per module? \n";
	cin >> furnaces;

	float furnaceModules{};
	cout << "How many modules will you have? \n";
	cin >> furnaceModules;


	//6 items per minute per furnace, 1 hopper transfers 150 items per min
	float output{ ceil(furnaces * furnaceModules * 6 / 150) };

	cout << output << " hopper speed in total \n" << ceil(output / furnaceModules) << " hopper speed per module \n";
}

void hcTiming() // hopper clock timing
{
	float seconds{};
	cout << "How many seconds do you want the clock time to be? \n";
	cin >> seconds;

	cout << ceil((2.5 * seconds) / 2) << " items \n";
}

void compNumPE() // Number of comparators in a pulse extender
{
	int seconds{};
	string temp{};

	cout << "How many seconds do you want it to take? \n";
	cin >> seconds;

compStart:
	cout << "Do you want to use a block (y/n)\n";
	cin >> temp;

	// 1.5 seconds per 2 comparators without block
	double comparatorsBlock{ ceil(3 / 2 * seconds) };
	double comparatorsNoBlock{ ceil(1.5 / 2 * seconds) };

	if (temp == "y") {
		cout << comparatorsBlock + (int(comparatorsBlock) % 2) << " Comparators \n";
		if (comparatorsBlock < comparatorsBlock + (int(comparatorsBlock) % 2)) {
			cout << " +3 sec use " << comparatorsBlock << " comparators if you want to have exactly " << seconds << " seconds";
		}
	}
	else if (temp == "n") {
		cout << comparatorsNoBlock + (int(comparatorsNoBlock) % 2);
		if (comparatorsNoBlock < comparatorsNoBlock + (int(comparatorsNoBlock) % 2)) {
			cout << " +1.5 sec use " << comparatorsNoBlock << " comparators if you want to have exactly " << seconds << " seconds";
		}
	}
	else {
		cout << "\nERROR: not a valid option\n\n";
		goto compStart;
	};

}
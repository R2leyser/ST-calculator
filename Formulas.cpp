#include <iostream>
#include <string>
#include <math.h>


void hsPerModule()	// hopper speed per furnace array module
{
	float furnaces{};
	std::cout << "How many furnaces per module? \n";
	std::cin >> furnaces;

	float furnaceModules{};
	std::cout << "How many modules will you have? \n";
	std::cin >> furnaceModules;


	//6 items per minute per furnace, 1 hopper transfers 150 items per min
	float output{ ceil(furnaces * furnaceModules * 6 / 150) };

	std::cout << output << " hopper speed in total \n" << ceil(output / furnaceModules) << " hopper speed per module \n";
}

void hcTiming() // hopper clock timing
{
	float seconds{};
	std::cout << "How many seconds do you want the clock time to be? \n";
	std::cin >> seconds;

	std::cout << ceil((2.5 * seconds) / 2) << " items \n";
}

void compNumPE() // Number of comparators in a pulse extender																				
{
	int seconds{};
	std::string temp{};

	std::cout << "How many seconds do you want it to take? \n";
	std::cin >> seconds;

compStart:
	std::cout << "Do you want to use a block (y/n)\n";
	std::cin >> temp;

	// 1.5 seconds per 2 comparators without block																							
	double comparatorsBlock{ ceil(3 / 2 * seconds) };
	double comparatorsNoBlock{ ceil(1.5 / 2 * seconds) };

	if (temp == "y") {
		std::cout << comparatorsBlock + (int(comparatorsBlock) % 2) << " comparators ";
		if (comparatorsBlock < comparatorsBlock + (int(comparatorsBlock) % 2)) {
			std::cout << " +3 sec use " << comparatorsBlock << " comparators if you want to have exactly " << seconds << " seconds";
		}
	}
	else if (temp == "n") {
		std::cout << comparatorsNoBlock + (int(comparatorsNoBlock) % 2);
		if (comparatorsNoBlock < comparatorsNoBlock + (int(comparatorsNoBlock) % 2)) {
			std::cout << " +1.5 sec use " << comparatorsNoBlock << " comparators if you want to have exactly " << seconds << " seconds";
		}
	}
	else {
		std::cout << "\nERROR: not a valid option\n\n";
		goto compStart;
	};
}
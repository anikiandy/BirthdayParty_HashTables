#include <iostream>
#include <string>
#include "BirthdayParty.h"

int main()
{

	std::cout << "-------------start birthday party---------------\n";
	//make a birthday party list
	BirthdayParty myParty = BirthdayParty(100);

	//test key
	int key = myParty.hash("ctor", "boner");

	std::cout<< "KEY IS:" << key;

	std::cout << "-------------end birthday party---------------\n";
	return 0;
}

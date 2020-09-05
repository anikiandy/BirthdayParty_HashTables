#include <iostream>
#include <string>
#include "BirthdayParty.h"

int main()
{
	bool tf1, tf2;
	std::cout << "-------------start birthday party---------------\n";
	//make a birthday party list
	BirthdayParty myParty = BirthdayParty(4);

	//test key
	int key = myParty.hash("ctor", "boner");

	std::cout<< "KEY IS:" << key;
	tf1 = myParty.addInvitee("bobby", "joe", "wonderful");
	tf2 = myParty.addInvitee("bobby", "joe", "wonderful");

	std::cout << "\n\n__________________\n\n" << "TF1: " << tf1 <<std::endl<< "TF2: " << tf2<<std::endl; 

	std::cout << "-------------end birthday party---------------\n";

	return 0;
}

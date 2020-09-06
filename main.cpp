#include <iostream>
#include <string>
#include "BirthdayParty.h"


int main()
{
	bool tf1, tf2, tf3;
	std::cout << "-------------start birthday party---------------\n";
	//make a birthday party list
	BirthdayParty myParty = BirthdayParty();

	//test key
	int key = myParty.hash("ctor", "boogers");

	std::cout<< "KEY IS:" << key;
	tf1 = myParty.addInvitee("bobby", "joe", "wonderful");
	std::cout << "\n count(1): " << myParty.whosOnTheGuestList() << std::endl;
	tf2 = myParty.addInvitee("bobby", "joe", "wonderful");
	std::cout << "\n count(1): " << myParty.whosOnTheGuestList() << std::endl;
	tf3 = myParty.addInvitee("jonny", "Dingdong", "wallace");
	std::cout << "\n count(2): " << myParty.whosOnTheGuestList() << std::endl;
	tf3 = myParty.addInvitee("Jeanne", "LIU", "boingo");
	std::cout << "\n count(3): " << myParty.whosOnTheGuestList() << std::endl;
	tf3 = myParty.addInvitee("andy", "shiraki", "doingo");
	std::cout << "\n count(4): " << myParty.whosOnTheGuestList() << std::endl;
	tf3 = myParty.addInvitee("bolo", "tumpkins", "jojo");
	std::cout << "\n count(5): " << myParty.whosOnTheGuestList() << std::endl;
	tf2 = myParty.addInvitee("mobby", "joe", "wonderful");
	std::cout << "\n count(6): " << myParty.whosOnTheGuestList() << std::endl;

	std::cout << "\n\n__________________\n\n" << "TF1: " << tf1 <<std::endl<< "TF2: " << tf2<<std::endl << "TF3: " << tf3<< std::endl ; 

	std::cout << "\n\n BOOGDERS: " << myParty.makeLower("Boogers") << std::endl <<"____________________________________\n";

	std::cout << "Compare Andy to jeanne: " << myParty.stringCompare("jeanne", "jeanne") << std::endl;
	std::cout << "how many people on list: " << myParty.whosOnTheGuestList() << std::endl;

	std::cout << "-------------end birthday party---------------\n";

	return 0;
}

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
	tf3 = myParty.addInvitee("BUndy", "szrraki", "doingo");
	tf3 = myParty.addInvitee("Fredrick", "Shinoko", "doingo");
	std::cout << "\n count(5): " << myParty.whosOnTheGuestList() << std::endl;
	tf2 = myParty.addInvitee("mobby", "joe", "wonderful");
	std::cout << "\n count(6): " << myParty.whosOnTheGuestList() << std::endl;
	myParty.modifyInvitee("andy", "shiraki", "seventy2");
	myParty.dropFromGuestList("Fredrick", "Shinoko");
	myParty.addOrModify("mobby", "joe", "turtles");
	myParty.addOrModify("leonardo", "mutant", "boxers");

	BirthdayParty copyParty = BirthdayParty(myParty);
	myParty.~BirthdayParty();
	BirthdayType testType;

	//myParty.checkGuestList("andy", "shiraki", testType);

	std::cout << "Test Birthday TYpe:   "<< testType << std::endl;

	std::cout << "-------------end birthday party---------------\n";

	for (int n = 0; n < copyParty.whosOnTheGuestList(); n++)
	{
		std::string first;
		std::string last;
		BirthdayType val;
		copyParty.selectInvitee(n, first, last, val);
		std::cout << first << " " << last << " " << val << std::endl;
	}
	std::cout << "nothing";
	return 0;
}

#include <iostream>
#include <string>
#include "BirthdayParty.h"
#include "assert.h"



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

	BirthdayParty theLastDance;
	theLastDance.addInvitee("Michael", "Jordan", "23");
	theLastDance.addInvitee("Scottie", "Pippen", "33");
	theLastDance.addInvitee("Dennis", "Rodman", "91");
	theLastDance.addInvitee("Luc", "Longley", "13");
	theLastDance.addInvitee("Ron", "Harper", "9");
	for (int n = 0; n < theLastDance.whosOnTheGuestList(); n++)
	{
		std::string first;
		std::string last;
		BirthdayType val;
		theLastDance.selectInvitee(n, first, last, val);
		std::cout << first << " " << last << " " << val << std::endl;
	}


	BirthdayParty copyParty = BirthdayParty(myParty);
	myParty.~BirthdayParty();

	myParty.addOrModify("mobby", "joe", "turtles");
	myParty.addOrModify("leonardo", "mutant", "boxers");

	myParty.changeGuestList(copyParty);

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

	
	BirthdayParty dodgers;
	dodgers.addInvitee("Clayton", "Kershaw", "31.0");
	dodgers.addInvitee("Cody", "Bellinger", "11.5");
	assert(!dodgers.personOnGuestList("", ""));
	dodgers.addInvitee("Mookie", "Betts", "27.0");
	dodgers.addInvitee("", "", "0.57");
	dodgers.addInvitee("Justin", "Turner", "20.0");
	assert(dodgers.personOnGuestList("", ""));
	dodgers.dropFromGuestList("Mookie", "Betts");
	assert(dodgers.whosOnTheGuestList() == 4
		&& dodgers.personOnGuestList("Clayton", "Kershaw")
		&& dodgers.personOnGuestList("Cody", "Bellinger")
		&& dodgers.personOnGuestList("Justin", "Turner")
		&& dodgers.personOnGuestList("", ""));
		


	//test combineguest list
	BirthdayParty bp1, bp2, bp3;
	bp1 = BirthdayParty();
	bp2 = BirthdayParty();
	bp3 = BirthdayParty();
	bp1.addInvitee("Kobe", "Bryant", "8");
	bp1.addInvitee("Gianna", "Bryant", "19");
	bp1.addInvitee("Pau", "gasol", "24");
	bp1.addInvitee("Kobe", "Jeans", "12");
	//combineGuestLists(bp1, bp2, bp3);
	verifyGuestList("Kobe", "*", bp1, bp3);
	
	for (int n = 0; n < bp3.whosOnTheGuestList(); n++)
	{
		std::string first;
		std::string last;
		BirthdayType val;
		bp3.selectInvitee(n, first, last, val);
		std::cout << first << " " << last << " " << val << std::endl;
	}
	return 0;
}

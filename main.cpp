#include <iostream>
#include <string>
#include "BirthdayParty.h"
#include "assert.h"



int main()
{
	bool tf1, tf2;
	std::cout << "-------------start birthday party---------------\n";
	//make a birthday party list
	BirthdayParty myParty = BirthdayParty();

	tf1 = myParty.addInvitee("bobby", "joe", 1);
	std::cout << "\n count(1): " << myParty.whosOnTheGuestList() << std::endl;
	tf2 = myParty.addInvitee("bobby", "joe", 23);

	BirthdayParty theLastDance;
	theLastDance.addInvitee("Michael", "Jordan", 23);
	theLastDance.addInvitee("Scottie", "Pippen", 33);
	theLastDance.addInvitee("Dennis", "Rodman", 91);
	theLastDance.addInvitee("Luc", "Longley", 13);
	theLastDance.addInvitee("Ron", "Harper", 9);
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

	myParty.addOrModify("Andrew", "Shiraki", 1);

	myParty.changeGuestList(copyParty);


	std::cout << "-------------end birthday party---------------\n";

	for (int n = 0; n < copyParty.whosOnTheGuestList(); n++)
	{
		std::string first;
		std::string last;
		BirthdayType val;
		copyParty.selectInvitee(n, first, last, val);
		std::cout << first << " " << last << " " << val << std::endl;
	}
	
	BirthdayParty dodgers;
	dodgers.addInvitee("Clayton", "Kershaw", 31);
	dodgers.addInvitee("Cody", "Bellinger", 11);
	assert(!dodgers.personOnGuestList("", ""));
	dodgers.addInvitee("Mookie", "Betts", 27);
	dodgers.addInvitee("", "", 57);
	dodgers.addInvitee("Justin", "Turner", 20);
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
	bp1.addInvitee("Kobe", "Bryant", 8);
	bp1.addInvitee("Gianna", "Bryant", 19);
	bp1.addInvitee("Pau", "gasol", 24);
	bp1.addInvitee("Kobe", "Jeans", 12);
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

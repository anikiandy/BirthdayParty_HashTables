/*#include <iostream>
#include <string>
#include "BirthdayParty.h"
#include "assert.h"

void spamList(BirthdayParty bp)
{
	for (int n = 0; n < bp.whosOnTheGuestList(); n++)
	{
		std::string first;
		std::string last;
		BirthdayType val;
		bp.selectInvitee(n, first, last, val);
		std::cout << first << " " << last << " " << val << std::endl;
	}
}


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
	spamList(theLastDance);


	BirthdayParty copyParty = BirthdayParty(theLastDance);
	myParty.~BirthdayParty();
	myParty.addOrModify("Andrew", "Shiraki", 1);
	myParty.changeGuestList(copyParty);
	std::cout << "----------------------------\n";
	spamList(copyParty);

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
	bp1.addInvitee("Kobe", "bean", 12);
	//combineGuestLists(bp1, bp2, bp3);
	verifyGuestList("Kobe", "*", bp1, bp3);

	spamList(bp3);
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	bp3.dropFromGuestList("Kobe", "Bryant");
	bp3.addInvitee("Andrew", "Shiraki", 1);
	bp3.addInvitee("Olive", "Shiraki", 5);
	bp3.addInvitee("", "Blanky", 5);
	bp3.addInvitee("blankerson", "", 23);

	spamList(bp3);
	std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	spamList(bp1);

	return 0;
}
*/
// ?Fall 2020 E.Ambrosio
//Project 2: The Year of the Quarantine Testing
//There were 100 test cases.Each test was worth 1.3 points each; to run the test cases :
//1. Remove the main routine from your BirthdayParty.cpp file.
//2. Append the following text to the end of your BirthdayParty.cpp file and build
//the resulting program.
//3. For any test case you wish to try, run the program, providing as input the test
//number.
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
#include <type_traits>
#include "BirthdayParty.h"
using namespace std;
bool checkGuestList3type(bool (BirthdayParty::*)(const
	std::string&, const std::string&, BirthdayType&) const) {
	return
		true;
}
bool checkGuestList3type(bool (BirthdayParty::*)(const
	std::string&, const std::string&, BirthdayType&)) {
	return
		false;
}
bool checkGuestList3type(...) { return false; }
bool selectInvitee4type(bool (BirthdayParty::*)(int,
	std::string&, std::string&, BirthdayType&) const) {
	return true;
}
bool selectInvitee4type(bool (BirthdayParty::*)(int,
	std::string&, std::string&, BirthdayType&)) {
	return false;
}
bool selectInvitee4type(...) { return false; }
std::string SOMEFNAME = std::string("123");
std::string DEFAULTFNAME = std::string();
std::string ARRAYFNAME[6] = {
std::string("10"), std::string("20"), std::string("30"),
std::string("40"), std::string("50"), std::string("60")
};
std::string SOMELNAME = std::string("321");
std::string DEFAULTLNAME = std::string();
std::string ARRAYLNAME[6] = {
std::string("11"), std::string("21"), std::string("31"),
std::string("41"), std::string("51"), std::string("61")
};
// ?Fall 2020 E.Ambrosio
BirthdayType SOMEVALUE = "junk";
BirthdayType DEFAULTV = BirthdayType();
BirthdayType ARRAYV[6] = {
"able", "baker", "charlie", "delta", "echo", "foxtrot"
};
bool has(const BirthdayParty& m, const std::string& firstName,
	const std::string& lastName, const BirthdayType& v)
{
	BirthdayType v2 = DEFAULTV;
	m.checkGuestList(firstName, lastName, v2);
	BirthdayType v3 = SOMEVALUE;
	m.checkGuestList(firstName, lastName, v3);
	return v2 == v && v3 == v;
}
void testone(int n)
{
	BirthdayParty m;
	switch (n)
	{
	default: {
		cout << "Bad argument" << endl;
	} break; case 1: {
		assert((is_same<decltype(&BirthdayParty::noInvitees), bool
		(BirthdayParty::*)() const>::value));
	} break; case 2: {
		//assert((is_same<decltype(&BirthdayParty::whosOnTheGuestLis
			//t), int (BirthdayParty::*)() const>::value));
	} break; case 3: {
		assert((is_same<decltype(&BirthdayParty::personOnGuestList
			), bool (BirthdayParty::*)(const std::string, const std::string)
			const>::value) ||
			(is_same<decltype(&BirthdayParty::personOnGuestList), bool
			(BirthdayParty::*)(const std::string&, const std::string&)
				const>::value));
	} break; case 4: {
		assert(checkGuestList3type(&BirthdayParty::checkGuestList)
		);
	} break; case 5: {
		// ?Fall 2020 E.Ambrosio
		assert(selectInvitee4type(&BirthdayParty::selectInvitee));
	} break; case 6: {
		assert(m.noInvitees());
	} break; case 7: {
		assert(m.whosOnTheGuestList() == 0);
	} break; case 8: {
		assert(!m.modifyInvitee(DEFAULTFNAME, DEFAULTLNAME,
			SOMEVALUE) && m.whosOnTheGuestList() == 0);
	} break; case 9: {
		assert(!m.dropFromGuestList(DEFAULTFNAME,
			DEFAULTLNAME) && m.whosOnTheGuestList() == 0);
	} break; case 10: {
		assert(!m.personOnGuestList(DEFAULTFNAME,
			DEFAULTLNAME));
	} break; case 11: {
		BirthdayType v = SOMEVALUE;
		assert(!m.checkGuestList(DEFAULTFNAME, DEFAULTLNAME,
			v) && v == SOMEVALUE);
	} break; case 12: {
		BirthdayType v = SOMEVALUE;
		assert(!m.selectInvitee(0, DEFAULTFNAME,
			DEFAULTLNAME, v) && v == SOMEVALUE);
	} break; case 13: {
		assert(m.addInvitee(SOMEFNAME, SOMELNAME,
			SOMEVALUE));
	} break; case 14: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		assert(!m.noInvitees());
	} break; case 15: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		assert(m.whosOnTheGuestList() == 1);
	} break; case 16: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		assert(m.personOnGuestList(SOMEFNAME, SOMELNAME));
	} break; case 17: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		BirthdayType v = DEFAULTV;
		assert(m.checkGuestList(SOMEFNAME, SOMELNAME, v));
	} break; case 18: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		BirthdayType v = DEFAULTV;
		m.checkGuestList(SOMEFNAME, SOMELNAME, v);
		assert(v == SOMEVALUE);
	} break; case 19: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			SOMEVALUE);
		// ?Fall 2020 E.Ambrosio
		BirthdayType v = DEFAULTV;
		assert(!m.checkGuestList(ARRAYFNAME[1],
			ARRAYLNAME[1], v));
	} break; case 20: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		BirthdayType v = SOMEVALUE;
		m.checkGuestList(ARRAYFNAME[1], ARRAYLNAME[1], v);
		assert(v == SOMEVALUE);
	} break; case 21: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		std::string f = DEFAULTFNAME;
		std::string l = DEFAULTLNAME;
		BirthdayType v = DEFAULTV;
		assert(m.selectInvitee(0, f, l, v));
	} break; case 22: {
		m.addInvitee(SOMEFNAME, SOMELNAME, SOMEVALUE);
		std::string f = DEFAULTFNAME;
		std::string l = DEFAULTLNAME;
		BirthdayType v = DEFAULTV;
		m.selectInvitee(0, f, l, v);
		assert(f == SOMEFNAME && l == SOMELNAME && v ==
			SOMEVALUE);
	} break; case 23: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(!m.noInvitees() && m.whosOnTheGuestList() ==
			2);
	} break; case 24: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(m.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) && m.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]));
	} break; case 25: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
	} break; case 26: {
		// ?Fall 2020 E.Ambrosio
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			SOMEVALUE);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE);
		assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
			SOMEVALUE) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
	} break; case 27: {
		assert(m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]));
		assert(m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]));
	} break; case 28: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[2]);
		assert(m.whosOnTheGuestList() == 2);
	} break; case 29: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[2]);
		assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
	} break; case 30: {
		assert(m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]));
		assert(m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]));
		assert(!m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[2]));
	} break; case 31: {
		assert(m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]));
		assert(m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]));
		assert(!m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]));
	} break; case 32: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		// ?Fall 2020 E.Ambrosio
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m.modifyInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE);
		assert(m.whosOnTheGuestList() == 3 &&
			m.personOnGuestList(ARRAYFNAME[0], ARRAYLNAME[0]) &&
			m.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) && m.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]));
	} break; case 33: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m.modifyInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE);
		assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE) &&
			has(m, ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]));
	} break; case 34: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		assert(m.modifyInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE));
	} break; case 35: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.modifyInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[0]);
		assert(m.whosOnTheGuestList() == 2 && has(m,
			ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
			has(m, ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]) && !m.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]));
	} break; case 36: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		// ?Fall 2020 E.Ambrosio
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(!m.modifyInvitee(ARRAYFNAME[2],
			ARRAYLNAME[2], ARRAYV[2]) && !m.modifyInvitee(ARRAYFNAME[3],
				ARRAYLNAME[3], ARRAYV[0]));
	} break; case 37: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addOrModify(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(!m.noInvitees() && m.whosOnTheGuestList() ==
			2);
	} break; case 38: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addOrModify(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]));
	} break; case 39: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			SOMEVALUE);
		m.addOrModify(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE);
		assert(has(m, ARRAYFNAME[0], ARRAYLNAME[0],
			SOMEVALUE) && has(m, ARRAYFNAME[1], ARRAYLNAME[1], SOMEVALUE));
	} break; case 40: {
		assert(m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]));
		assert(m.addOrModify(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]));
	} break; case 41: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addOrModify(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[2]);
		assert(m.whosOnTheGuestList() == 2 && has(m,
			ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[2]) &&
			has(m, ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]));
	} break; case 42: {
		assert(m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]));
		assert(m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]));
		// ?Fall 2020 E.Ambrosio
		assert(m.addOrModify(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[2]));
	} break; case 43: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m.addOrModify(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE);
		assert(m.whosOnTheGuestList() == 3 && has(m,
			ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
			has(m, ARRAYFNAME[1], ARRAYLNAME[1],
				SOMEVALUE) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]));
	} break; case 44: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		assert(m.addOrModify(ARRAYFNAME[1], ARRAYLNAME[1],
			SOMEVALUE));
	} break; case 45: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addOrModify(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[0]);
		assert(m.whosOnTheGuestList() == 3 && has(m,
			ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
			has(m, ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[0]));
	} break; case 46: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(m.addOrModify(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]));
	} break; case 47: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		// ?Fall 2020 E.Ambrosio
		assert(m.dropFromGuestList(ARRAYFNAME[1],
			ARRAYLNAME[1]));
	} break; case 48: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.dropFromGuestList(ARRAYFNAME[1], ARRAYLNAME[1]);
		assert(!m.noInvitees() && m.whosOnTheGuestList() ==
			1 && has(m, ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
			!m.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]));
	} break; case 49: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.dropFromGuestList(ARRAYFNAME[0], ARRAYLNAME[0]);
		assert(!m.noInvitees() && m.whosOnTheGuestList() ==
			1 && has(m, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1]) &&
			!m.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]));
	} break; case 50: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.dropFromGuestList(ARRAYFNAME[0], ARRAYLNAME[0]);
		m.dropFromGuestList(ARRAYFNAME[1], ARRAYLNAME[1]);
		assert(m.whosOnTheGuestList() == 0);
	} break; case 51: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m.dropFromGuestList(ARRAYFNAME[1], ARRAYLNAME[1]);
		m.dropFromGuestList(ARRAYFNAME[2], ARRAYLNAME[2]);
		m.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		assert(m.whosOnTheGuestList() == 2 && has(m,
			ARRAYFNAME[0], ARRAYLNAME[0], ARRAYV[0]) &&
			has(m, ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]) && !m.personOnGuestList(ARRAYFNAME[1], ARRAYLNAME[1])
			&&
			// ?Fall 2020 E.Ambrosio
			!m.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 52: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		assert(!m.dropFromGuestList(ARRAYFNAME[2],
			ARRAYLNAME[2]) && m.whosOnTheGuestList() == 2);
	} break; case 53: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		std::string f;
		std::string l;
		BirthdayType v;
		assert(!m.selectInvitee(-1, f, l, v));
	} break; case 54: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		std::string f = SOMEFNAME;
		std::string l = SOMELNAME;
		BirthdayType v = SOMEVALUE;
		m.selectInvitee(-1, f, l, v);
		assert(f == SOMEFNAME && l == SOMELNAME && v ==
			SOMEVALUE);
	} break; case 55: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		std::string f, l;
		BirthdayType v;
		assert(!m.selectInvitee(2, f, l, v));
	} break; case 56: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		std::string f = SOMEFNAME;
		std::string l = SOMELNAME;
		BirthdayType v = SOMEVALUE;
		m.selectInvitee(2, f, l, v);
		// ?Fall 2020 E.Ambrosio
		assert(f == SOMEFNAME && l == SOMELNAME && v ==
			SOMEVALUE);
	} break; case 57: {
		m.addInvitee(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
		assert(m.whosOnTheGuestList() == 1 && has(m,
			DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE));
	} break; case 58: {
		m.modifyInvitee(DEFAULTFNAME, DEFAULTLNAME,
			SOMEVALUE);
		assert(m.whosOnTheGuestList() == 0 &&
			!m.personOnGuestList(DEFAULTFNAME, DEFAULTLNAME));
	} break; case 59: {
		m.addOrModify(DEFAULTFNAME, DEFAULTLNAME,
			SOMEVALUE);
		assert(m.whosOnTheGuestList() == 1 && has(m,
			DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE));
	} break; case 60: {
		m.addInvitee(DEFAULTFNAME, DEFAULTLNAME, SOMEVALUE);
		m.dropFromGuestList(DEFAULTFNAME, DEFAULTLNAME);
		assert(m.whosOnTheGuestList() == 0 &&
			!m.personOnGuestList(DEFAULTFNAME, DEFAULTLNAME));
	} break; case 61: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m.changeGuestList(m2);
			assert(m.whosOnTheGuestList() == 3);
		}
	} break; case 62: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			// ?Fall 2020 E.Ambrosio
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m.changeGuestList(m2);
			assert(has(m, ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]) && has(m, ARRAYFNAME[2], ARRAYLNAME[2], ARRAYV[2]) &&
				has(m, ARRAYFNAME[3], ARRAYLNAME[3],
					ARRAYV[3]) && !m.personOnGuestList(ARRAYFNAME[0],
						ARRAYLNAME[0]));
		}
	} break; case 63: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m.changeGuestList(m2);
			assert(m2.whosOnTheGuestList() == 2);
		}
	} break; case 64: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m.changeGuestList(m2);
			assert(has(m2, ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]) && has(m2, ARRAYFNAME[1], ARRAYLNAME[1], ARRAYV[1])
				&&
				!m2.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]) && !m2.personOnGuestList(ARRAYFNAME[3],
						ARRAYLNAME[3]));
			// ?Fall 2020 E.Ambrosio
		}
	} break; case 65: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			m.changeGuestList(m2);
			assert(m.whosOnTheGuestList() == 3 &&
				m2.whosOnTheGuestList() == 5);
		}
	} break; case 66: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			assert(m2.whosOnTheGuestList() == 2 &&
				m2.personOnGuestList(ARRAYFNAME[1], ARRAYLNAME[1]) &&
				!m2.personOnGuestList(ARRAYFNAME[2], ARRAYLNAME[3]));
		}
	} break; case 67: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2.dropFromGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]);
			// ?Fall 2020 E.Ambrosio
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.dropFromGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m2.dropFromGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]);
			m2.dropFromGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]);
			m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
		}
		assert(true); // no corruption so bad that destruction failed
	} break; case 68: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			BirthdayParty m3(m2);
			m3.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m3.dropFromGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]);
			m3.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m3.dropFromGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]);
			m3.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m3.dropFromGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]);
			m3.dropFromGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]);
			m3.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
		}
		assert(true); // no corruption so bad that
		//destruction failed
	} break; case 69: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			// ?Fall 2020 E.Ambrosio
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			BirthdayParty m3(m2);
			assert(m3.whosOnTheGuestList() == 3);
		}
	} break; case 70: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		{
			BirthdayParty m2(m);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			assert(m2.whosOnTheGuestList() ==
				m.whosOnTheGuestList() + 1);
		}
	} break; case 71: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		{
			BirthdayParty m2(m);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			assert(m2.whosOnTheGuestList() == 4 &&
				m2.personOnGuestList(ARRAYFNAME[1], ARRAYLNAME[1]) &&
				m2.personOnGuestList(ARRAYFNAME[3], ARRAYLNAME[3]));
		}
	} break; case 72: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		{
			BirthdayParty m2(m);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			// ?Fall 2020 E.Ambrosio
			assert(m2.whosOnTheGuestList() == 4 &&
				m2.personOnGuestList(ARRAYFNAME[1], ARRAYLNAME[1]) &&
				!m2.personOnGuestList(ARRAYFNAME[4], ARRAYLNAME[4]));
		}
	} break; case 73: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			BirthdayParty m3;
			m3.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
			m3.addInvitee(ARRAYFNAME[5], ARRAYLNAME[5],
				ARRAYV[5]);
			m3 = m2;
			assert(m3.whosOnTheGuestList() == 3 &&
				m2.whosOnTheGuestList() == 3);
		}
	} break; case 74: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
			m2 = m;
			m2.addInvitee(ARRAYFNAME[5], ARRAYLNAME[5],
				ARRAYV[5]);
			assert(m2.whosOnTheGuestList() ==
				m.whosOnTheGuestList() + 1);
		}
	} break; case 75: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			// ?Fall 2020 E.Ambrosio
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
			m2.addInvitee(ARRAYFNAME[5], ARRAYLNAME[5],
				ARRAYV[5]);
			m2 = m;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			assert(m2.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
				m2.personOnGuestList(ARRAYFNAME[1],
					ARRAYLNAME[1]) &&
				m2.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]) &&
				!m2.personOnGuestList(ARRAYFNAME[3],
					ARRAYLNAME[3]));
		}
	} break; case 76: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
				ARRAYV[4]);
			m2.addInvitee(ARRAYFNAME[5], ARRAYLNAME[5],
				ARRAYV[5]);
			m2 = m;
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			assert(m.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
				m.personOnGuestList(ARRAYFNAME[1],
					ARRAYLNAME[1]) &&
				!m.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]));
		}
	} break; case 77: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			// ?Fall 2020 E.Ambrosio
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2 = m2;
			assert(m2.whosOnTheGuestList() == 3);
			assert(m2.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
				m2.personOnGuestList(ARRAYFNAME[1],
					ARRAYLNAME[1]) &&
				m2.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]));
		}
		assert(true); // no corruption so bad that
		//destruction failed
	} break; case 78: {
		{
			BirthdayParty m2;
			m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
				ARRAYV[0]);
			m2.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
				ARRAYV[1]);
			m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]);
			m2 = m2;
			m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
				ARRAYV[3]);
			assert(m2.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
				m2.personOnGuestList(ARRAYFNAME[1],
					ARRAYLNAME[1]) &&
				m2.personOnGuestList(ARRAYFNAME[2],
					ARRAYLNAME[2]) &&
				m2.personOnGuestList(ARRAYFNAME[3],
					ARRAYLNAME[3]));
		}
	} break; case 79: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		BirthdayParty m3;
		combineGuestLists(m, m2, m3);
		// ?Fall 2020 E.Ambrosio
		assert(m3.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m3.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m3.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 80: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		BirthdayParty m3;
		combineGuestLists(m2, m, m3);
		assert(m3.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m3.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m3.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 81: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		BirthdayParty m3;
		combineGuestLists(m, m2, m3);
		assert(m3.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m3.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m3.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]) &&
			m3.personOnGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]) &&
			m3.personOnGuestList(ARRAYFNAME[4],
				ARRAYLNAME[4]));
	} break; case 82: {
		// ?Fall 2020 E.Ambrosio
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		BirthdayParty m3;
		assert(combineGuestLists(m, m2, m3));
	} break; case 83: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		BirthdayParty m3;
		m3.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[5]);
		combineGuestLists(m, m2, m3);
		assert(m3.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m3.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m3.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]) &&
			m3.personOnGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]) &&
			m3.personOnGuestList(ARRAYFNAME[4],
				ARRAYLNAME[4]) &&
			has(m3, ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[2]) &&
			!has(m3, ARRAYFNAME[2], ARRAYLNAME[2],
				ARRAYV[5]));
	} break; case 84: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		// ?Fall 2020 E.Ambrosio
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		BirthdayParty m3;
		m3.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[5]);
		assert(combineGuestLists(m, m2, m3));
	} break; case 85: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m3;
		combineGuestLists(m, m2, m3);
		assert(m3.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m3.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m3.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]) &&
			m3.personOnGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]));
	} break; case 86: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		// ?Fall 2020 E.Ambrosio
		BirthdayParty m3;
		assert(combineGuestLists(m, m2, m3));
	} break; case 87: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[4]);
		BirthdayParty m3;
		combineGuestLists(m, m2, m3);
		assert(m3.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m3.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m3.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 88: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[4]);
		BirthdayParty m3;
		assert(!combineGuestLists(m, m2, m3));
	} break; case 89: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		// ?Fall 2020 E.Ambrosio
		m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		combineGuestLists(m, m2, m);
		assert(m.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]) &&
			m.personOnGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]) &&
			m.personOnGuestList(ARRAYFNAME[4],
				ARRAYLNAME[4]));
	} break; case 90: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[3], ARRAYLNAME[3],
			ARRAYV[3]);
		m2.addInvitee(ARRAYFNAME[4], ARRAYLNAME[4],
			ARRAYV[4]);
		combineGuestLists(m, m2, m2);
		assert(m2.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) &&
			m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m2.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]) &&
			m2.personOnGuestList(ARRAYFNAME[3],
				ARRAYLNAME[3]) &&
			m2.personOnGuestList(ARRAYFNAME[4],
				ARRAYLNAME[4]));
	} break; case 91: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		m2.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		// ?Fall 2020 E.Ambrosio
		verifyGuestList(ARRAYFNAME[1], ARRAYLNAME[1], m,
			m2);
		assert(!m2.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) && m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]));
	} break; case 92: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		verifyGuestList(ARRAYFNAME[1], ARRAYLNAME[1], m,
			m2);
		assert(!m2.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) && m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]));
	} break; case 93: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		verifyGuestList(ARRAYFNAME[1], ARRAYLNAME[1], m, m);
		assert(!m.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[0]) && m.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]));
	} break; case 94: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[2]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[1],
			ARRAYV[3]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		verifyGuestList("*", ARRAYLNAME[1], m, m2);
		assert(m2.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[1]) &&
			m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			// ?Fall 2020 E.Ambrosio
			m2.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[1]) &&
			!m2.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
			!m2.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 95: {
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[0],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[2]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[2],
			ARRAYV[3]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		verifyGuestList(ARRAYFNAME[1], "*", m, m2);
		assert(m2.personOnGuestList(ARRAYFNAME[1],
			ARRAYLNAME[0]) &&
			m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[2]) &&
			!m2.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
			!m2.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 96: {
		string all = "*";
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[0],
			ARRAYV[0]);
		m.addInvitee(ARRAYFNAME[0], ARRAYLNAME[1],
			ARRAYV[1]);
		m.addInvitee(ARRAYFNAME[1], ARRAYLNAME[1],
			ARRAYV[2]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[1],
			ARRAYV[3]);
		m.addInvitee(ARRAYFNAME[2], ARRAYLNAME[2],
			ARRAYV[2]);
		BirthdayParty m2;
		verifyGuestList("*", "*", m, m2);
		assert(m2.personOnGuestList(ARRAYFNAME[0],
			ARRAYLNAME[1]) &&
			m2.personOnGuestList(ARRAYFNAME[1],
				ARRAYLNAME[1]) &&
			// ?Fall 2020 E.Ambrosio
			m2.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[1]) &&
			m2.personOnGuestList(ARRAYFNAME[0],
				ARRAYLNAME[0]) &&
			m2.personOnGuestList(ARRAYFNAME[2],
				ARRAYLNAME[2]));
	} break; case 97: {
		BirthdayParty m2 = m;
		BirthdayParty m3;
		verifyGuestList("*", "*", m2, m3);
		assert(m3.whosOnTheGuestList() ==
			m.whosOnTheGuestList());
	} break; case 98: {
		BirthdayParty m2;
		BirthdayParty m3(m);
		verifyGuestList("*", "*", m2, m3);
		assert(m3.noInvitees());
	} break; case 99: {
		BirthdayParty m2;
		verifyGuestList("*", "*", m2, m2);
		assert(m2.whosOnTheGuestList() == 0);
	} break; case 100: {
		const int NITEMS = 2000;
		for (int k = 0; k < NITEMS; k++)
			assert(m.addInvitee(std::to_string(k),
				std::to_string(k), SOMEVALUE));
		assert(m.whosOnTheGuestList() == NITEMS);
	}
	}
}
int main()
{
	while (true)
	{
		cout << "Enter test number: ";
		int n;
		cin >> n;
		testone(n);
		cout << "Passed" << endl;
	}

}
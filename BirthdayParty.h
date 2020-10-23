#ifndef BIRTHDAYPARTY_H
#define BIRTHDAYPARTY_H
#include <string>
#include <iostream>
typedef std::string BirthdayType;

struct Bucket
{
	std::string firstName;
	std::string lastName;
	BirthdayType type;
	Bucket *next;
};
class BirthdayParty
{
private:
	bool isEmpty;
	int slots = 26;
	Bucket list[26];

public:
	BirthdayParty(); // Create an empty BirthdayParty list
	BirthdayParty (const BirthdayParty& other); //copy constructor
	~BirthdayParty(); //destructor 
	int hash(std::string first, std::string last) const;//hash function
	bool noInvitees() const; // Return true if the BirthdayParty list
							 // is empty, otherwise false.
	
	int whosOnTheGuestList() const; // Return the number of players
									// the BirthdayParty list.
	int stringCompare(const std::string compare, const std::string to); //compare 2 name buckets return int to indicate alphabetical order

	std::string makeLower(std::string s); // use in string compare to make all lowercase

	const BirthdayParty& operator=(const BirthdayParty& rhs);//assignment operator

	bool addInvitee(const std::string& firstName, const std::string&lastName, const BirthdayType& value);
	// If the full name (both the first and last name) is not equal
	// to any full name currently in the list then add it and return
	// true. Elements should be added according to their last name.
	// Elements with the same last name should be added according to
	// their first names. Otherwise, make no change to the list and
	// return false (indicating that the name is already in the
	// list).

	bool modifyInvitee(const std::string& firstName, const std::string& lastName, const BirthdayType& value);
	// If the full name is equal to a full name currently in the
	// list, then make that full name no longer map to the value it
	// currently maps to, but instead map to the value of the third
	// parameter; return true in this case. Otherwise, make no
	// change to the list and return false.

	bool addOrModify(const std::string& firstName, const std::string&lastName, const BirthdayType& value);
	// If full name is equal to a name currently in the list, then
	// make that full name no longer map to the value it currently
	// maps to, but instead map to the value of the third parameter;
	// return true in this case. If the full name is not equal to
	// any full name currently in the list then add it and return
	// true. In fact, this function always returns true.

	bool dropFromGuestList(const std::string& firstName, const std::string& lastName);
	// If the full name is equal to a full name currently in the
	// list, remove the full name and value from the list and return
	// true. Otherwise, make no change to the list and return
	// false.

	bool personOnGuestList(const std::string& firstName, const std::string& lastName) const;
	// Return true if the full name is equal to a full name
	// currently in the list, otherwise false.

	bool checkGuestList(const std::string& firstName, const std::string& lastName, BirthdayType& value) const;
	// If the full name is equal to a full name currently in the
	// list, set value to the value in the list that that full name
	// maps to, and return true. Otherwise, make no change to the
	// value parameter of this function and return false.

	bool selectInvitee(int i, std::string& firstName, std::string& lastName, BirthdayType& value) const;
	// If 0 <= i < size(), copy into firstName, lastName and value
	// parameters the corresponding information of the element at
	// position i in the list and return true. Otherwise, leave the
	// parameters unchanged and return false. (See below for details
	// about this function.)
	void changeGuestList(BirthdayParty& other);
	// Exchange the contents of this list with the other one.

	bool GetBirthdayType(const std::string& firstName, const std::string&lastName, BirthdayType& value) const;
	//update value with BirthdayType of atendee. return true if successful


	//copy constructor
};

bool combineGuestLists(const BirthdayParty & bpOne,
	const BirthdayParty & bpTwo,
	BirthdayParty & bpJoined);

void verifyGuestList(const std::string& fsearch,
	const std::string& lsearch,
	const BirthdayParty& bpOne,
	BirthdayParty& bpResult);

#endif

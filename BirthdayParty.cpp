#include "BirthdayParty.h"
#include <iostream>
#include <string>

BirthdayParty::BirthdayParty(int n) // Create an empty BirthdayParty list
{
	list = new Bucket[n];
	isEmpty = true;
	slots = n;
	for (int i = 0; i < n; i++)
	{
		list[i].next = nullptr;
	}
}

BirthdayParty::~BirthdayParty()//destructor 
{
	for (int i = 0; i < slots; i++)
	{
		if (list[i].next != nullptr)
		{
			delete list[i].next;
		}
	}
}

int BirthdayParty::hash(std::string first, std::string last)//hash function
{
	int key=0;
	std::string s = first + last;
	
	for (int i = 0; i < int(s.length()); i++)
	{
		key += int (s[i]);
	}
	key = key % slots;

	return key;
}

bool BirthdayParty::noInvitees() const
{

	for (int i = 0; i < slots; i++)
	{
		if (list[i].next != nullptr) return false;
	}
	return true;
}

bool BirthdayParty::addInvitee(const std::string& firstName, const std::string& lastName, const BirthdayType& value)
{
	int key = hash(firstName, lastName);//hash name to get key
	Bucket* inspect = list[key].next;
	Bucket* add = new Bucket;
	add->firstName = firstName;
	add->lastName = lastName;
	add->type = value;
	add->next = nullptr;
	//check if the bucket is empty
	if (inspect == nullptr) //means the slot is empty
	{
		list[key].next = add; // point to new entry 
		return true;
	}
	else //traverse list looking for end or match
	{
		while (inspect != nullptr)
		{
			if (inspect->firstName == firstName && inspect->lastName == lastName)
			{
				delete add;
				return false;
			}
			else if (inspect->next == nullptr)
			{
				inspect->next = add; //reached the end of the linked list without finding a match. Add name then return true
				return true;
			}
			inspect = inspect->next;
		}
		
	}
	return false;
}

int BirthdayParty::stringCompare(const std::string compare, std::string to) //compare 2 strings return 1 if compare comes first, 2 if to comes first, and 0 if theyre the same
{
	//convertcase

	//check for same 
	
	//find which string is longest
	return 0;
}
std::string BirthdayParty::makeLower(std::string s)
{
	for (int i = 0; i < int(s.length()); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}
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
			if (makeLower(inspect->firstName) == makeLower(firstName) && makeLower(inspect->lastName) == makeLower(lastName))
			{
				delete add;
				return false;
			}
			else if (stringCompare(inspect->lastName, add->lastName) == 1 )//add goes before inspect bucket based on last name
			{
				//do the add
				return true;
			}
			else if ((stringCompare(inspect->lastName, add->lastName) == 0) && (stringCompare(inspect->firstName, add->firstName) == 1)) // last names are the same so check firstnames
			{
				//add goes before insepct based on first name
			
					//do the add
					return true;
			
			}
			else if (inspect->next == nullptr) //hit the end of the linked list for this slot and found no bucket that add should go before
			{
				inspect->next = add; //reached the end of the linked list without finding a match. Add name then return true
				return true;
			}
			inspect = inspect->next;
		}
		
	}
	return false;
}

//This function takes 2 string arguements and compares them alphabetically. Retrun 0 it theyre the same, Return 1 if compare comes first, Return 2 if to comes first
int BirthdayParty::stringCompare(const std::string compare, std::string to) //compare 2 strings return 1 if compare comes first, 2 if to comes first, and 0 if theyre the same
{
	//convertcase
	std::string s1 = makeLower(compare);
	std::string s2 = makeLower(to);
	//check for same 
	if (s1.compare(s2) == 0) return 0;//return 0 if the strings are the same
	//find which string is longest
	if (int(s1.length()) > int(s2.length())) //if compare string is longer use length of to string as iterator
	{
		for (int i = 0; i < int(s2.length()); i++)
		{
			if (int(s1[i]) < int(s2[i])) return 1; //if 'i' char in compare is lo wer than 'i' char in to then compare comes first(return 1)
			else if (int(s1[i]) > int(s2[i])) return 2;// if 'i' char in compare is higher than 'i' char in to then to comes first (return 2)
			// it the chars are the same then continue
		}
		//iterated through all of the shorter word and all chars were the same, so the longer word (s1) comes second
		return 2; 
	}
	else// s2 is longer than or equal to so use s1 length as iterator end
	{
		for (int i = 0; i < int(s1.length()); i++)
		{
			if (int(s1[i]) < int(s2[i])) return 1; //if 'i' char in compare is lower than 'i' char in to then compare comes first(return 1)
			else if (int(s1[i]) > int(s2[i])) return 2;// if 'i' char in compare is higher than 'i' char in to then to comes first (return 2)
			// it the chars are the same then continue
		}
		//iterated through all of the shorter word and all chars were the same, so the longer word (s1) comes second
		return 1;
	}
	return 7; //we should never get here. if we did, something is broken;
}
std::string BirthdayParty::makeLower(std::string s)
{
	for (int i = 0; i < int(s.length()); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}//take string and return string in all lowercase
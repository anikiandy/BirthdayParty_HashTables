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
	
	for (int i = 0; i < 5; i++)
	{
		key += int (s[i]);
	}
	key = key % slots;

	return key;
}
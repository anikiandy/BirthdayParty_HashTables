#include "BirthdayParty.h"
#include <iostream>
#include <string>

BirthdayParty::BirthdayParty() // Create an empty BirthdayParty list
{
	isEmpty = true;
	for (int i = 0; i < slots; i++)
	{
		list[i].next = nullptr;
	}
}

BirthdayParty::~BirthdayParty()//destructor 
{
	Bucket *del, *mark;
	for (int i = 0; i < slots; i++) //traverse slots looking for occupied slots
	{
		if (list[i].next != nullptr)
		{
			mark = list[i].next;
			del = mark;
			list->next = nullptr; //point slot to 
			while (mark != nullptr)
			{
				mark = mark->next;
				delete del;
				del = mark;
				std::cout << " deleted something \n";
				
			}//delete all buckets in this slot
		}
	}
}

int BirthdayParty::hash(std::string first, std::string last) const//hash by first letter of last name
{
	int key = tolower(last[0]) - 97;
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
	Bucket* inspect = list[key].next; //point inspect pointer to the correct slot
	Bucket* trailing;//trail inspect pointer
	Bucket* add = new Bucket; //make new invitee
	add->firstName = firstName;
	add->lastName = lastName;
	add->type = value;
	add->next = nullptr;

	//check if the first bucket is empty
	if (inspect == nullptr) //means the slot is empty
	{
		list[key].next = add; // point to new entry 
		return true;
	}
	else if (stringCompare(makeLower(add->lastName), makeLower(inspect->lastName)) == 1)//if add goes before first node
	{
		add->next = inspect;
		list[key].next = add;
	}
	else if (makeLower(inspect->firstName) == makeLower(firstName) && makeLower(inspect->lastName) == makeLower(lastName)) //if it is the same as the first node
	{
		delete add;
		return false;
	}
	else //advance inspection and point trailing pointer to previous node
	{
		trailing = inspect;
		inspect = inspect->next;
		while (inspect != nullptr)//traverse linked list
		{
			if (makeLower(inspect->firstName) == makeLower(firstName) && makeLower(inspect->lastName) == makeLower(lastName)) //if find exact match delete add
			{
				delete add;
				return false;
			}
			
			else if (stringCompare(makeLower(inspect->lastName), makeLower(add->lastName)) == 1)//add goes before inspect bucket based on last name
			{
				add->next = inspect;
				trailing->next = add;
				return true;
			}
			else if ((stringCompare(makeLower(inspect->lastName), makeLower(add->lastName)) == 0) && (stringCompare(makeLower(inspect->firstName), makeLower(add->firstName)) == 1)) // last names are the same so check firstnames
			{
				add->next = inspect;
				trailing->next = add;
				std::cout << "firstname thing";
				return true;
			
			}
			trailing = inspect;
			inspect = inspect->next;
		}
		//got through while loop without finding an entry which comes after add alphabetically. inspect is on nullptr so point trailing to add
		trailing->next = add; 
		return true;
		
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

int BirthdayParty::whosOnTheGuestList() const // Return the number of players
{
	int count = 0;
	Bucket *marker;
	for (int i = 0; i < slots; i++)
	{
		if (list[i].next != nullptr)
		{
			marker = list[i].next;
			while (marker != nullptr)
			{
				count++;
				marker = marker->next;
			}
		}
	}
	return count;

}

//This function is a terrigble use of a hash table... start from the top of the has table array and iterate down until you reach ith 
bool BirthdayParty::selectInvitee(int i, std::string& firstName, std::string& lastName, BirthdayType& value) const
{
	
	int counter = 0;
	Bucket *inspect;
	for (int j = 0; j < slots; j++)
	{
		if (list[j].next != nullptr)//something is in the slot 
		{
			inspect = list[j].next; 
			//iterate down the linked list increasing counter
			while (inspect != nullptr)
			{ 
				if (counter == i)
				{
					firstName = inspect->firstName;
					lastName = inspect->lastName;
					value = inspect->type;
					return true;
				}
				else
				{
					counter++;
					inspect = inspect->next;
				}
			}
		}
	}
	return false; //counter never reaches i (i > list size) so return false
}

bool BirthdayParty::modifyInvitee(const std::string& firstName, const std::string& lastName, const BirthdayType& value)
{
	int key = hash(firstName, lastName);
	Bucket *inspect;
	inspect = list[key].next;

	while (inspect != nullptr)
	{
		if (inspect->lastName == lastName && inspect->firstName == firstName)
		{
			inspect->type = value;
			return true;
		}
		inspect = inspect->next;
	}

	return false; //unable to find match return false
}

bool BirthdayParty::dropFromGuestList(const std::string& firstName, const std::string& lastName)
{
	int key = hash(firstName, lastName);
	Bucket *del, *trailing;
	del = list[key].next;
	trailing = del;
	while (del != nullptr)
	{
		if (del->firstName == firstName && del->lastName == lastName)
		{
			if (list[key].next == del)//found name in first node in slot 
			{
				list[key].next = del->next;
				delete del;
				return true;
			}
			trailing = del->next;//point trailing over del and delete del
			delete del;
			return true;
		}
		trailing = del;//advance pointers
		del = del->next;
	}
	return false;//hit end of linked list without match
}

bool BirthdayParty::personOnGuestList(const std::string& firstName, const std::string& lastName) const
{
	int key = hash(firstName, lastName);
	Bucket *inspect = list[key].next;

	while (inspect != nullptr)
	{
		if (inspect->firstName == firstName && inspect->lastName == lastName)
		{
			return true;
		}
		inspect = inspect->next;
	}
	return false;
}
// Return true if the full name is equal to a full name
// currently in the list, otherwise false.

bool BirthdayParty::addOrModify(const std::string& firstName, const std::string&lastName, const BirthdayType& value)
{
	if (personOnGuestList(firstName, lastName))
	{
		modifyInvitee(firstName, lastName, value);
	}
	else
		addInvitee(firstName, lastName, value);

	return true;
}

bool BirthdayParty::checkGuestList(const std::string& firstName, const std::string& lastName, BirthdayType& value) const
{
	if (personOnGuestList(firstName, lastName))
	{
		value = "p";
		return true;
	}
	else return false;
}
// CPSC 2150, Assignment #4, Fall 2017
// Gladys Monagan
#include "SList.h"
#include <cassert>
#include <iostream>
#include <ctime>


//UNITTEST HAS ISSUE AS WHETHER A VALUE GOES ON LEVEL 2 IS RANDOM (WITH PROBABILITY COEFFICIENT P)
//HOWEVER, UNITTEST HAS SET VALUES THAT IT EXPECTS THE PRGORAM TO PRINT WHICH NOT POSSIBLE WHEN PROBABILITY IS INVOLVED.

// to have debugging output and asserts, comment out the following statement
#define NDEBUG

#ifndef NDEBUG
using std::cerr;
#endif

const float PROB = 0.5;
srand(time(NULL));

//
SList::SList()
{
	DEREF_COUNT = 0;
	head_LEVEL_BASE = head_LEVEL2 = nullptr;
	outputTopList = false;
	delimiter = DEFAULT_DELIMITER;
}

//_______________________________________

//insertAt() function is only used to insert a Node regardless of level either between 2 nodes or at the beginning/end of the list. As we handle the levels on the main insert function.
SNode* SList::insertAt(int x, SNode* node)
{
	SNode* temp = new SNode{nullptr, nullptr, x};
	if (node == nullptr)
	{
		temp->next = head_LEVEL2;
		temp->nextlevel = new SNode{head_LEVEL_BASE, nullptr, x};
		head_LEVEL2 = temp;
		head_LEVEL_BASE = temp->nextlevel;
	}
	else
	{
		temp->next = node->next;
		node->next = temp;

	}
	//add 3 as in both if blocks we do 3 dereference operations
	DEREF_COUNT += 3;
	return temp;
}

void SList::insert(int x)
{
	if (head_LEVEL_BASE == nullptr)
	{
		head_LEVEL_BASE = new SNode{nullptr, nullptr, x};
		head_LEVEL2 = new SNode{nullptr, head_LEVEL_BASE, x};
		return;
	}
	bool ifLevelUp = rand() < (RAND_MAX() * PROB);
	SNode* temp;
	SNode* currentNode = x < head_LEVEL2->x ? nullptr : head_LEVEL2;
	DEREF_COUNT++;
	
	//iterate through level 2
	//Using comma operator to accurately count dereference operation
	while (currentNode != nullptr && (++DEREF_COUNT, currentNode->next != nullptr) && (++DEREF_COUNT, x > currentNode->next->x))
	{
		currentNode = currentNode->next;
		++DEREF_COUNT;
	}
	//create node that will be added to level 2
	if (ifLevelUp || currentNode == nullptr)
	{
		temp = insertAt(x, currentNode);

		if (currentNode == nullptr)
		{
			return;
		}
	}
	currentNode = currentNode->nextlevel;
	++DEREF_COUNT;

	//iterate through base level
	//Using comma operator again to accurately count dereference operation
	while (currentNode != nullptr && (++DEREF_COUNT, currentNode->next != nullptr) && (++DEREF_COUNT, x > currentNode->next->x))
	{
		currentNode = currentNode->next;
		++DEREF_COUNT;
	}
	if (ifLevelUp)
	{
		temp->nextlevel = insertAt(x, currentNode);
		++DEREF_COUNT;
	}
	else
	{
		//since we don't need to set nextlevel (as we are only in base list at this point), return pointer can be discarded and function call is casted as void.
		static_cast<void>(insertAt(x, currentNode));
	}
}

//_______________________________________

int SList::getMoves() const
{
	return DEREF_COUNT;
}

//_______________________________________

// returns whether x is in the skip list(s) or not
// counts and returns the number of comparisons done in the search
bool SList::search(int x, int& comparisons)
{
	if (head_LEVEL_BASE == nullptr)
		return false;

	//search through level2 to fasten the search operation
	currentNode = head_LEVEL2;
	while (currentNode->next != nullptr && (++comparisons, x > currentNode->next->x))
	{
		currentNode = currentNode->next;
	}
	if (++comparisons, x == currentNode->x)
		return true;

	//go down 1 level to base level and search linearly through the list
	currentNode = currentNode->nextlevel;
	while (currentNode->next != nullptr && (++comparisons, x > currentNode->next->x))
	{
		currentNode = currentNode->next;
	}
	if (++comparisons, x == currentNode->x)
		return true;
	
	return false;
}

//_______________________________________

// used for debugging purposes, we are counting  how many elements were inserted
// the user could have done this if s/he had kept track of the insertions
int SList::numberOfElements() const
{
	if (head_LEVEL_BASE == nullptr)
		return 0;
	int count = 1;
	SNode* temp = head_LEVEL_BASE;
	while (temp->next != nullptr)
	{
		++count;
		temp = temp->next;
		DEREF_COUNT += 2;
	}
	++DEREF_COUNT;
	return count;
}

//_______________________________________

// free up the nodes properly and initialize everything
void SList::reset()
{
	SNode* temp = head_LEVEL_BASE;
	SNode* temp2 = head_LEVEL_BASE->next;
	while (temp->next != nullptr)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	delete temp;
	temp = head_LEVEL2;
	temp2 = head_LEVEL2->next;
	while (temp->next != nullptr)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	delete temp;
	head_LEVEL2 = head_LEVEL_BASE = nullptr;
	DEREF_COUNT = 0;
}

//_______________________________________

// copy constructor ... do a shallow copying of the instance variables
// and do a deep copy
SList::SList(const SList& s)
{
	head_LEVEL2 = head_LEVEL_BASE = nullptr;
	(*this) = s;
}

//_______________________________________

SList& SList::operator = (const SList &rhs)
{
	if (this != &rhs)
	{
		this->reset();
		delimiter = rhs.delimiter;
		DEREF_COUNT = rhs.DEREF_COUNT;
		//ITERATE AND DEEP COPY EVERYTHING
	}
	return (*this);
}

//_______________________________________

// destructor
SList::~SList()
{
	reset();
}

//_______________________________________

// print the top list if sList.getTopListOutput() is true, otherwise
// linearly print every element (the bottom list)
std::ostream& operator << (std::ostream& out, const SList& sList)
{
	if (sList.getTopListOutput())
	{
		SNode* temp = head_LEVEL2;
		while (temp != nullptr)
		{
			out << temp->x << delimiter;
			temp = temp->next;
		}
	}
	else
	{
		SNode* temp = head_LEVEL_BASE;
		while (temp != nullptr)
		{
			out << temp->x << delimiter;
			temp = temp->next;
		}
	}
	return out;
}

//_______________________________________

// for pretty printing .... totally unexciting
void SList::setOutDelimeter(std::string str)
{
	delimiter = str;
}
//_______________________________________

// for pretty printing .... totally unexciting
std::string SList::getOutDelimeter() const
{
	return delimiter;
}

//_______________________________________

void SList::setTopListOutput(bool topListDumping)
{
	outputTopList = topListDumping;
}

//_______________________________________

bool SList::getTopListOutput() const
{
	return outputTopList;
}

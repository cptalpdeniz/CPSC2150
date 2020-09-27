/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #2, CPSC 2150 (expand code started by Gladys Monagan)

NOTE:
* Self explanatory variables and parameters will not be documented as they are, "self-explanatory".
*/

#include "LList.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;

const string LList::DELIMITER = string(" ");

// -22 since it represents EINVAL as invalid_argument
const int LList::NOT_DEFINED = -22;

// ASSIGNMENT requirement:
// initialize NOT_DEFINED [DONE]

// constructor with no arguments, makes an empty list
// code can be modified below if you choose to have a dummy head node
LList::LList()
{
	this->head = nullptr;  
}

bool LList::isEmpty() const
{
	return (head == nullptr);
}

void LList::cons(int x)
{
	this->head = new Node{x, this->head};
}

//_______________________________________

void LList::append(Node* n, int x)
{
	if (n->link == nullptr)
	{
		n->link = new Node{x, nullptr};
		return;
	}
	append(n->link, x);
	
}

void LList::append(int x)
{
	if (isEmpty())
	{
		head = new Node{x, nullptr};
		return;
	}
	append(head, x);
}

//_______________________________________

// make a string from the values of the list in this->head and return it
// precondition:
//   LList::DELIMETER has been initialized
// postcondition:
//    return a string of the form 
//          [ DELIMITER element DELIMITER ... element DELIMITER ]
// code needs to be modified if you choose to have a dummy head node
string LList::toString() const {
	string str = "[";
	str += toString(this->head, DELIMITER);
	str += "]";
	return str;
}

// make a string from the elements in p using the delimiter to separated the elements
// postcondition:
//    return a string of the form 
//         [ delimiter element ... element delimiter element delimiter ]
string LList::toString(Node * p, string delimiter) {
	if (p == nullptr) {
		return delimiter;
	}
	std::stringstream ss;
	ss << delimiter;
	ss << p->item;
	ss << toString(p->link, delimiter);
	return ss.str();
}

//_______________________________________

/*
* Add 1 per number of nodes recursively
* return 0 if at the end of the list;
*/
int LList::length(Node* n)
{ 
	return ((n == nullptr) ? 0 : (1 + length(n->link)));
}

int LList::length() const
{
	return length(head);
}

//_______________________________________

/*
* do bool short-circuit evaluation to check if we are at last node
* return true if item found else call with address of link node to search 
* the link recursively.
*/ 
bool LList::search(Node* n, int x)
{
	return (n != nullptr && (n->item == x || search(n->link, x)));
}

bool LList::search(int x) const
{
	return search(head, x);
}

//_______________________________________

int LList::first() const
{
	if (head == nullptr)
		return LList::NOT_DEFINED;
	else 
		return head->item;
}

//_______________________________________

/*
* finds the last node by doing ternary operation in a recursive call
* returns the last node in the list
* precondition:list is not empty
* returning node* to use if for splice
*/
LList::Node* LList::last(Node* n)
{
	return (n->link == nullptr ? n : last(n->link));
}

int LList::last() const 
{
	if (head == nullptr)
		return LList::NOT_DEFINED;
	return last(head)->item;
}

//_______________________________________

/*
* Check if we are at the last node, if yes return false
* find the element, then do remove operation. Take node out of the the list
* without losing adresses, then remove the node that contains X
*/
bool LList::remove(Node* n, const int x)
{
	if (n->link == nullptr)
		return false;
	if (n->link->item == x)
	{
		Node* tempN = n->link;
		n->link = n->link->link;
		tempN->link = nullptr;
		deleteList(tempN);
		return true;
	}
	return remove(n->link, x);
}

bool LList::remove(int x)
{
	if (head->item == x)
	{
		Node* tempN = head;
		head = head->link;
		delete tempN;
		return true;
	}
	return remove(head, x);
}

//_______________________________________

/*
* if the link of the current node is nullptr, that means we are at the end of the list
* which is our base, return the current node pointer
* the method reverse(Node*) works by getting the next node (by recursive call), setting it to temporary variable (tempN), then setting the tempN's link
* attribute to n (the current node). After that, we set n's link to nullptr as n will become tempN on the
* previous recursive call.
*/
LList::Node* LList::reverse(Node* n)
{
	if (n->link == nullptr)
		return n;
	Node* tempN = reverse(n->link); 
	tempN->link = n; 
	n->link = nullptr; 
	return n;
}

void LList::reverse()
{
	if (isEmpty())
		return;
	Node* lastNode = last(head);
	static_cast<void>(reverse(head));
	head = lastNode;
}

//_______________________________________

/*
* exit method call if other.length is zero (which means other list is empty and there's nothing to copy)
* if given pos is zero or this list is empty, places it in the beginning
* else if pos provided is greater or equal to this.length() then add to end
* if pos is in the middle, iterate the pointer to pos-1, do necessary operations to set the pos-1 link to other
* head then set the other's last->link to pos in original list
* After all the operations are complete, set the other.head to nullptr
*/
void LList::splice(LList& other, int pos)
{
	if (! other.length())
		return;
	Node* temp = head;
	if (pos == 0 || isEmpty())
	{
		head = other.head;
		other.last(other.head)->link = temp;
	}
	else if (pos >= length())
	{
		last(head)->link = other.head;
	}
	else
	{
		for (; pos > 1; --pos)
		{
			temp = temp->link;
		}
		other.last(other.head)->link = temp->link;
		temp->link = other.head;
	}
	other.head = nullptr;
}

//_______________________________________

/*
* Overloaded recursive function (useless) to check if left side and right side
* of equal to (==) operator are equal to each other
*/
bool LList::equalsOverload(Node* lHead, Node* rHead)
{
	if (lHead->item != rHead->item)
		return false;
	if (lHead->link == nullptr && rHead->link == nullptr)
		return true;
	return equalsOverload(lHead->link, rHead->link);
}

bool operator==(const LList& lfSide, const LList& rtSide)
{
	//if one of lists are empty return false and short-circuit the evaluation
	//if not, check for sizes
	if ((lfSide.isEmpty() ^ rtSide.isEmpty()) || lfSide.length() != rtSide.length())
		return false;
	return LList::equalsOverload(lfSide.head, rtSide.head);
}

//_______________________________________

/*
* How it works? Magic.
*/

bool operator!=(const LList& lfSide, const LList& rtSide)
{
	return !(lfSide == rtSide);
}

//_______________________________________

//Copy Constructor
LList::LList(const LList& l)
{
	head =nullptr;
	(*this) = l; 
}

//_______________________________________

//Overloaded Assignment Operator
LList& LList::operator=(const LList& l)
{
	if (head != nullptr)
		deleteList(head);
	head = copyList(l.head);
	return (*this);
}

//_______________________________________


void LList::deleteList(Node* n)
{
	if (n->link != nullptr)
		deleteList(n->link);
	delete n;
}

LList::Node* LList::copyList(const Node* n)
{
	if (n == nullptr)
		return nullptr;
	Node* tempN = new Node{ n->item, copyList(n->link)};
	return tempN;
}

// destructor
// ASSIGNMENT requirement:
// finish the comment on postcondition:
// postcondition: 
LList::~LList()
{
	if (head != nullptr)
		deleteList(head);
}

#ifndef SLIST_H
#define SLIST_H
// Build  a skip list
// CPSC 2150, Assignment #4, October 2020 Gladys Monagan
// Name: 

#include <string>
#include <iostream>

/*
* A skip list that keeps the values in ascending order.
* It supports insertion into the skip list but no deletion.
*/

struct SNode
{
	SNode* next;
	SNode* nextlevel;
	int data;	
};

class SList 
{
	public:
	// create an empty list
	// initializes the number of pointer dereferences or moves to 0
	SList();
	
	// insert an element in ascending order
	// postcondition: 
	// x is added to the skip list (the bottom list and possibly the top list)
	// the number of moves done in 'insert' is added to the number of moves so far
	// 
	// Note: to get the number of moves, i.e. the pointer dereferences,
	// including the ones needed to adjust the pointers of the top list, 
	// call getMoves()
	void insert(int x);

	// returns the TOTAL number of moves done so far when  
	// inserting all the elements into the skip list
	//
	// the skip list is sorted in ascending order and the number of
	// moves increases continuously -- it is never reset (unless reset is called)
	//
	// the total number of moves depends on the number of calls 
	// to the function insert and on how the top list is built and
	// the pointers adjusted 
	int getMoves() const;

	// return true if x is found in the list, false otherwise
	// postcondition: the number of comparisons done in this particular
	// call to search is returned in comparisons
	bool search(int x, int& comparisons);
     
	// return the number of elements in the skip list 
	int numberOfElements() const;
	
	// delete/deallocate the skip list and reset to the initial state
	void reset();
	
	// overloaded assignment operator      
	SList& operator = (const SList&);
	
	// copy constructor
	SList(const SList&); 
	
	// destructor
	~SList();

	// output all the elements of the list in ascending order
	// there is a delimiter output after each element
	// 
	// if setTopListOutput(true) is called previously,
	// the elements of the top list are output
	// if setTopListOutput(false) is called previously,
	// the elements of the bottom list are output
	friend std::ostream& operator<< (std::ostream&, const SList&);

	// default delimiter value: a string that separates the elements in the output
	const std::string DEFAULT_DELIMITER = "  ";

	// delimiter used to separate the elements when the operator << is used
	// the initial value of delimiter is DEFAULT_DELIMITER
	void setOutDelimeter(std::string delimiter);

	// for pretty printing .... totally unexciting
	std::string getOutDelimeter() const;

	// when outputting with the operator << output all the elements
	// (bottom list) unless setTopListOutput is called with a false argument
	// 
	// postcondition:
	//    after setTopListOutput(true), the top list will be output with <<
	//    after setTopListOutput(false), all the elements are output with <<
	void setTopListOutput(bool topListDumping);

	// return true if the top list should be printed with <<
	// otherwise return false meaning that all the elements will be printed with <<
	bool getTopListOutput() const;
	     
	private:
	// used to separate elements in the output
	std::string delimiter;

	// determines whether the top list will be output with the operator << 
	bool outputTopList;
	SNode* head_LEVEL_BASE;
	SNode* head_LEVEL2;
	int DEREF_COUNT;
	SNode* insertAt(int, SNode*);

};
#endif  // SLIST_H
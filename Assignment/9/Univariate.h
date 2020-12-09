/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #9, CPSC 2150

NOTE:
Self explanatory variables and parameters will not be documented as they are, "self-explanatory".

*/

// Represents a univariate polynomial with a binary search tree
// Course: CPSC 2150
#ifndef UNIVARIATE_H
#define UNIVARIATE_H

#include <iostream>    // std::ostream
#include <functional>  // std::function
#include "Term.h"

class Univariate
{

public:
	// create the zero polynomial 
	// and set the comparison function cmp between 2 term degrees
	Univariate(std::function<bool(int, int)> cmp);

	// create a monomial with one term c x^d 
	// and set the comparison function between 2 term degrees
	Univariate(int c, int d, std::function<bool(int, int)> cmp);

	// return the highest degree of the polynomial
	// in the special case of the zero polynomial return -1
	int degree() const;

	// return the coefficient of term that has degree n
	int coefficient(int n) const;

	// evaluate the polynomial with the given value of x
	double evaluate(double x) const; 

	// determine if the polynomial is the zero polynomial
	bool isZeroPolynomial() const;

	// insert an already created term into the polynomial
	// precondition: t is not the nullptr
	void insert(Term* t);

	// return the number of terms in the polynomial:
	// for the zero polynomial return 1
	int numberOfTerms() const;

	// add (sum) two polynomials
	const Univariate operator + (const Univariate& b); 

	// differentiate a and return a new polynomial
	const Univariate differentiate() const; 

	// copy constructor
	Univariate(const Univariate&);

	// destructor
	~Univariate();

	// overloaded assignment operator
	Univariate& operator = (const Univariate&); 

	// output the polynomial nicely in x
	friend std::ostream& operator << (std::ostream&, const Univariate&);

	// first read the number of terms n (as an int) 
	// followed by the pairs of coefficient and degree 
	// for each of the n terms
	friend std::istream& operator >> (std::istream&, Univariate&);


private:
	// a Node that is used to represent a polynomial stored as a 
	// BST. Each Node stores the pointer of a term and the links to its 
	// children.
	// Terms are stored in the tree in the order depending on cmpFct order, 
	// ideally, the terms in the right branch always have higher degrees 
	// than the node, while the terms in the left branch always 
	// have lower degrees than the node.
	// 
	// Note:
	//     No duplicate terms with the same degree will be in the tree.
	
	// You can make the Node a class of its own if you prefer
	struct Node {
		Node *left;
		Term *term;
		Node *right;
	};

	void deleteTree(Node*);
	void deleteNode(Node*);
	void insertHelper(Node*, Univariate &) const;
	void differentiateHelper(Node*, Univariate &) const;
	double evaluateHelper(Node*, double) const;
	static void print(std::ostream &, Node*);
	Node* search(Node*, int,bool) const;

	// the BST is always sorted and never has duplicates
	std::function<bool(int,int)> cmpFct;
	Node* head;
	int highestDegree;
	int numOfTerms;
};
#endif


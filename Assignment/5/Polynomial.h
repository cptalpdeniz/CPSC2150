#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H 

#include "Term.h"
#include <iostream>

struct Node
{
	Term* term;
	Node* next;
};

class Polynomial
{
public:
	Polynomial();
	~Polynomial();
	Polynomial(Node* n, int i) : head(n), numOfTerms(i) {};

	Polynomial&	operator=(const Polynomial &);
	Polynomial(const Polynomial &);

	void insert(const Term);
	void sort(); //this is cancer
	friend std::ostream& operator<<(std::ostream&, const Polynomial &);
	Polynomial operator+(Polynomial const &) const;
	Polynomial operator*(Polynomial const &) const;
	int getNumOfTerms() { return numOfTerms; }
	Polynomial diff(bool) const;

private:
	Node* head;
	int numOfTerms;
	static void split(Node*, Node* &, Node* &);
	static Node* sortHelper(Node*); //this is cancer
	static Node* mergeList(Node*, Node*);
};
#endif
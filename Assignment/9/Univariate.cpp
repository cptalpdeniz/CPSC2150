/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #9, CPSC 2150

NOTE:
Self explanatory variables and parameters will not be documented as they are, "self-explanatory".

*/


// Represents a univariate polynomial with a binary search tree
// Course: CPSC 2150

#include <iostream>
#include <functional>   // std::function
#include <cmath>		// std::pow;

#include "Term.h"
#include "Univariate.h"

using std::pow;


// create the zero polynomial 
Univariate::Univariate(std::function<bool(int, int)> fct)  
{   
	cmpFct = fct;
	head = nullptr;
	highestDegree = -1;
	numOfTerms = 0;
}

// precondition:
//    c is the coefficient of the only term in the polynomial
//    d is the degree of the only term in the polynomial
// postcondition: 
//    a Univariate with one term c x^d is created
Univariate::Univariate(int c, int d, std::function<bool(int, int)> fct) 
{
	cmpFct = fct;
	head = new Node{nullptr, new Term(c, d), nullptr};
	highestDegree = d;
	numOfTerms = 1;
}

// precondition:
//    p is the Univariate we are copying from
// postcondition: 
//    a Univariate which is a copy of p is created
Univariate::Univariate(const Univariate& p)
{   
	(*this) = p;
}

void Univariate::deleteTree(Node* node)
{
	if (node == nullptr)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node->term;
	delete node;
	node = nullptr;
}

void Univariate::deleteNode(Node* node)
{
	if (node == nullptr)
		return;	
	if(head == node)
		head= nullptr;
	Univariate temp(this->cmpFct);
	insertHelper(node->left, temp);
	insertHelper(node->right, temp);
	deleteTree(node);
	insertHelper(temp.head, *this);
	numOfTerms -= (temp.numOfTerms + 1);
}

// postcondition:
//    deep copy of the rtSide was made      
Univariate& Univariate::operator = (const Univariate& rtSide) 
{
	if (this != &rtSide)
	{
		deleteTree(head);
		highestDegree = rtSide.highestDegree;
		cmpFct = rtSide.cmpFct;
		insertHelper(rtSide.head, (*this));
	}
	return (*this);
}

// destructor frees up the memory 
Univariate::~Univariate() 
{
	deleteTree(head);
}


// postcondition: 
//    returns the highest degree of the polynomial
//    in the special case of the zero polynomial, return -1 
int Univariate::degree() const {
	return highestDegree;
}

Univariate::Node* Univariate::search(Node* node, int t, bool forRemoval = false) const
{
	if (node == nullptr || t == node->term->getDegree() || (forRemoval && ((node->right && node->right->term && node->right->term->getDegree() == t )|| (node->left && node->left&& node->left->term->getDegree() == t))))
		return node;
	return search((this->cmpFct(t,node->term->getDegree()) ? node->right : node->left), t);
}


// postcondition: 
//    returns the coefficient of term that has degree n
int Univariate::coefficient(int n) const 
{
	Node* temp =  (search(head,n));
	return temp? temp->term->getCoeff() : -1;

}

double Univariate::evaluateHelper(Node* node, double x) const
{
	if (node == nullptr)
		return 0;
	return (node->term->getCoeff() * pow(x, static_cast<double>(node->term->getDegree()))) + evaluateHelper(node->left, x) + evaluateHelper(node->right, x);
}

// postcondition: 
//    returns the value of evaluating the polynomial at x
double Univariate::evaluate(double x) const {
	return evaluateHelper(head, x);
}

// determine if the polynomial is the zero polynomial
bool Univariate::isZeroPolynomial() const { 
	return (! head);
}

void Univariate::insertHelper(Node* node, Univariate &target) const
{
	if (node == nullptr)
		return;
	insertHelper(node->left, target);
	insertHelper(node->right, target);
	Term* term = new Term(node->term->getCoeff(), node->term->getDegree());
	target.insert(term);
	delete term;

}

// precondition:
//   the term pointed to by t has been allocated 
//   t != nullptr 
void Univariate::insert(Term* t) 
{
	if (! t->getCoeff())
		return;
	if (head == nullptr)
	{
		head = new Node{nullptr, new Term(t->getCoeff(), t->getDegree()), nullptr};
		numOfTerms = 1;
		highestDegree = t->getDegree();
		return;
	}

	Node* temp = search(head, t->getDegree());
	if (temp != nullptr)
	{
		if ((t->getCoeff() + temp->term->getCoeff()) == 0)
		{
			temp = search(head,t->getDegree(), true);

			Node* temp2 = nullptr;
			if (temp->left && temp->left->term && temp->left->term->getDegree() == t->getDegree())
			{
				temp2 = temp->left;
				temp->left = nullptr;
			}
			else if (temp->right && temp->right->term && temp->right->term->getDegree() == t->getDegree())
			{
				temp2 = temp->right;
				temp->right = nullptr;
			} 
			else
			{
				temp2 = temp;
			}

			deleteNode(temp2);
			return;
		}

		Term* temp2 = new Term(t->getCoeff() + temp->term->getCoeff(), t->getDegree());
		delete temp->term;
		temp->term = temp2;
	}
	else
	{
		temp = head;
		while ((this->cmpFct(temp->term->getDegree(), t->getDegree()) ? temp->left : temp->right) != nullptr)
		{
			temp = this->cmpFct(temp->term->getDegree(), t->getDegree()) ? temp->left : temp->right;
		}
		(this->cmpFct(temp->term->getDegree(), t->getDegree()) ? temp->left : temp->right) = new Node{nullptr, new Term(t->getCoeff(), t->getDegree()), nullptr};
		++numOfTerms;
		highestDegree = highestDegree < t->getDegree() ? t->getDegree() : highestDegree;
	}
	return;
}

// postcondition: 
//    returns the number of terms in the tree
//    in the special case of the zero polynomial return 1
int Univariate::numberOfTerms() const {
	return numOfTerms ? numOfTerms : 1;
}

// precondition:
//    a and b are the two polynomials to sum up,
// postcondition: 
//    create a new polynomial which is the sum of two given polynomials
//    only the non-zero terms will be stored in the sum polynomial 
const Univariate Univariate::operator + (const Univariate& b) 
{
	Univariate uni(this->cmpFct);
	insertHelper(this->head, uni);
	insertHelper(b.head, uni);
	return uni;	
}

void Univariate::differentiateHelper(Node* node, Univariate &target) const
{
	if (node == nullptr)
		return;
	insertHelper(node->left, target);
	insertHelper(node->right, target);
	Term* term = new Term(node->term->getCoeff() * node->term->getDegree(), node->term->getDegree() -1);
	target.insert(term);
	delete term;
}

// differentiate
// postcondition:
//    returns a new polynomial
const Univariate Univariate::differentiate() const 
{
	Univariate uni(this->cmpFct);
	differentiateHelper(this->head, uni);
	return uni;	
}

// postcondition: 
//    if non numeric input is given, the istream enters a fail state
//    only non-zero terms will be inserted into the polynomial
std::istream& operator >> (std::istream& in, Univariate& poly) 
{
	int n;
	// input the number of non-zero terms n of the polynomial: ";
	in >> n;
	//get the degree and coefficient of every term
	for (int i = 0; i < n; i++) 
	{
		int tempC=0,tempD=0;
		in >> tempC >> tempD;
		if (!in)
		{
			std::cerr << "Input error" << std::endl;
			break;
		}
		Term t(tempC, tempD);
		poly.insert(&t);
	}
	return in;
}

void Univariate::print(std::ostream& out, Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	print(out, node->right);
	out << *(node->term);
	print(out, node?node->left:nullptr);
}

// postcondition:     
//    outputs the polynomial, starting with the highest degree
std::ostream& operator << (std::ostream& out, const Univariate& p) 
{
	Univariate::print(out, p.head);
	return out;
}

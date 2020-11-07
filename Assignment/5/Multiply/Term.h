#ifndef TERM_H
#define TERM_H

#include <iostream>


class Term
{
public:
	Term() = default;
	~Term() = default;
	Term(const Term &) = default;
	Term(int a, int b, int c) : coeff(a), deg_x(b), deg_y(c) {} 

	friend class Polynomial;
	bool operator< (const Term &p) { return (this->deg_x == p.deg_x ? this->deg_y < p.deg_y : this->deg_x < p.deg_x); }
	bool operator> (const Term &p) { return (this->deg_x == p.deg_x ? this->deg_y > p.deg_y : this->deg_x > p.deg_x); }
	bool operator== (const Term &p) { return (this->deg_x == p.deg_x && this->deg_y == p.deg_y); }
	bool operator<= (const Term &p) { return this->operator<(p) && this->operator==(p); }
	bool operator>= (const Term &p) { return this->operator>(p) && this->operator==(p); }
	Term operator* (const Term &p) { return Term(this->coeff * p.coeff, this->deg_x + p.deg_x, this->deg_y + p.deg_y); }
	int getCoeff() { return coeff; }
	int getX() { return deg_x; }
	int getY() { return deg_y; }
private:
	int coeff;
	int deg_x;
	int deg_y;	
};
#endif
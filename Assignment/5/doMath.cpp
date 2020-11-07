/* 
Alp Deniz Senyurt
100342433
CPSC2150 - W01


SORTING ALGORITHM DOES NOT WORK.
I WROTE THIS 3 TIMES AND NONE OF THEM WERE ABLE TO SORT CORRECTLY

1ST VERSION: DID NOT SORT CORRECTLY (SOMEWHAT SORTED) BUT AT LEAST SOME TERMS WERE "SORTED"
2ND VERSION: SEGMENTATION FAULT
3RD VERSION: ONLY RETURNS THE FIRST TERM AND NOTHING ELSE, RESULTING IN LOSS OF DATA

SUBMITTING FIRST VERSION ONLY AS AT LEAST IT SHOWS THAT OTHER OPERATIONS + BONUS IS WORKING (AT LEAST IT USED TO WORK FFS...)
*/

#include <iostream>
#include <cstdlib>

#include "Polynomial.h"
#include <fstream>

//#define MULTIPLY_POLYNOMIALS

// Read the number of terms that the polynomial has
// and each term assuming that the order of the terms
// are coefficient, degree_of_x, degree_of_y
// precondition:
//    error free input and an open stream
// postcondition:
//    if the ifstream fails, return.... 
//    otherwise .....
Polynomial readPoly(std::istream &fin, bool &done)
{
	Polynomial p;
	int size, c, degX, degY;
	if((fin >> size))
	{
		done = false;
		for (int i = 0; i < size; ++i)
		{
			fin >> c >> degX >> degY;
			p.insert(Term(c, degX, degY));
		}
	}
	else
	{
		done = true;
	}
	return p;
}

// output the polynomials as raw (unsorted)
// sorted, and then add and possibly multiply the polynomials
void doMathWithPolys(Polynomial p1, Polynomial p2)
{
	using std::cout;
	using std::endl; 

	cout << "===================================\n";
	cout << "unsorted" << endl;
	cout << "poly1: " << p1  << endl;
	cout << "poly2: " << p2  << endl;
	p1.sort();
	p2.sort();
	cout << "sorted" << endl;
	cout << "a: " << p1 << endl;
	cout << "b: " << p2 << endl;
	cout << "a + b: " << p1 + p2 << endl;
	#ifdef MULTIPLY_POLYNOMIALS
	cout << "a * b: " << p1 * p2 << endl;
	#endif
	cout << "da/dx: " << p1.diff(true)  << endl;
	cout << "da/dy: " << p1.diff(false)  << endl;
	cout << "db/dx: " << p2.diff(true)  << endl;
	cout << "db/dy: " << p2.diff(false) << endl;
	cout << "===================================\n";
}


int main()
{
	bool done = false;
	while (!done)
	{
		Polynomial p1, p2;
		p1 = readPoly(std::cin, done);
		if (!done)
		{
			p2 = readPoly(std::cin, done);
			doMathWithPolys(p1, p2);
		}
		std::cout << std::endl;
	}
	return 0;
}
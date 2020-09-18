/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
code started by Gladys Monagan
*/

#include "GArray.h"
#include <sstream>
#include <string>

const int GArray::NADA = -1;

// constructor with no arguments, makes an empty array
GArray::GArray()
{
	A = { 0, nullptr, 0 };
}

// postcondition:
// returns true if the array is empty, false otherwise
bool GArray::isEmpty() const
{
	return (A.n == 0 ? true : false);
}

void GArray::append(int x)
{
	if (A.capacity == A.n)
	{
		++A.capacity;
		int* tempArr = new int[A.capacity];
		for (int i = 0; i < A.n; ++i)
		{
			tempArr[i] = A.items[i];
		}
		delete [] A.items;
		A.items = tempArr;
	}
	A.items[A.n] = x;
	++A.n;
}

// make a string from the values of the array enclosed in "{ " followed by the value
// followed by a blank and then "}"
std::string GArray::toString() const
{
	std::string tempStr = "{ ";
	for (int i = 0; i < A.n; ++i)
	{
		tempStr += (std::to_string(A.items[i]) + " ");
	}
	return (tempStr + "}");
}

int GArray::length() const
{
	return A.n;
}

bool GArray::search(int x) const
{
	for (int i = 0; i < A.n; ++i)
	{
		if (A.items[i] == x)
			return true;
	}
	return false;
}

// postcondition:
//   returns the first element of the array if it exists or GArray::NADA otherwise
int GArray::first() const
{
	if (A.n == 0)
		return NADA;
	return *A.items;
}

// postcondition:
//   returns the last element of the array if it exists or GArray:: NADA otherwise
int GArray::last() const
{
		if (A.n == 0)
		return NADA;
	return *(A.items + A.n-1);
}

void GArray::reverse()
{
	int* tempArr = new int[A.n];
	for (int i = 0; i < A.n; ++i)
	{
		tempArr[i] = A.items[A.n-i-1];
	}
	delete [] A.items;
	A.items = tempArr;
}

bool operator == (const GArray& lfSide, const GArray& rtSide)
{
	if (lfSide.A.n != rtSide.A.n)
		return false;
	for (int i = 0; i < lfSide.A.n; ++i)
	{
		if (lfSide.A.items[i] != rtSide.A.items[i])
			return false;
	}
	return true;
}


bool GArray::equalArrays(const Array& a, const Array& b)
{
	if (a.n != b.n || a.capacity != b.capacity)
		return false;
	for (int i = 0; i < a.n; ++i)
	{
		if (a.items[i] != b.items[i])
			return false;
	}
	return true;
}

GArray::Array GArray::copyArray(const Array& from)
{
	Array temp = { from.n, new int[from.n], from.capacity };
	for (int i = 0; i < from.n; ++i)
	{
		temp.items[i] = from.items[i];
	}
	return temp;
}

void GArray::deleteArray(Array& array) 
{
	delete [] array.items;
}

// copy constructor 
// precondition:
//   there is enough heap memory to make a full copy
GArray::GArray(const GArray& other) 
{
	A = copyArray(other.A);
}

// overload the assignment operator
GArray& GArray::operator = (const GArray& other)
{
	if (this != &other) 
	{
		deleteArray(A);
		A = copyArray(other.A);
	}
	return *this;
}

// destructor
GArray::~GArray()
{
	delete [] A.items;
}
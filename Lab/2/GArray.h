#ifndef GARRAY_H
#define GARRAY_H
/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
defined by Gladys Monagan

A growing array
*/

#include <string>
using std::string;

class  GArray {
	public:
		// create an empty array
		GArray();

		// return if the array is empty, false otherwise
		bool isEmpty() const;

		// append x to the end of the array
		// precondition: there is enough heap memory
		// postcondition: x is placed as the last element and the length grows
		void append(int x);

		// return the number of elements in the array
		int length() const;

		// determine if x is in the array
		// postcondition: return true if in array, false otherwise
		bool search(int x) const;

		// return the first element of the array and GArray::NADA if the array is empty
		int first() const;

		// return the last element of the array and GArray::NADA if the array is empty
		int last() const;

		// mutator method (function) that reverses the array
		void reverse();

		// return a string consisting of 
		//   {
		//   ' '
		//   a1
		//   ' '
		//   a2
		//   ' '
		//   ...
		//   an
		//   ' '
		//   }
		// all the elements of the array separated by blanks
		// e.g. a string of 3 elements  "{ 41 36 999 }"
		string toString() const;

		// return true if the lfSide is equal to the rtSide 
		// meaning that the elements of both arrays are equal and in the same order
		friend bool operator == (const GArray& lfSide, const GArray& rtSide);

		// copy constructor
		// we assuming that there is enough heap memory to make a copy
		GArray(const GArray&);

		// overloaded assignment operator
		// we assuming that there is enough heap memory to make a copy
		GArray& operator = (const GArray&);

		// destructor
		~GArray();

		// value returned when the array is empty and first() or last() is called
		static const int NADA;

	private:
		struct Array {
			int n;        // the number of elements in the array 
			int* items;   // the elements
			int capacity; // the size of items namely
							  // how many elements were 
							  // allocated in the last array memory allocation
		};
		Array A;
		
		// return true when all the elements of a are identical to the elements of b
		// false otherwise
		static bool equalArrays(const Array&, const Array&);

		// make a deep, proper copy of the array from and return the copy
		Array copyArray(const Array& from);

		// deallocate the dynamically allocated memory of array
		void deleteArray(Array& array);

};
 
#endif

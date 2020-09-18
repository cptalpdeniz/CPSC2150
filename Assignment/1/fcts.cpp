// Name: 

#include "fcts.h"
#include <string>
#include <climits>  // CHAR_BIT

//MACRO TO MAKE IT EASIER AS SHARED CODE
#define CHECK_BIT(var,pos) (var & (1 << pos))


using std::string;

//---------------------------------------------------------------------------//
std::string toBinaryString(unsigned int n)
{
	//Base case, return "0" if the there's no number left
	if (n == 0)
		return "";
	//recursively get the bit, check if last bit is set/or not then concetenate
	return toBinaryString(n >> 1) + (CHECK_BIT(n, 0) ? "1" : "0");
}

//---------------------------------------------------------------------------//
//Recursive helper function
std::string toFinalStr(unsigned int n, unsigned int reqNumOfChars, unsigned int numOfChars)
{
	//base case 1 where we find string
	if (n == 0)
	{
		//length of the string is the same as required length. We can return.
		if (reqNumOfChars == numOfChars)
			return "";
		//Fill the left side with 0s
		return toFinalStr(n, reqNumOfChars, ++numOfChars++) + "0";
	}
	//Recursively populate the string, char by char
	return toFinalStr(n >> 1, reqNumOfChars, ++numOfChars++) + (CHECK_BIT(n, 0) ? "1" : "0");
}

std::string toBitsString(unsigned int n)
{
	return toFinalStr(n, sizeof(n) * CHAR_BIT, 0);
}

//---------------------------------------------------------------------------//
//Find the minimum positive

int minimumPositiveHelper(const int A[], int l, int num)
{
	if (l == 0)
		return num;
	if (A[l-1] < num && A[l-1] > 0)
		num = A[l-1];
	return minimumPositiveHelper(A, l-1, num);
}

int minimumPositive(const int A[] , int n)
{
	return minimumPositiveHelper(A, n, (A[n] < 0) ? 0 : A[n]);
}

/*

ASK ABOUT THIS PART TO SEE IF YOU CAN DO IT WITHOUT HELPER FUNCTION
int minimumPositive(const int A[], int n)
{
	if (n == 0)
		return A[n] < 0 ? 0 : A[n];
	return ((minimumPositive(A, n-1) < A[n] && A[n-1] > 0) ? A[n-1] : A[n])
}

*/

//---------------------------------------------------------------------------//

void swapPairsRightToLeft ( int A[ ] , int n ) ;

//---------------------------------------------------------------------------//

/*
* Assignment 1
* Author Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/


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
		return toFinalStr(n, reqNumOfChars, ++numOfChars) + "0";
	}
	//Recursively populate the string, char by char
	return toFinalStr(n >> 1, reqNumOfChars, ++numOfChars) + (CHECK_BIT(n, 0) ? "1" : "0");
}

std::string toBitsString(unsigned int n)
{
	return toFinalStr(n, sizeof(n) * CHAR_BIT, 0);
}

//---------------------------------------------------------------------------//
//Find the minimum positive

int minimumPositive(const int A[], int n)
{
	//set r as 0 or call for next recursion and set the next number
	int r = (--n < 0) ? 0 : minimumPositive(A, n);
	/*do ternary to determine to return either:
	-0 (as there are no positive numbers in the array)
	-A[n] (is the smallest number up to that point)
	-r (A[n] is not smaller than the previous number and we need to return r)
	*/
	return (A[n] > 0 && (A[n] < r || !r)) ? A[n] : r;
}


//---------------------------------------------------------------------------//
/*
do swap in 1 recursive call
then recurse with n-2 to go on next pair
stop when there is 0 or 1 element remaining
*/
void swapPairsRightToLeft (int A[] , int n)
{
	if (n <= 1)
		return;
	int temp = A[n-2];
	A[n-2] = A[n-1];
	A[n-1] = temp;
	return swapPairsRightToLeft(A, n-2);
}

//---------------------------------------------------------------------------//

//helper function
bool equalsChar(const std::string& strA, const std::string& strB, unsigned int index, char ch)
{	
	//detect which string is longer and compare index
	if (std::max(strA.length(), strB.length()) < index)
		return true;
	//XOR operation to check if they are the same or not (if ch is found at that index)
	if ((strA[index] == ch) ^ (strB[index] == ch))
	{
			return false;
	}
	//recursive call with index incremented by one
	return equalsChar(strA, strB, ++index, ch);
}

bool equalsChar(const std::string& strA , const std::string& strB , char ch) {
	return equalsChar(strA, strB, 0, ch);
}
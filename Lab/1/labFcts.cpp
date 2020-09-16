/*
*   Alp Deniz Senyurt
*   100342433
*   CPSC2150 - W02
*/

#include "labFcts.h"

bool search (int x, const int A[], int n)
{
	//if there's no more elements left to check, we weren't able to find the X in this array
	if (!n)
		return false;
	//if the element is found, return true
	if (x == A[0])
		return true;
	// by using ternary operator, we can write cleaner and shorter code for the same operation. If the number is not found in the first half, it initiates the recursive call for the second half
	return (search(x, A, n/2) ? true : search(x, A+(n/2), n-(n==1 ? n : n/2))); 
}
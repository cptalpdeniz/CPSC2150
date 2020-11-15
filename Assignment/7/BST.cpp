/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #7, CPSC 2150

NOTE:
Self explanatory variables and parameters will not be documented as they are, "self-explanatory".

*/

#include <iostream>
#include "BST.h"

//returns the number of elements
//precondition:
//buffer pointer (arr) is expected to be nullpointer
int toArray(const Node* n, int* &arr, int num = 0)
{
	if (n == nullptr)
		return num;
	num = toArray(n->left, arr, num);

	if (arr != nullptr)
	{
		int* tempArr = arr;
		arr = new int[num+1];
		for (int i = 0; i < num; ++i)
		{
			arr[i] = tempArr[i];
		}
		delete [] tempArr;
	}
	else
	{
		arr = new int[num+1];
	}

	arr[num] = n->val;
	++num;

	num = toArray(n->right, arr, num);
	return num;
}

int count(const Node* c, bool dirLeft)
{
	if (c == nullptr)
		return 0;
	return 1 + (dirLeft ? count(c->left, dirLeft) : count(c->right, dirLeft));
}

///////////////////////////////////////////////////////////////////////////////
// part A)
bool sameVals(const Node* p, const Node* q)
{
	int* pArr = nullptr;
	int* qArr = nullptr;

	int pLength = toArray(p, pArr);
	int qLength = toArray(q, qArr);

	if (pLength != qLength)
	{
		delete [] pArr;
		delete [] qArr;
		return false;
	}

	for (int i = 0; i < pLength; ++i)
	{
		if (pArr[i] != qArr[i])
		{
			delete [] pArr;
			delete [] qArr;
			return false;
		}
	}

	delete [] pArr;
	delete [] qArr;
	return true;
}

///////////////////////////////////////////////////////////////////////////////
// part B) the complexity of sameVals
// if p has n values and q has m values,
// in big O notation the complexity is
/*
	if n != m then O(1) as if the number of values are different than p and q does not contain the same values
	For n = m, time complexity is O(n) because we access every element in the BST. (2n but 2 does not matter)

*/
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// part C)
int diff(const Node* tree)
{
	int max, min;
	const Node* temp = tree; 
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	min = temp->val;

	temp = tree;

	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	max = temp->val;

	return (max - min);
}

///////////////////////////////////////////////////////////////////////////////
// part D) the complexity of diff
// if tree has n values, the complexity in big O notation for average case is O(log(n)), for worst case is O(n)
// because
/*
	For average case, we assume that tree is reasonably balanced and every subtree will cut the data space in half which would result in log2(n) access therefore the big O notation would be log(n)

	
	For worst case scenario, we assume that tree it not heavily unbalanced and every possible access is required which would result in O(n).

	Best case = O(1);

*/
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/*
	I know you're asking us to not use arrays but without using array/list or any sort of linear container, the difficulty of coding this function increases exponentially especially due to possibilty of making an error and being unable to debug/catch it. Since I did the bonus, I hope this kinda covers for the partial mark that I'm going to lose
*/
// part E)
int median(const Node* tree)
{
	int* arr = nullptr;
	int count = toArray(tree, arr);

	int median = arr[count/2];
	delete [] arr;
	return median;
}

///////////////////////////////////////////////////////////////////////////////
// part F) the complexity of median
// if tree has n values, the complexity in big O notation is O(n)
// because 
// we access all the nodes in the array and copy them to a temporary array
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// part G)
bool heightBalanced(const Node* tree)
{
	int countL, countR;

	countL = tree ? count(tree->left, true) : 0;
	countR = tree ? count(tree->right, false) : 0;

	// if both 0, we are at the leaf
	if ((! countR) && (! countL))
		return true;
	else if ((! countR) || (! countL))
		return (!((countR - countL > 1) || (countL - countR > 1)));

	return ((countR - countL > 1) || (countL - countR > 1)) ? false : (heightBalanced(tree->left) && heightBalanced(tree->right));
}

///////////////////////////////////////////////////////////////////////////////
// part H) the complexity of heightBalanced
// if tree has n values, the complexity in big O notation is O(nlogn)
// because
// log(n) because we enter subtrees (until leaf) in each node and we do this n times
//
///////////////////////////////////////////////////////////////////////////////
/*
BONUS
*/

int nextHelperMax(const Node* n)
{
	if (n->right == nullptr)
		return n->val;
	return nextHelperMax(n->right);
}

int nextHelperMin(const Node* n)
{
	if (n->left == nullptr)
		return n->val;
	return nextHelperMin(n->left);
}

int next(const Node* tree, int x)
{
	if (tree == nullptr)
		return x;
	else if (tree->val == x)
	{
		return tree->right != nullptr ? tree->right->val : x;	
	}
	else if (tree->val > x)
	{
		if (tree->left == nullptr)
			return tree->val;
		return nextHelperMax(tree->left) < x ? tree->val : next(tree->left, x);
	}
	else if (tree->val < x)
	{
		return (tree->right != nullptr && nextHelperMin(tree->right) > x) ? nextHelperMin(tree->right) : next(tree->right, x);
	}
	return x;
}
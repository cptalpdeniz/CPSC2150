// CPSC 2150 by Gladys Monagan
// Copyright 2020
// Do not post anywhere

#include <iostream>
#include "BST.h"
#include "BST_utils.h"
#include <string>
using std::string;


int main()
{
	using monagan::makeLeaf;
	using monagan::insertRight;
	using monagan::insertLeft;
	using monagan::toString;
	using std::cout;

	Node* tree1 = makeLeaf(4);
	tree1 = insertLeft(tree1, 3);
	tree1 = insertLeft(tree1, 1);
	tree1 = insertRight(tree1, 8);
	tree1 = insertRight(tree1, 10);

	Node* tree2 = makeLeaf(6);
	tree2 = insertLeft(tree2, 4);
	tree2 = insertLeft(tree2, 3);
	tree2 = insertLeft(tree2, 1);
	tree2 = insertRight(tree2, 8);
	tree2 = insertRight(tree2, 19);

	if (diff(tree1) == 9) {
		cout << "diff(" << toString(tree1) << ") is 9 as expected";
	}
	else {
		cout << "diff(" << toString(tree1) << " erroneously returns ";
		cout << diff(tree1);
	}
	cout << "\n\n";
	if (diff(tree2) == 18) {
		cout << "diff(" << toString(tree2) << ") is 18 as expected";
	}
	else {
		cout << "diff(" << toString(tree2) << "erroneously returns ";
		cout << diff(tree2);
	}
	cout << "\n\n";

	int m = median(tree1);
	if (m == 4){
		cout << "median is 4 as expected\n";
		cout << toString(tree1);
	}
	else {
		cout << "ERROR: median was " << m << "\n";
		cout << toString(tree1);
	}
	cout << "\n\n";

	m = median(tree2);
	if (m == 4 || m == 6){
		cout << "median is either 4 or 6 as expected\n";
		cout << toString(tree2);
	}
	else {
		cout << "ERROR: median was " << m << "\n";
		cout << toString(tree2);
	}
	cout << "\n\n";

	return 0;
}
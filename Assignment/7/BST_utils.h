// CPSC 2150 by Gladys Monagan
// Copyright 2020
// Do not post anywhere

#ifndef BST_UTILS_H
#define BST_UTILS_H
#include "BST.h"
#include <string>

namespace monagan 
{
	Node* makeLeaf(int x);
	std::string toString(const Node* tree, std::string label = std::string(""));
	std::string twoToString(const Node* p, const Node* q);
	Node* insertRight(Node* tree, int x);
	Node* insertLeft(Node* tree, int x);
	void destroyTree(Node* &tree);
}

#endif
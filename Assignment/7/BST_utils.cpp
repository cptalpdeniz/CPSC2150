// CPSC 2150 by Gladys Monagan
// Copyright 2020
// Do not post anywhere

#include <string>
#include <sstream>
#include "BST.h"
#include "BST_utils.h"

namespace monagan
{
	void toString(const Node* tree, std::stringstream& ss)
	{
		if (tree == nullptr) 
			return;
		ss << " [ ";
		toString(tree->left, ss);
		ss << tree->val;
		toString(tree->right, ss);
		ss << " ] ";
	}
	
	std::string toString(const Node* tree, std::string label)
	{ 
		std::stringstream ss;
		ss << label;
		toString(tree, ss);
		return ss.str();
	}
	
	std::string twoToString(const Node* p, const Node* q)
	{
		std::string trees = "";
		trees += toString(p, "p");
		trees += "\n";
		trees += toString(q, "q");
		return trees;
	}
	
	Node* makeLeaf(int x)
	{
		return new Node{nullptr, x, nullptr};
	}
	
	Node* insertRight(Node* p, int x)
	{
		if (p == nullptr) 
			p = makeLeaf(x);
		else
			p->right = insertRight(p->right, x);
		return p;
	}
	
	Node* insertLeft(Node* p, int x)
	{
		if (p == nullptr) 
			p = makeLeaf(x);
		else
			p->left = insertLeft(p->left, x);
		return p;
	}
	
	void destroyTree(Node* &tree)
	{
		if (tree == nullptr)
			return;
		destroyTree(tree->left);
		destroyTree(tree->right);
		delete tree;
		tree = nullptr;
	}
} 


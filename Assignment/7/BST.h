// CPSC 2150 Gladys Monagan
// do not submit

#ifndef BST_H
#define BST_H

struct Node
{
	Node* left;
	int val;
	Node* right;
};

bool sameVals(const Node* p, const Node* q);

// precondition: n has at least two nodes
int diff(const Node* tree);

// precondition: n has at least one node
int median(const Node* tree);

bool heightBalanced(const Node* tree);

// bonus
int next(const Node* tree, int x);

#endif

// CPSC 2150 by Gladys Monagan
// Copyright 2020
// Do not post anywhere

#include "gtest/gtest.h"
#include "BST.h"
#include "BST_utils.h"
#include <string>
using std::cout;
using std::string;

using monagan::makeLeaf;
using monagan::insertRight;
using monagan::insertLeft;
using monagan::toString;
using monagan::twoToString;
using monagan::destroyTree;

/*
tests for sameVals
./BST_unittest --gtest_filter="sameValsTestSuite.*"

tests for diff
./BST_unittest --gtest_filter="diffTestSuite.*"

tests for median
./BST_unittest --gtest_filter="Median*.*"

tests for heightBalanced
./BST_unittest --gtest_filter="heightBalancedTestSuite.*"
*/

// uncomment the next line if the bonus (next) was done
#define BONUS_NOT_DONE
/*
tests for heightBalanced
./BST_unittest --gtest_filter="nextTestSuite*.*"
*/

// having the option NDEBUG NOT defined means NO debugging occurs
// uncomment the next line if you DO want debugging
#define NDEBUG

TEST(sameValsTestSuite, SpecialEmptyTrees) {
   EXPECT_TRUE(sameVals(nullptr, nullptr));
}

TEST(sameValsTestSuite, IdenticalTrees1) {
   Node* p = makeLeaf(7);
   Node *q = makeLeaf(7);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 1NodeTreeFail) {
   Node* p = makeLeaf(4);
   Node *q = makeLeaf(7);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 2IdentialNodesTree) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 7);
   Node *q = makeLeaf(5);
   q = insertRight(q, 7);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, SameValsDiffStruct2) {
   Node* p = makeLeaf(6);
   p = insertRight(p, 8);
   Node *q = makeLeaf(8);
   q = insertLeft(q, 6);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructsFail) {
   Node* p = makeLeaf(4);
   p = insertRight(p, 7);
   Node *q = makeLeaf(4);
   q = insertRight(q, 5);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructs2Fail) {
   Node* p = makeLeaf(4);
   p = insertLeft(p, 2);
   Node *q = makeLeaf(4);
   q = insertLeft(q, 1);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 3NodesTreeRR) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 20);
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 3NodesTreeLL) {
   Node* p = makeLeaf(9);
   p = insertLeft(p, 7);
   p = insertLeft(p, 5);
   Node* q = makeLeaf(9);
   q = insertLeft(q, 7);
   q = insertLeft(q, 5);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct3NodesTree1) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 20);
   Node* q = makeLeaf(20);
   q = insertLeft(q, 15);
   q = insertLeft(q, 10);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct3NodesTree2) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 20);
   Node* q = makeLeaf(15);
   q = insertLeft(q, 10);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct3NodesTree3) {
   Node* p = makeLeaf(20);
   p = insertLeft(p, 15);
   p = insertLeft(p, 10);
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}


TEST(sameValsTestSuite, DiffStruct3NodesTree4) {
   Node* p = makeLeaf(15);
   p = insertLeft(p, 10);
   p = insertRight(p, 20);
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructs3Fail) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 30); // value not found in q
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 3NodesTree2Fail) {
   Node* p = makeLeaf(15);
   p = insertRight(p, 20);
   p = insertLeft(p, 5); // value not found in q
   Node* q = makeLeaf(15);
   q = insertRight(q, 20);
   q = insertLeft(q, 10);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTree) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 5); 
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTreeSwap) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 5); 
   // swapping p and q
   EXPECT_TRUE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTreeFail) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 3); 
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTreeSwapFail) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 3); 
   // swapping p and q
   EXPECT_FALSE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, qMoreNodespOneFail) {
   Node* p = makeLeaf(2);
   Node* q = makeLeaf(15);
   q = insertLeft(q, 10);
   q = insertRight(q, 20);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, pMoreNodespOneFail) {
   Node* p = makeLeaf(2);
   Node* q = makeLeaf(15);
   q = insertLeft(q, 10);
   q = insertRight(q, 20);
   // swapping p and q
   EXPECT_FALSE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, qMoreNodes) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 7);
   p = insertRight(p, 9); 
   Node* q = makeLeaf(5);
   q = insertRight(q, 7);
   q = insertRight(q, 9); 
   q->right = insertLeft(q->right, 8); // value not found in q
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, pMoreNodesFail) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 7);
   p = insertRight(p, 9); 
   Node* q = makeLeaf(5);
   q = insertRight(q, 7);
   q = insertRight(q, 9); 
   q->right = insertLeft(q->right, 8); // value not found in q
   // swapping p and q
   EXPECT_FALSE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, pMoreNodesqEmptyFail) {
   Node* p = makeLeaf(2);
   Node* q = nullptr;
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, qMoreNodespEmptyFail) {
   Node* p = nullptr;
   Node* q = makeLeaf(2);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, IdenticalTrees6NodesTree1) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 7);
   q = insertLeft(q, 2);
   q->left = insertRight(q->left, 18);
   q->left->left = insertRight(q->left->left, 4);
   q->left->left->right = insertRight(q->left->left->right, 6);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, IdenticalTrees6NodesTree2) {
   Node* p = makeLeaf(-10);
   p = insertRight(p, -7);
   p = insertRight(p, -2);
   p->right = insertLeft(p->right, -9);
   p->right->right = insertLeft(p->right->right, -4);
   p->right->right->left = insertLeft(p->right->right->left, -6);
   Node* q = makeLeaf(-10);
   q = insertRight(q, -7);
   q = insertRight(q, -2);
   q->right = insertLeft(q->right, -9);
   q->right->right = insertLeft(q->right->right, -4);
   q->right->right->left = insertLeft(q->right->right->left, -6);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, Structs6NodesTree1Fail) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 7);
   q = insertLeft(q, 2);
   q->left = insertRight(q->left, 18);
   q->left->left = insertRight(q->left->left, 4);
   q->left->left->right = insertRight(q->left->left->right, 5); // here
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, SameStructs6NodesTree2Fail) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 5); // here
   Node* q = makeLeaf(29);
   q = insertLeft(q, 7);
   q = insertLeft(q, 2);
   q->left = insertRight(q->left, 18);
   q->left->left = insertRight(q->left->left, 4);
   q->left->left->right = insertRight(q->left->left->right, 6);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, SameStructs6NodesTree3Fail) {
   Node* p = makeLeaf(-10);
   p = insertRight(p, -8); // here
   p = insertRight(p, -2);
   p->right = insertLeft(p->right, -9);
   p->right->right = insertLeft(p->right->right, -4);
   p->right->right->left = insertLeft(p->right->right->left, -6);
   Node* q = makeLeaf(-10);
   q = insertRight(q, -7);
   q = insertRight(q, -2);
   q->right = insertLeft(q->right, -9);
   q->right->right = insertLeft(q->right->right, -4);
   q->right->right->left = insertLeft(q->right->right->left, -6);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructs6NodesTree4Fail) {
   Node* p = makeLeaf(-10);
   p = insertRight(p, -7); 
   p = insertRight(p, -2);
   p->right = insertLeft(p->right, -9);
   p->right->right = insertLeft(p->right->right, -4);
   p->right->right->left = insertLeft(p->right->right->left, -6);
   Node* q = makeLeaf(-10);
   q = insertRight(q, -7);
   q = insertRight(q, -2);
   q->right = insertLeft(q->right, -9);
   q->right->right = insertLeft(q->right->right, -5); // here
   q->right->right->left = insertLeft(q->right->right->left, -6);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct6NodesTree1) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(2);
   q = insertRight(q, 4);
   q = insertRight(q, 6);
   q = insertRight(q, 7);
   q = insertRight(q, 18);
   q = insertRight(q, 29);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct6NodesTree1Swap) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(2);
   q = insertRight(q, 4);
   q = insertRight(q, 6);
   q = insertRight(q, 7);
   q = insertRight(q, 18);
   q = insertRight(q, 29);
   // swapping p and q
   EXPECT_TRUE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct6NodesTree2) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 18);
   q = insertLeft(q, 7);
   q = insertLeft(q, 6);
   q = insertLeft(q, 4);
   q = insertLeft(q, 2);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct6NodesTree2Swap) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 18);
   q = insertLeft(q, 7);
   q = insertLeft(q, 6);
   q = insertLeft(q, 4);
   q = insertLeft(q, 2);
   // swapping p and q
   EXPECT_TRUE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}


//////////////////////////////////////////////////////////////
// precondition for diff    n >= 2
//////////////////////////////////////////////////////////////
TEST(diffTestSuite, OneLeftChild) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(1, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, OneLeftChildNegative) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, -3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(7, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, OneRightChild) {
   Node* tree = makeLeaf(3);
   tree = insertRight(tree, 10);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(7, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, OneRightChildNegative) {
   Node* tree = makeLeaf(-1);
   tree = insertRight(tree, 10);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(11, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Mixed7) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(20, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, MixedBoth9) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 2);
   tree = insertLeft(tree, 1);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(22, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Mixed6) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(18, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Mixed8) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   tree->right->left = insertRight(tree->right->left, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(20, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Tree1) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 1);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 10);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(9, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Tree2) {
   Node* tree = makeLeaf(6);
   tree = insertLeft(tree, 4);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 1);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 19);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(18, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Diamond7) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(15, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Diamond9) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 16);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree = insertRight(tree, 27);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(24, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, FunnyDiamond7) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 9);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 14);
   tree->left->right = insertLeft(tree->left->right, 13);
   tree->left->right = insertLeft(tree->left->right, 11);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(22, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, FunnyDiamond11) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 2);
   tree = insertLeft(tree, 1);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 15);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(24, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, Diamond8) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(22, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, LeftTail5) {
   Node* tree = makeLeaf(51);
   tree = insertLeft(tree, 45);
   tree = insertLeft(tree, 43);
   tree = insertLeft(tree, 41);
   tree = insertLeft(tree, 38);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(13, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, LeftTail6) {
   Node* tree = makeLeaf(51);
   tree = insertLeft(tree, 45);
   tree = insertLeft(tree, 43);
   tree = insertLeft(tree, 41);
   tree = insertLeft(tree, 38);
   tree = insertLeft(tree, 37);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(14, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, LeftTail7) {
   Node* tree = makeLeaf(51);
   tree = insertLeft(tree, 45);
   tree = insertLeft(tree, 43);
   tree = insertLeft(tree, 41);
   tree = insertLeft(tree, 38);
   tree = insertLeft(tree, 37);
   tree = insertLeft(tree, 36);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(15, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}
TEST(diffTestSuite, RightTail6) {
   Node* tree = makeLeaf(31);
   tree = insertRight(tree, 32);
   tree = insertRight(tree, 33);
   tree = insertRight(tree, 34);
   tree = insertRight(tree, 35);
   tree = insertRight(tree, 36);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(5, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, RightTail7) {
   Node* tree = makeLeaf(31);
   tree = insertRight(tree, 32);
   tree = insertRight(tree, 33);
   tree = insertRight(tree, 34);
   tree = insertRight(tree, 35);
   tree = insertRight(tree, 36);
   tree = insertRight(tree, 100);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(69, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, LeftRightTail16) {
   Node* tree = makeLeaf(65);
   tree = insertLeft(tree, 64);
   tree = insertRight(tree, 66);
   tree = insertRight(tree, 67);
   tree = insertRight(tree, 68);
   tree = insertRight(tree, 69);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(5, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, UnBalancedRight8) {
   Node* tree = makeLeaf(2);
   tree = insertLeft(tree,0);
   tree->left = insertRight(tree->left, 1);
   tree = insertRight(tree, 3);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(7, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, UnBalancedLeft8) {
   Node* tree = makeLeaf(6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 7);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 4);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 2);
   tree = insertLeft(tree, 1);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(7, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, ZigZag7) {
   Node* tree = makeLeaf(50);
   tree = insertLeft(tree, 20);
   tree->left = insertRight(tree->left, 40);
   tree->left->right = insertLeft(tree->left->right, 33);
   tree->left->right->left = insertRight(tree->left->right->left, 34);
   tree->left->right->left = insertRight(tree->left->right->left, 36);
   tree = insertRight(tree, 60);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(40, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(diffTestSuite, ZigZag8) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 2);
   tree->left = insertRight(tree->left, 5);
   tree = insertRight(tree, 40);
   tree->right = insertLeft(tree->right, 30);
   tree->right->left = insertRight(tree->right->left, 35);
   tree->right->left->right = insertLeft(tree->right->left->right, 33);
   tree->right->left->right = insertLeft(tree->right->left->right, 32);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(38, diff(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}


testing::AssertionResult isEitherOr(int value, int a, int b) {
   if (value == a || value == b) {
      return testing::AssertionSuccess() 
         << "median(tree)=" << value << "  ==>  ==" << a <<  " or ==" << b;
   }
   else {
      return testing::AssertionFailure() 
         << "median(tree)=" << value << "  ==>  !=" << a <<  " and !=" << b;
   }
}

//////////////////////////////////////////////////////////////
// precondition for median    n >= 1
//////////////////////////////////////////////////////////////
TEST(MedianRootTestSuite, Root1) {
   Node* tree = makeLeaf(17);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(17, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, OneLeftChild2) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 3, 4)) <<  toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, OneLeftChildNegative2) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, -3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 4, -3)) <<  toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, OneRightChild2) {
   Node* tree = makeLeaf(3);
   tree = insertRight(tree, 10);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 3, 10)) <<  toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, OneRightChildNegative2) {
   Node* tree = makeLeaf(-1);
   tree = insertRight(tree, 10);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), -1, 10)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, MedianInRoot3) {
   Node* tree = makeLeaf(5);
   tree = insertLeft(tree, 2);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(5, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, TreeV5) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 1);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 10);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(4, median(tree)) << toString(tree, "t ree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, MedianInRootV7) {
   Node* tree = makeLeaf(9);
   tree = insertLeft(tree, 7);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 3);
   tree = insertRight(tree, 11);
   tree = insertRight(tree, 13);
   tree = insertRight(tree, 15);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(9, median(tree)) << toString(tree, "t ree = ");
   destroyTree(tree);
}


TEST(MedianRootTestSuite, Diamond7) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(19, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, Diamond9) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree = insertRight(tree, 27);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(19, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, FunnyDiamond7) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 9);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 14);
   tree->left->right = insertLeft(tree->left->right, 13);
   tree->left->right = insertLeft(tree->left->right, 11);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(14, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, FunnyDiamond11) {
   Node* tree = makeLeaf(19);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 2);
   tree = insertLeft(tree, 1);
   tree->left = insertRight(tree->left, 14);
   tree->left = insertRight(tree->left, 15);
   tree->left = insertRight(tree->left, 17);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 24);
   tree->right = insertLeft(tree->right, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(15, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, Tree6) {
   Node* tree = makeLeaf(6);
   tree = insertLeft(tree, 4);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 1);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 19);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 4, 6)) <<  toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, Mixed7) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree = insertRight(tree, 25);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(20, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, MixedBoth9) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 2);
   tree = insertLeft(tree, 1);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(7, median(tree)) << toString(tree, "t ree = ");
   destroyTree(tree);
}

TEST(MedianRootTestSuite, Mixed8) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 3);
   tree->left = insertRight(tree->left, 7);
   tree = insertRight(tree, 23);
   tree->right = insertLeft(tree->right, 20);
   tree->right->left = insertRight(tree->right->left, 21);
   tree->right->left = insertRight(tree->right->left, 22);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 10, 20)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, LeftTail5) {
   Node* tree = makeLeaf(51);
   tree = insertLeft(tree, 45);
   tree = insertLeft(tree, 43);
   tree = insertLeft(tree, 41);
   tree = insertLeft(tree, 38);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(43, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, LeftTail6) {
   Node* tree = makeLeaf(51);
   tree = insertLeft(tree, 45);
   tree = insertLeft(tree, 43);
   tree = insertLeft(tree, 41);
   tree = insertLeft(tree, 38);
   tree = insertLeft(tree, 37);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 41, 43)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, LeftTail7) {
   Node* tree = makeLeaf(51);
   tree = insertLeft(tree, 45);
   tree = insertLeft(tree, 43);
   tree = insertLeft(tree, 41);
   tree = insertLeft(tree, 38);
   tree = insertLeft(tree, 37);
   tree = insertLeft(tree, 36);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(41, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, RightTail6) {
   Node* tree = makeLeaf(31);
   tree = insertRight(tree, 32);
   tree = insertRight(tree, 33);
   tree = insertRight(tree, 34);
   tree = insertRight(tree, 35);
   tree = insertRight(tree, 36);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 33, 34)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, RightTail7) {
   Node* tree = makeLeaf(31);
   tree = insertRight(tree, 32);
   tree = insertRight(tree, 33);
   tree = insertRight(tree, 34);
   tree = insertRight(tree, 35);
   tree = insertRight(tree, 36);
   tree = insertRight(tree, 100);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(34, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, LeftRightTail16) {
   Node* tree = makeLeaf(65);
   tree = insertLeft(tree, 64);
   tree = insertRight(tree, 66);
   tree = insertRight(tree, 67);
   tree = insertRight(tree, 68);
   tree = insertRight(tree, 69);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 66, 67)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, UnBalancedRight8) {
   Node* tree = makeLeaf(2);
   tree = insertLeft(tree,0);
   tree->left = insertRight(tree->left, 1);
   tree = insertRight(tree, 3);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 3, 4)) <<  toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, UnBalancedLeft8) {
   Node* tree = makeLeaf(6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 7);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 4);
   tree = insertLeft(tree, 3);
   tree = insertLeft(tree, 2);
   tree = insertLeft(tree, 1);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 4, 5)) <<  toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, ZigZag7) {
   Node* tree = makeLeaf(50);
   tree = insertLeft(tree, 20);
   tree->left = insertRight(tree->left, 40);
   tree->left->right = insertLeft(tree->left->right, 33);
   tree->left->right->left = insertRight(tree->left->right->left, 34);
   tree->left->right->left = insertRight(tree->left->right->left, 36);
   tree = insertRight(tree, 60);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_EQ(36, median(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(MedianTestSuite, ZigZag8) {
   Node* tree = makeLeaf(10);
   tree = insertLeft(tree, 2);
   tree->left = insertRight(tree->left, 5);
   tree = insertRight(tree, 40);
   tree->right = insertLeft(tree->right, 30);
   tree->right->left = insertRight(tree->right->left, 35);
   tree->right->left->right = insertLeft(tree->right->left->right, 33);
   tree->right->left->right = insertLeft(tree->right->left->right, 32);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(isEitherOr(median(tree), 30, 32)) << toString(tree, " tree = ");
   destroyTree(tree);
}


TEST(heightBalancedTestSuite, 7NodesTree3L3RFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -2);
   tree = insertLeft(tree, -4);
   tree = insertLeft(tree, -6);
   tree = insertRight(tree, 1);
   tree = insertRight(tree, 3);
   tree = insertRight(tree, 5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 5NodesTree1L2R1RL) {
   Node* tree = makeLeaf(13);
   tree = insertLeft(tree, 11);
   tree = insertRight(tree, 15);
   tree = insertRight(tree, 17);
   tree->right = insertLeft(tree->right, 14);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, EmptyTree) {
   Node* tree = nullptr;
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 1NodeFullTree) {
   Node* tree = makeLeaf(7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 2NodesTree1L) {
   Node* tree = makeLeaf(7);
   tree = insertLeft(tree, 5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 2NodesTree1R) {
   Node* tree = makeLeaf(3);
   tree = insertRight(tree, 8);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 3NodesTree2RFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 3NodesTree2LFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 3NodesFullTree1L1R) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree3LFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree3RFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree2L1) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree1L2R) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree2L1LRFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree2R1RLFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree1R1RL1RLRFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 4);
   tree->right->left = insertLeft(tree->right->left, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, Root05NodesTree1L2R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -2);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 5NodesTree2L2R) {
   Node* tree = makeLeaf(6);
   tree = insertLeft(tree, 4);
   tree = insertLeft(tree, 2);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 6NodesTree1L1LR2R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 6NodesTree2L1LR1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree3L1LR1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 6NodesTree3LR1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
}

TEST(heightBalancedTestSuite, 6NodesTree2R1RL1RLL1RLRFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 5NodesTree2R1RL1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTreeFull) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -6);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesNotTreeFull) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -8);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->left->left = insertRight(tree->left->left, -6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesIsNotTreeFull) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -8);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->left->left = insertRight(tree->left->left, -7);
   tree->left->left->right = insertRight(tree->left->left->right, -6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree2L2L1RL1RLR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree2LR1LRL1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -3);
   tree->left->right = insertLeft(tree->left->right, -4);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree3L2R1RLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesIsNotTreeAFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -8);
   tree->left->left = insertRight(tree->left->left, -6);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree1L1RL1L3R1LR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree2L1RL1LLR1RLR1R1LR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -3);
   tree->left->right = insertLeft(tree->left->right, -4);
   tree->left->right = insertRight(tree->left->right, -2);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree1L1RL2L2R1LR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree2L2R1RL1RLR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 4);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesTree2L2R1RL1RLR1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right = insertLeft(tree->right, 1);
   tree->right->left = insertRight(tree->right->left, 4);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesTree4L4RFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -2);
   tree = insertLeft(tree, -4);
   tree = insertLeft(tree, -6);
   tree = insertLeft(tree, -8);
   tree = insertRight(tree, 1);
   tree = insertRight(tree, 3);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, TenNodesTree2L2R1RL1RLR1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -2);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right = insertLeft(tree->right, 1);
   tree->right->left = insertRight(tree->right->left, 4);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, FifteenNodesNO) {
   Node* tree = makeLeaf(50);
   tree = insertLeft(tree, 40);
   tree = insertLeft(tree, 30);
   tree = insertLeft(tree, 20);
   tree = insertLeft(tree, 10);
   tree->left = insertRight(tree->left, 45);
   tree->left = insertRight(tree->left, 48);
   tree = insertRight(tree, 60);
   tree = insertRight(tree, 70);
   tree = insertRight(tree, 80);
   tree->right->right = insertLeft(tree->right->right, 69);
   tree->right = insertLeft(tree->right, 55);
   tree->right->left = insertLeft(tree->right->left, 53);
   tree->right->left = insertLeft(tree->right->left, 51);
   tree->right->left = insertRight(tree->right->left, 57);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, SixteenNodesNo) {
   Node* tree = makeLeaf(50);
   tree = insertLeft(tree, 40);
   tree = insertLeft(tree, 30);
   tree = insertLeft(tree, 20);
   tree = insertLeft(tree, 10);
   // difference with heightBalanced15HeavyNodesHeavyTestSuite
   tree->left->left = insertRight(tree->left->left, 35);
   tree->left = insertRight(tree->left, 45);
   tree->left = insertRight(tree->left, 48);
   tree = insertRight(tree, 60);
   tree = insertRight(tree, 70);
   tree = insertRight(tree, 80);
   tree->right->right = insertLeft(tree->right->right, 69);
   tree->right = insertLeft(tree->right, 55);
   tree->right->left = insertLeft(tree->right->left, 53);
   tree->right->left = insertLeft(tree->right->left, 51);
   tree->right->left = insertRight(tree->right->left, 57);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}


//////////////////////////////////////////////////////////////////////////
// BONUS
//////////////////////////////////////////////////////////////////////////
#ifndef BONUS_NOT_DONE
Node* nextBST_5NRRR() {
   Node *tree = makeLeaf(5);
   tree = insertRight(tree, 10);
   tree = insertRight(tree, 15);
   tree = insertRight(tree, 20);
   return tree;
}

Node* nextBST_5NRNLR() {
   Node *tree = makeLeaf(5);
   tree = insertRight(tree, 15);
   tree->right = insertLeft(tree->right, 10);
   tree->right = insertRight(tree->right, 20);
   return tree;
}
Node* nextBST_5NRLL() {
   Node *tree = makeLeaf(5);
   tree = insertRight(tree, 20);
   tree->right = insertLeft(tree->right, 15);
   tree->right->left = insertLeft(tree->right->left, 10);
   return tree;
}
Node* nextBST_5NRLR() {
   Node *tree = makeLeaf(5);
   tree = insertRight(tree, 20);
   tree->right = insertLeft(tree->right, 10);
   tree->right->left = insertRight(tree->right->left, 15);
   return tree;
}

Node* nextBST_10LNRR() {
   Node *tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree = insertRight(tree, 15);
   tree = insertRight(tree, 20);
   return tree;   
}

Node* nextBST_10LNRL() {
   Node *tree = makeLeaf(10);
   tree = insertLeft(tree, 5);
   tree = insertRight(tree, 20);
   tree->right = insertLeft(tree->right, 15);
   return tree;
}

Node* nextBST_15LLNR() {
   Node *tree = makeLeaf(15);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 5);
   tree = insertRight(tree, 20);
   return tree;
}

Node* nextBST_15LRNR() {
   Node *tree = makeLeaf(15);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 10);
   tree = insertRight(tree, 20);
   return tree;
}

Node* nextBST_20NLRR() {
   Node* tree = makeLeaf(20);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 10);
   tree->left->right = insertRight(tree->left->right, 15);
   return tree;
}

Node* nextBST_20NLRL() {
   Node* tree = makeLeaf(20);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 15);
   tree->left->right = insertLeft(tree->left->right, 10);
   return tree;
}

Node* nextBST_20NLLNR() {
   Node* tree = makeLeaf(20);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 5);
   tree->left = insertRight(tree->left, 15);
   return tree;
}

Node* nextBST_20NLLL() {
   Node* tree = makeLeaf(20);
   tree = insertLeft(tree, 15);
   tree = insertLeft(tree, 10);
   tree = insertLeft(tree, 5);
   return tree;
}

Node* nextBST_20NLLR() {
   Node* tree = makeLeaf(20);
   tree = insertLeft(tree, 15);
   tree = insertLeft(tree, 5);
   tree->left->left = insertRight(tree->left->left, 10);
   return tree;
}

Node* makeOtherBST() {
   Node* tree = makeLeaf(29);
   tree = insertLeft(tree, 7);
   tree = insertLeft(tree, 2);
   tree->left = insertRight(tree->left, 18);
   tree->left->left = insertRight(tree->left->left, 4);
   tree->left->left->right = insertRight(tree->left->left->right, 6);
   return tree;
}

TEST(nextTestSuite_not_in, EmptyTree) {
   Node* tree = nullptr;
   int x = 5;
   int nVal = next(tree, x);
   EXPECT_EQ(5, nVal) << "the tree is empty";
   x = 0;
   nVal = next(tree, x);
   EXPECT_EQ(0, nVal) << "the tree is empty";
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRRR_5) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRRR_10) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRRR_15) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRNLR_5) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRNLR_10) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRNLR_15) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRLL_5) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRLL_10) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRLL_15) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRLR_5) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRLR_10) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_5NRLR_15) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_10LNRR_5) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_10LNRR_10) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_10LNRR_15) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_10LNRL_5) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_10LNRL_10) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_10LNRL_15) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_15LLNR_5) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_15LLNR_10) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_15LLNR_15) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_15LRNR_5) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_15LRNR_10) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_15LRNR_15) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLRR_5) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLRR_10) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLRR_15) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLRL_5) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLRL_10) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLRL_15) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLNR_5) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLNR_10) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLNR_15) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLL_5) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLL_10) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLL_15) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLR_5) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 5), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLR_10) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 10), 15) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, BST_20NLLR_15) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 15), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, BST_smaller_value_5NRRR) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_5NRNLR) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_5NRLL) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_5NRLR) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_10LNRR) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_10LNRL) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_15LLNR) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_15LRNR) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_20NLRR) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_20NLRL) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_20NLLNR) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_20NLLL) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_smaller_value_20NLLR) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 2), 5) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, BST_middle_value7_5NRRR) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_5NRNLR) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_5NRLL) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_5NRLR) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_10LNRR) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_10LNRL) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_15LLNR) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_15LRNR) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_20NLRR) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_20NLRL) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_20NLLNR) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_20NLLL) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value7_20NLLR) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 7), 10) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, BST_middle_value19_5NRRR) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_5NRNLR) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_5NRLL) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_5NRLR) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_10LNRR) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_10LNRL) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_15LLNR) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_15LRNR) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_20NLRR) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_20NLRL) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_20NLLNR) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_20NLLL) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_middle_value19_20NLLR) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 19), 20) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, BST_largest_5NRRR) {
   Node* tree = nextBST_5NRRR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_5NRNLR) {
   Node* tree = nextBST_5NRNLR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_5NRLL) {
   Node* tree = nextBST_5NRLL();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_5NRLR) {
   Node* tree = nextBST_5NRLR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_10LNRR) {
   Node* tree = nextBST_10LNRR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_10LNRL) {
   Node* tree = nextBST_10LNRL();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_15LLNR) {
   Node* tree = nextBST_15LLNR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_15LRNR) {
   Node* tree = nextBST_15LRNR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_20NLRR) {
   Node* tree = nextBST_20NLRR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_20NLRL) {
   Node* tree = nextBST_20NLRL();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_20NLLNR) {
   Node* tree = nextBST_20NLLNR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_20NLLL) {
   Node* tree = nextBST_20NLLL();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}
TEST(nextTestSuite_not_in, BST_largest_20NLLR) {
   Node* tree = nextBST_20NLLR();
   EXPECT_EQ(next(tree, 25), 25) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, OtherBST_right1) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 2), 4) << toString(tree);
}
TEST(nextTestSuite_in, OtherBST_right2) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 4), 6) << toString(tree);
}
TEST(nextTestSuite_in, OtherBST_right3) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 7), 18) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, OtherBST_above1) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 6), 7) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_in, OtherBST_above2) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 18), 29) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, OtherBST_middle_value5) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 5), 6) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, OtherBST_middle_value3) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 3), 4) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, OtherBST_middle_value10) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 10), 18) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, OtherBST_middle_value20) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 20), 29) << toString(tree);
   destroyTree(tree);
}

TEST(nextTestSuite_not_in, OtherBST_largest10) {
   Node* tree = makeOtherBST();
   EXPECT_EQ(next(tree, 100), 100) << toString(tree);
   destroyTree(tree);
}
#endif

// A unit test for Langara CPSC 2150 
// Assignment 4: Skip List
// C++ unit test framework: Google Test
// Author: Gladys Monagan 
// Name: 

#include "SList.h"
#include "gtest/gtest.h"
#include <string.h>
#include <sstream>
#include <iostream>

using std::string;
using std::cout;
using std::stringstream;

// helper function to print custom error message
string COUT_ERROR(string e) { 
  return "[  ERROR ] " + e;
}

//-----------------------------------------------------------------
// constructorTest
//-----------------------------------------------------------------
TEST(constructorTest, BottomEmptyList) {
	SList sList;
	stringstream actual;
	actual << sList;
	EXPECT_EQ(actual.str(), string(""));
}
TEST(constructorTest, TopEmptyList) {
	SList sList;
	stringstream actual;
	sList.setTopListOutput(true);
	actual << sList;
	EXPECT_EQ(actual.str(), string(""));
}
//-----------------------------------------------------------------
// insert in ascending order
//-----------------------------------------------------------------
TEST(insertAscendingTest, OneElementBottomList) {
	SList sList;
	int x = 10;
	sList.insert(x);
	stringstream actual;
	actual << sList;
	stringstream expected;
	expected << x << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, OneElementTopList) {
	SList sList;
	int x = 10;
	sList.insert(x);
	stringstream actual;
	sList.setTopListOutput(true);
	actual << sList;
	stringstream expected;
	expected << x << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, TwoElementsBottomList) {
	SList sList;
	int x = 10;
	int y = 20;
	sList.insert(x);
	sList.insert(y);
	stringstream actual;
	actual << sList;
	stringstream expected;
	expected << x << sList.getOutDelimeter()
				<< y << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, TwoElementsTopList) {
	SList sList;
	int x = 10;
	int y = 20;
	sList.insert(x);
	sList.insert(y);
	stringstream actual;
	sList.setTopListOutput(true);
	actual << sList;
	stringstream expected;
	expected << x << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, ThreeElementsBottomList) {
	SList sList;
	int A[] = {10, 20, 30};
	int n = 3;
	stringstream expected;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
		expected << A[i] << sList.getOutDelimeter();
	}
	stringstream actual;
	actual << sList;
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, ThreeElementsTopList) {
	SList sList;
	int A[] = {10, 20, 30};
	int n = 3;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
	}
	stringstream actual;
	sList.setTopListOutput(true);
	actual << sList;
	stringstream expected;
	expected << A[0] << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, FourElementsBottomList) {
	SList sList;
	int A[] = {10, 20, 30, 40};
	int n = 4;
	stringstream expected;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
		expected << A[i] << sList.getOutDelimeter();
	}
	stringstream actual;
	actual << sList;
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, FiveElementsBottomList) {
	SList sList;
	int A[] = {10, 20, 30, 40, 50};
	int n = 5;
	stringstream expected;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
		expected << A[i] << sList.getOutDelimeter();
	}
	stringstream actual;
	actual << sList;
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, FiveElementsTopList) {
	SList sList;
	int A[] = {10, 20, 30, 40, 50};
	int n = 5;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
	}
	stringstream actual;
	sList.setTopListOutput(true);
	actual << sList;
	stringstream expected;
	expected << A[0] << sList.getOutDelimeter()
				<< A[2] << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, NineElementsBottomList) {
	SList sList;
	int A[] = {10, 20, 30, 40, 50, 61, 77, 88, 99};
	int n = 9;
	stringstream expected;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
		expected << A[i] << sList.getOutDelimeter();
	}
	stringstream actual;
	actual << sList;
	EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, NineElementsTopList) {
	SList sList;
	int A[] = {10, 20, 30, 40, 50, 61, 77, 88, 99};
	int n = 9;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
	}
	stringstream actual;
	sList.setTopListOutput(true);
	actual << sList;
	stringstream expected;
	expected << A[0] << sList.getOutDelimeter()
			<< A[3] << sList.getOutDelimeter()
			<< A[6] << sList.getOutDelimeter();
	EXPECT_EQ(actual.str(), expected.str());
}
//-----------------------------------------------------------------
// search for an element: ignore the number of comparisons
//-----------------------------------------------------------------
TEST(searchTest, NoElementsFail) {
	SList sList;
	int c;
	EXPECT_FALSE(sList.search(3, c));
}
TEST(searchTest, NineElements) {
	SList sList;
	int c;
	int A[] = {10, 20, 30, 40, 50, 61, 77, 88, 99};
	int n = 9;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
	}
	for (auto i = 0; i < n; i++) {
		EXPECT_TRUE(sList.search(A[i], c));
	}
}
TEST(searchTest, NineElementsFail) {
	SList sList;
	int c;
	int A[] = {10, 20, 30, 40, 50, 61, 77, 88, 99};
	int n = 9;
	for (auto i = 0; i < n; i++) {
		sList.insert(A[i]);
	}
	EXPECT_FALSE(sList.search(100, c));
}
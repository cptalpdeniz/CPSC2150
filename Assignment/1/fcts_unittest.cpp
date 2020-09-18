// CPSC 2150, Assignment #1 started by Gladys Monagan
#include <string>
#include "gtest/gtest.h"
#include "fcts.h"

using std::string;
using std::cout;

// helper function to make a string 
//   [----ERROR-]
//   the n values of A
//   msg
string errorArrayString(string arrayName, const int A[], int n, string msg){
   string arrayStr = arrayName + " = { ";
   for (int i = 0; i < n; i++) {
      arrayStr += std::to_string(A[i]) + " ";
   }
   arrayStr += "} ";
   return "[----ERROR-] " + arrayStr + msg;
}

// determines if A and B are equal return true if such is the case, false otherwise
bool equalArrays(const int A[], int nA, const int B[], int nB) {
   if (nA != nB)
      return false;
   for (int i = 0; i < nA; i++) {
      if (A[i] != B[i])
         return false;
   }
   return true;
}

//---------------------------------------------------------------------------//
TEST(toBinaryStringTest, TwoDecimalDigits) {
  EXPECT_EQ("1100", toBinaryString(12));
}

TEST(toBinaryStringTest, OneDecimalDigit) {
  EXPECT_EQ("1", toBinaryString(1));
}

//---------------------------------------------------------------------------//
TEST(toBitsStringTest, OneDecimalDigit) {
   EXPECT_EQ("00000000000000000000000000000001", toBitsString(1));
}

TEST(toBitsStringTest, TwoDecimalDigits) {
   EXPECT_EQ("00000000000000000000000000001100", toBitsString(12));
}

TEST(toBitsStringTest, FourDecimalDigits) {
   EXPECT_EQ("00000000000000000000010000000001", toBitsString(1025));
}

//---------------------------------------------------------------------------//
TEST(minimumPositiveTest, OneElementFail) {
  int A[] = { -7 };
  EXPECT_EQ(0, minimumPositive(A, 1)) << 
     errorArrayString("A", A, 1, " no positive integers " );
}

TEST(minimumPositiveTest, NoElementsFail) {
  int A[] = { 3 };
  EXPECT_EQ(0, minimumPositive(A, 0)) << 
     errorArrayString("A", A, 0, " no positive integers: empty array " );
}

TEST(minimumPositiveTest, MinimumPositiveElementFirst) {
  int A[] = {1, 7};
  EXPECT_EQ(1, minimumPositive(A, 2)) << 
     errorArrayString("A", A, 2, " 1 is less than 7 " );
  int B[] = {4, -8};
  EXPECT_EQ(4, minimumPositive(B, 2)) <<
     errorArrayString("B", B, 2, " 4 is positive, -8 is not " );
}

//---------------------------------------------------------------------------//
// swapPairsRightToLeft precondition: n > 0
TEST(swapPairsRightToLeftTest, EvenNumberOfElements) {
   int A[] = {11, 22, 33, 44, 55, 66};
   int EXPECTED_A[] = {22, 11, 44, 33, 66, 55};
   swapPairsRightToLeft(A, 6);
   EXPECT_TRUE(equalArrays(A, 6, EXPECTED_A, 6)) <<
      errorArrayString("A", A, 6, " not swapped correctly " );
}

TEST(swapPairsRightToLeftTest, OddNumberOfElements) {
   int A[] = {11, 22, 33, 44, 55};
   int EXPECTED_A[] = {11, 33, 22, 55, 44};
   swapPairsRightToLeft(A, 5);
   EXPECT_TRUE(equalArrays(A, 5, EXPECTED_A, 5)) <<
      errorArrayString("A", A, 5, " not swapped correctly " );
}

//---------------------------------------------------------------------------//
TEST(equalsCharTest, ExtraCharactersButCharSame) {
   EXPECT_TRUE(equalsChar( "aaaXaaaX", "abcXcbaX", 'X' ));
   EXPECT_TRUE(equalsChar( "abcXcbaX", "aaaXaaaX", 'X' ));
   EXPECT_TRUE(equalsChar( "XaXbXcX", "XtXoXpXdef", 'X' ));
   EXPECT_TRUE(equalsChar( "XtXoXpXdef", "XaXbXcX", 'X' ));
}

TEST(equalsCharTest, TooManyXsFail) {
   EXPECT_FALSE(equalsChar( "XaXbXcX", "XtXoXpXdXf", 'X' ));
   EXPECT_FALSE(equalsChar( "XtXoXpXdXf", "XaXbXcX", 'X' ));
}

TEST(equalsCharTest, JustCharsWrongNumberFail) {
   EXPECT_FALSE(equalsChar( "XXXX", "XX", 'X' ));
   EXPECT_FALSE(equalsChar( "XX", "XXXX", 'X' ));
}

TEST(equalsCharTest, WrongPositionedXsFail) {
   EXPECT_FALSE(equalsChar( "aXaXbXcX", "XtXoXpX", 'X' ));
   EXPECT_FALSE(equalsChar( "XtXoXpX", "aXaXbXcX", 'X' ));
}

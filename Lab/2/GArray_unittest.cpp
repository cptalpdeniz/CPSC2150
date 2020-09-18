// A unit test for Langara CPSC 2150 
// C++ unit test framework: google test
// Author: Gladys Monagan
// September 2020
// Name: 

#include "GArray.h"
#include "gtest/gtest.h"
#include <string.h>

// return a string concatanating [----ERROR-] and msg
std::string errorString(std::string msg) { 
  return "[  ERROR ] " + msg;
}

//-----------------------------------------------------------------
// constructorTest...depends on toString
//-----------------------------------------------------------------
TEST(constructorTest, DefaultConstructor) {
   GArray array;
   EXPECT_EQ("{ }", array.toString()) <<
      errorString("the constructor should have made an empty array");
}

//-----------------------------------------------------------------
// isEmptyTest
//-----------------------------------------------------------------
TEST(isEmptyTest, EmptyArray) {
   GArray array;
   EXPECT_TRUE(array.isEmpty()) << 
      errorString("A new array should be empty");
}

//-----------------------------------------------------------------
// appendTest...depends on toString
//-----------------------------------------------------------------
TEST(appendTest, OneElement) {
   GArray array;
   array.append(11);
   EXPECT_EQ("{ 11 }", array.toString());
}

TEST(appendTest, TwoElements) {
   GArray array;
   array.append(11);
   array.append(22);
   EXPECT_EQ("{ 11 22 }", array.toString());
}

TEST(appendTest, ThreeElements) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   EXPECT_EQ("{ 11 22 33 }", array.toString());
}

TEST(appendTest, SixElements) { // array should have grown
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.append(44);
   array.append(55);
   array.append(66);
   EXPECT_EQ("{ 11 22 33 44 55 66 }", array.toString());
}

//-----------------------------------------------------------------
// lengthTest...depends on append
//-----------------------------------------------------------------
TEST(lengthTest, EmptyArray) {
   GArray array;
   EXPECT_EQ(0, array.length()) << 
      errorString("A new array should have a length of 0");
}

TEST(lengthTest, OneElement) {
   GArray array;
   array.append(11);
   EXPECT_EQ(1, array.length()) << 
      errorString("length should be 1, after appending 1 item.");
   // making sure that otherArray is separate from array   
   GArray otherArray;
   otherArray.append(33);
   EXPECT_EQ(1, otherArray.length()) << 
      errorString("length should be 1, after appending 1 item.");
}

TEST(lengthTest, TwoElementsAppend) {
   GArray otherArray;
   otherArray.append(33);
   otherArray.append(44);
   EXPECT_EQ(2, otherArray.length()) << 
      errorString("length should be 2, after appending 2 items.");
}

TEST(lengthTest, SevenElements) {
   GArray array;
   array.append(33);
   array.append(22);
   array.append(11);
   array.append(11);
   array.append(11);
   array.append(11);
   array.append(11);
   EXPECT_EQ(7, array.length()) << 
      errorString("length should be 7, after appending 7 items.");

   GArray otherArray;
   otherArray.append(44);
   otherArray.append(55);
   otherArray.append(66);
   EXPECT_EQ(3, otherArray.length()) << 
      errorString("length should be 3, after appending 3 items.");
}

//-----------------------------------------------------------------
// searchTest...depends on append and append and toString
//-----------------------------------------------------------------
TEST(searchTest, EmptyArrayFail) {
   GArray array;
   EXPECT_FALSE(array.search(11)) << 
      errorString("should not able to find in an empty Array.");
}

TEST(searchTest, OneElement) {
   GArray array;
   array.append(99);
   EXPECT_FALSE(array.search(11)) << 
      errorString("should not able to find 11 in " + array.toString());
}

TEST(searchTest, OneElementFail) {
   GArray array;
   array.append(99);
   EXPECT_TRUE(array.search(99)) << 
      errorString("should find 99 in " + array.toString());
}

TEST(searchTest, FirstElementFound) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.append(44);
   EXPECT_TRUE(array.search(44)) <<
      errorString("should find 44 in " + array.toString());
}

TEST(searchTest, LongerArrayElementFail) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.append(44);
   array.append(5);
   EXPECT_FALSE(array.search(66)) <<
      errorString("should not be able to find 66 in " + array.toString());
}

TEST(searchTest, LastElementFound) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.append(44);
   EXPECT_TRUE(array.search(11)) <<
      errorString("should find 11 in " + array.toString());
}

TEST(searchTest, MiddleElementFound) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.append(44);
   array.append(55);
   EXPECT_TRUE(array.search(22)) <<
      errorString("should find 22 in " + array.toString());
   EXPECT_TRUE(array.search(33)) <<
      errorString("should find 33 in " + array.toString());
   EXPECT_TRUE(array.search(44)) <<
      errorString("should find 44 in " + array.toString());
}

TEST(searchTest, RepeatsFound) {
   GArray array;
   EXPECT_FALSE(array.search(1)) <<
      errorString("should not be able to find 55 in " + array.toString());
   array.append(11);
   EXPECT_TRUE(array.search(11)) <<
      errorString("should find 11 in " + array.toString());
   array.append(11);
   EXPECT_TRUE(array.search(11)) <<
      errorString("should find 11 in " + array.toString());
   array.append(22);
   EXPECT_TRUE(array.search(22)) <<
      errorString("should find 22 in " + array.toString());
   EXPECT_TRUE(array.search(11)) <<
      errorString("should find 11 in " + array.toString());
}

//-----------------------------------------------------------------
// firstTest...depends on append
//-----------------------------------------------------------------
TEST(firstTest, EmptyArray) {
   GArray array;
   EXPECT_EQ(GArray::NADA, array.first()) << 
      errorString("an empty array has an undefined value");
}

TEST(firstTest, OneElement) {
   GArray array;
   array.append(17);
   EXPECT_EQ(17, array.first());
}

TEST(firstTest, MoreElements) {
   GArray array;
   array.append(1);
   EXPECT_EQ(1, array.first());
   array.append(2);
   EXPECT_EQ(1, array.first());
   array.append(3);
   EXPECT_EQ(1, array.first());
   array.append(4);
   EXPECT_EQ(1, array.first());
   array.append(5);
   EXPECT_EQ(1, array.first());
}

//-----------------------------------------------------------------
// lastTest...depends on append
//-----------------------------------------------------------------
TEST(lastTest, EmptyArray) {
   GArray array;
   EXPECT_EQ(GArray::NADA, array.last()) << 
      errorString("an empty array has as last an undefined value");
}

TEST(lastTest, OneElement) {
   GArray array;
   array.append(22);
   EXPECT_EQ(22, array.last());
}

TEST(lastTest, MoreElements) {
   GArray array;
   array.append(1);
   EXPECT_EQ(1, array.last());
   array.append(2);
   EXPECT_EQ(2, array.last());
   array.append(3);
   EXPECT_EQ(3, array.last());
   array.append(4);
   EXPECT_EQ(4, array.last());
   array.append(5);
   EXPECT_EQ(5, array.last());
}

//-----------------------------------------------------------------
// equalsTest...depends on append and the constructor
//-----------------------------------------------------------------
TEST(equalsTest, EmptyArrays) {
   GArray aArray, bArray;
   EXPECT_TRUE(aArray == bArray) << 
      errorString("two empty arrays are equal");
}

TEST(equalsTest, OneArrayWithAnElementFail) {
   GArray aArray, bArray;
   aArray.append(7);
   EXPECT_FALSE(aArray == bArray) << 
      errorString("one array does have an element");
   EXPECT_FALSE(bArray == aArray) << 
      errorString("one array does have an element");
}

TEST(equalsTest, Length1DifferentValuesFail) {
   GArray aArray, bArray;
   aArray.append(7);
   bArray.append(-2);
   EXPECT_FALSE(aArray == bArray) << 
      errorString("different values in arrays");
   EXPECT_FALSE(bArray == aArray) << 
      errorString("different values in arrays");
}

TEST(equalsTest, SameLengthDifferentValuesFail) {
   GArray aArray, bArray;
   aArray.append(7);
   aArray.append(10);
   bArray.append(-2);
   bArray.append(3);
   EXPECT_FALSE(aArray == bArray) << 
      errorString("different values in arrays of length 2");
   EXPECT_FALSE(bArray == aArray) << 
      errorString("different values in arrays of length 2");
}

TEST(equalsTest, SameLengthSameValuesDifferentOrderFail) {
   GArray aArray, bArray;
   aArray.append(2);
   aArray.append(3);
   aArray.append(4);
   bArray.append(4);
   bArray.append(3);
   bArray.append(2);
   EXPECT_FALSE(aArray == bArray) << 
      errorString("same values in arrays of length 2");
   EXPECT_FALSE(bArray == aArray) << 
      errorString("same values in arrays of length 2");
}

TEST(equalsTest, Samel) {
   GArray aArray, bArray;
   aArray.append(1);
   aArray.append(2);
   aArray.append(3);
   aArray.append(4);
   aArray.append(5);
   bArray.append(1);
   bArray.append(2);
   bArray.append(3);
   bArray.append(4);
   bArray.append(5);
   EXPECT_TRUE(aArray == bArray) << 
      errorString("same values in the same order");
   EXPECT_TRUE(bArray == aArray) << 
      errorString("same values in the same order");
}

//-----------------------------------------------------------------
// reverseTest...depends on append and toString
// some tests depend on the GArray operator ==
//-----------------------------------------------------------------
TEST(reverseTest, EmptyArray) {
   GArray array;
   array.reverse();
   EXPECT_EQ("{ }", array.toString()) << 
      errorString("reversing an empty array give an empty array");
}

TEST(reverseTest, OneElement) {
   GArray array;
   array.append(11);
   array.reverse();
   EXPECT_EQ("{ 11 }", array.toString());
}

TEST(reverseTest, TwoElements) {
   GArray array;
   array.append(11);
   array.append(22);
   array.reverse();
   EXPECT_EQ("{ 22 11 }", array.toString());
}

TEST(reverseTest, ThreeElements) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.reverse();
   EXPECT_EQ("{ 33 22 11 }", array.toString());
}

TEST(reverseTest, SevenElements) {
   GArray array;
   array.append(11);
   array.append(22);
   array.append(33);
   array.append(44);
   array.append(55);
   array.append(66);
   array.append(77);
   array.reverse();
   EXPECT_EQ("{ 77 66 55 44 33 22 11 }", array.toString());
}

TEST(reverseTest, TwoElementsEqualArrays) {
   GArray array;
   array.append(22);
   array.append(11);
   array.reverse();

   GArray otherArray;
   otherArray.append(11);
   otherArray.append(22);
   EXPECT_TRUE(array == otherArray) <<
      errorString(array.toString()  + " should have been operator == to " + otherArray.toString());
}

TEST(reverseTest, FiveElementsEqualArrays) {
   GArray array;
   array.append(55);
   array.append(44);
   array.append(33);
   array.append(22);
   array.append(11);
   array.reverse();

   GArray otherArray;
   otherArray.append(11);
   otherArray.append(22);
   otherArray.append(33);
   otherArray.append(44);
   otherArray.append(55);
   EXPECT_TRUE(array == otherArray) <<
      errorString(array.toString()  + " should have been operator == to " + otherArray.toString());
}

TEST(reverseTest, FourElementsEqualArrays) {
   GArray array;
   array.append(44);
   array.append(33);
   array.append(22);
   array.append(11);
   array.reverse();

   GArray otherArray;
   otherArray.append(11);
   otherArray.append(22);
   otherArray.append(33);
   otherArray.append(44);
   EXPECT_TRUE(array == otherArray) <<
      errorString(array.toString()  + " should have been operator == to " + otherArray.toString());
}

//-----------------------------------------------------------------
// copyConstructor...depends on append, remove and toString
//-----------------------------------------------------------------
TEST(copyConstructorTest, EmptyArray) {
   GArray array;
   GArray otherArray = array; // calls the copy constructor
   EXPECT_EQ(array.toString(), otherArray.toString()) <<
      errorString("failed to copy an empty array properly");
}

//-----------------------------------------------------------------
// overloadedAssignmentOperatorTest...depends on append, search, and toString
//-----------------------------------------------------------------
TEST(overloadedAssignmentOperatorTest, EmptyArray) {
   GArray array;
   GArray otherArray;
   array = otherArray;
   EXPECT_EQ(array.toString(), otherArray.toString()) <<
      errorString("the overloaded assignment operator failed for empty arrays");
}

TEST(overloadedAssignmentOperatorTest, ArraysWithOneElement) {
   GArray array; 
   GArray rtSideArray;
   array.append(17);
   ASSERT_TRUE(array.search(17)) << 
      errorString("should find 17 => original array not built properly");
   ASSERT_FALSE(rtSideArray.search(17)) << 
      errorString("should NOT find 17 in the empty rtSideArray => rtSideArray not built properly");

   rtSideArray.append(99);
   ASSERT_TRUE(rtSideArray.search(99)) << 
      errorString("should find 99 => append on rtSideArray failed");
   ASSERT_FALSE(array.search(99)) << 
      errorString("should NOT find 99 in array because it was rtSideArray that was changed");

   array = rtSideArray;

   EXPECT_EQ(array.toString(), rtSideArray.toString()) <<
      errorString("failed in the overloading of =");
   EXPECT_FALSE(array.search(17)) << 
      errorString("should NO LONGER find 17");
   EXPECT_TRUE(rtSideArray.search(99)) << 
      errorString("should find 99");
   EXPECT_TRUE(array.search(99)) << 
      errorString("should find 99 which was copied from rtSideArray");
}

//-----------------------------------------------------------------
// destructorTest...depends on append and toString
//-----------------------------------------------------------------
TEST(destructorTest, EmptyArray) {
   {
      GArray array;
      ASSERT_TRUE(array.isEmpty()) << 
         errorString("should be empty => destructor test aborted");
      // the destructor is called, array is going out of scope
   }
   GArray array;
   EXPECT_TRUE(array.isEmpty()) << 
      errorString("the destructor should have returned the memory");
   EXPECT_EQ("{ }", array.toString()) <<
      errorString("the array should be empty again");
}

TEST(destructorTest, ArrayWithElements) {
   {
      GArray array;
      array.append(1);
      array.append(2);
      array.append(3);
      ASSERT_FALSE(array.isEmpty()) << 
         errorString("array should not be empty => destructor test aborted");
      // the destructor is called, array is going out of scope
   }
   GArray array;
   EXPECT_TRUE(array.isEmpty()) << 
      errorString("the destructor should have returned the memory");
   EXPECT_EQ("{ }", array.toString()) <<
      errorString("the array should be empty again");
}

TEST(destructorTest, WithPointer) {
   GArray* p = new GArray;
   ASSERT_TRUE(p->isEmpty())  << 
      errorString("array pointed to should be empty => destructor test aborted");
   p->append(1);
   p->append(2);
   p->append(3);
   p->append(4);
   p->append(5);
   delete p; // calling the destructor
   p = new GArray;
   EXPECT_TRUE(p->isEmpty())  << 
      errorString("array pointed to should be empty");
   EXPECT_EQ("{ }", p->toString()) <<
      errorString("the array should be empty again");
   delete p; // calling the destructor .... it should not crash!
}

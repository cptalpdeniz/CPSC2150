// A unit test for Langara CPSC 2150 
// Assignment 2: Linked List
// C++ unit test framework: google test
// Author: Gladys Monagan
// September 2020
// Name: 

#include "LList.h"
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
   LList list;
   EXPECT_EQ("[" + LList::DELIMITER + "]", list.toString()) <<
      errorString("the constructor should have made an empty list");
}

//-----------------------------------------------------------------
// isEmptyTest
//-----------------------------------------------------------------
TEST(isEmptyTest, EmptyList) {
   LList list;
   EXPECT_TRUE(list.isEmpty()) << 
      errorString("A new list should be empty");
}

//-----------------------------------------------------------------
// consTest...depends on toString
//-----------------------------------------------------------------
TEST(consTest, OneElement) {
   LList list;
   list.cons(11);
   EXPECT_EQ("[" + LList::DELIMITER 
      + "11" + LList::DELIMITER 
      + "]", list.toString());
}

TEST(consTest, TwoElements) {
   LList list;
   list.cons(22);
   list.cons(11);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER
      + "]", list.toString());
}

//-----------------------------------------------------------------
// lengthTest...depends on cons and append
//-----------------------------------------------------------------
TEST(lengthTest, EmptyList) {
   LList list;
   EXPECT_EQ(0, list.length()) << 
      errorString("A new list should have a length of 0");
}

TEST(lengthTest, TwoElementsConsAppend) {
   LList otherList;
   otherList.append(44);
   otherList.cons(33);
   EXPECT_EQ(2, otherList.length()) << 
      errorString("length should be 2, after appending 2 items.");
}

//-----------------------------------------------------------------
// searchTest...depends on cons and toString
//-----------------------------------------------------------------
TEST(searchTest, EmptyListFail) {
   LList list;
   EXPECT_FALSE(list.search(11)) << 
      errorString("should not able to find in an empty List.");
}

//-----------------------------------------------------------------
// firstTest...depends on cons and append
//-----------------------------------------------------------------
TEST(firstTest, EmptyList) {
   LList list;
   EXPECT_EQ(LList::NOT_DEFINED, list.first()) << 
      errorString("an empty list has an undefined value");
}

TEST(firstTest, OneElementWithCons) {
   LList list;
   list.cons(19);
   EXPECT_EQ(19, list.first());
}

TEST(firstTest, MoreElementsWithAppend) {
   LList list;
   list.append(1);
   list.append(2);
   list.append(3);
   list.append(4);
   list.append(5);
   list.append(6);
   list.append(7);
   EXPECT_EQ(1, list.first());
}

//-----------------------------------------------------------------
// lastTest...depends on cons and append
//-----------------------------------------------------------------
TEST(lastTest, MoreElementsWithAppend) {
   LList list;
   list.append(1);
   list.append(2);
   list.append(3);
   list.append(4);
   list.append(5);
   list.append(6);
   list.append(7);
   EXPECT_EQ(7, list.last());
}
//-----------------------------------------------------------------
// removeTest...depends on cons and toString 
// two possible errors: the return value is wrong and/or the element is not removed
//-----------------------------------------------------------------
TEST(removeTest, OneElementFail) {
   LList list;
   list.cons(99);
   EXPECT_FALSE(list.remove(11)) << 
      errorString("succeeded in removing 11 from " + list.toString());
}

TEST(removeTest, LastElementSuccess) {
   LList list;
   list.append(1);
   list.append(2);
   list.append(3);
   list.append(4);
   list.append(5);
   list.append(6);
   list.append(7);

   list.remove(7);

   EXPECT_EQ("[" + LList::DELIMITER 
      + "1" + LList::DELIMITER 
      + "2" + LList::DELIMITER 
      + "3" + LList::DELIMITER 
      + "4" + LList::DELIMITER 
      + "5" + LList::DELIMITER 
      + "6" + LList::DELIMITER 
      + "]", list.toString());
}

//-----------------------------------------------------------------
// spliceTest...depends on cons and toString
//-----------------------------------------------------------------
TEST(spliceTest, ListsWithElementsPos2) {
   LList list;
   list.cons(77);
   list.cons(66);
   list.cons(22);
   list.cons(11);
   LList otherList;
   otherList.cons(55);
   otherList.cons(44);
   otherList.cons(33);
   list.splice(otherList, 2);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "44" + LList::DELIMITER
      + "55" + LList::DELIMITER
      + "66" + LList::DELIMITER
      + "77" + LList::DELIMITER
      + "]", list.toString());
   EXPECT_EQ("[" + LList::DELIMITER + "]", otherList.toString());
   EXPECT_TRUE(otherList.isEmpty());
}

TEST(spliceTest, FirstListWithOneElementPos1) {
   LList list;
   list.cons(11);
   LList otherList;
   otherList.cons(44);
   otherList.cons(33);
   otherList.cons(22);
   list.splice(otherList, 1);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "44" + LList::DELIMITER
      + "]", list.toString());
   EXPECT_EQ("[" + LList::DELIMITER + "]", otherList.toString());
   EXPECT_TRUE(otherList.isEmpty());
}

TEST(spliceTest, SecondListWithOneElementPos1) {
   LList list;
   list.cons(44);
   list.cons(33);
   list.cons(11);
   LList otherList;
   otherList.cons(22);
   list.splice(otherList, 1);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "44" + LList::DELIMITER
      + "]", list.toString());
   EXPECT_EQ("[" + LList::DELIMITER + "]", otherList.toString());
   EXPECT_TRUE(otherList.isEmpty());
}

TEST(spliceTest, ListsWithElementsPosTooBig) {
   LList list;
   list.cons(44);
   list.cons(33);
   list.cons(22);
   list.cons(11);
   LList otherList;
   otherList.cons(77);
   otherList.cons(66);
   otherList.cons(55);
   list.splice(otherList, 24);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "44" + LList::DELIMITER
      + "55" + LList::DELIMITER
      + "66" + LList::DELIMITER
      + "77" + LList::DELIMITER
      + "]", list.toString()) <<
      errorString("pos=24 >= list.length() so append the otherList to the end");
   EXPECT_EQ("[" + LList::DELIMITER + "]", otherList.toString());
   EXPECT_TRUE(otherList.isEmpty());
}

TEST(spliceTest, FirstEmptyListPosition0) {
   LList list;
   LList otherList;
   otherList.cons(33);
   otherList.cons(22);
   otherList.cons(11);
   list.splice(otherList, 0);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "]", list.toString());
   EXPECT_EQ("[" + LList::DELIMITER + "]", otherList.toString());
   EXPECT_TRUE(otherList.isEmpty());
}

TEST(spliceTest, OtherEmptyListPosition3) {
   LList list;
   list.cons(33);
   list.cons(22);
   list.cons(11);
   LList otherList;
   list.splice(otherList, 3);
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "]", list.toString());
   EXPECT_EQ("[" + LList::DELIMITER + "]", otherList.toString());
   EXPECT_TRUE(otherList.isEmpty());
}

//-----------------------------------------------------------------
// equalsTest...depends on cons, append and the constructor
//-----------------------------------------------------------------
TEST(equalsTest, OneListWithAnElementFail) {
   LList aList, bList;
   aList.cons(7);
   EXPECT_FALSE(aList == bList) << 
      errorString("one list does have an element");
   EXPECT_FALSE(bList == aList) << 
      errorString("one list does have an element");
}

TEST(equalsTest, Length1DifferentValuesFail) {
   LList aList, bList;
   aList.cons(7);
   bList.cons(-2);
   EXPECT_FALSE(aList == bList) << 
      errorString("different values in lists");
   EXPECT_FALSE(bList == aList) << 
      errorString("different values in lists");
}

//-----------------------------------------------------------------
// reverseTest...depends on cons and toString
// some tests depend on the LList operator ==
//-----------------------------------------------------------------
TEST(reverseTest, EmptyList) {
   LList list;
   list.reverse();
   EXPECT_EQ("[" + LList::DELIMITER + "]", list.toString()) << 
      errorString("reversing an empty list give an empty list");
}

TEST(reverseTest, OneElement) {
   LList list;
   list.cons(11);
   list.reverse();
   EXPECT_EQ("[" + LList::DELIMITER 
      + "11" + LList::DELIMITER 
      + "]", list.toString());
}

TEST(reverseTest, TwoElementsToString) {
   LList list;
   list.cons(11);
   list.cons(22);
   list.reverse();
   EXPECT_EQ("[" + LList::DELIMITER 
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "]", list.toString());
}

TEST(reverseTest, ThreeElementsToString) {
   LList list;
   list.cons(11);
   list.cons(22);
   list.cons(33);
   list.reverse();
   EXPECT_EQ("[" + LList::DELIMITER 
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "]", list.toString());
}

TEST(reverseTest, FourElementsToString) {
   LList list;
   list.cons(11);
   list.cons(22);
   list.cons(33);
   list.cons(44);
   list.reverse();
   EXPECT_EQ("[" + LList::DELIMITER
      + "11" + LList::DELIMITER 
      + "22" + LList::DELIMITER 
      + "33" + LList::DELIMITER
      + "44" + LList::DELIMITER
      + "]", list.toString());
}

TEST(reverseTest, TwoElementsEqualLists) {
   LList list;
   list.cons(11);
   list.cons(22);
   list.reverse();

   LList otherList;
   otherList.append(11);
   otherList.append(22);
   EXPECT_TRUE(list == otherList) <<
      errorString(list.toString()  + " should have been equal to " + otherList.toString());
}

//-----------------------------------------------------------------
// copyConstructor...depends on cons, remove and toString
//-----------------------------------------------------------------
TEST(copyConstructorTest, EmptyList) {
   LList list;
   LList otherList = list; // calls the copy constructor
   EXPECT_EQ(list.toString(), otherList.toString()) <<
      errorString("failed to copy an empty list properly");
}

TEST(copyConstructorTest, ListWithElements) {
   LList list;
   list.cons(33);
   list.cons(22);
   list.cons(11);
   LList copiedList(list); // calls the copy constructor 
   EXPECT_EQ(list.toString(), copiedList.toString()) <<
      errorString("failed to copy the list properly");

   // modify original list which should then be different from copiedList's
   EXPECT_TRUE(list.remove(22));
   EXPECT_TRUE(list.remove(33));
   EXPECT_NE(list.toString(), copiedList.toString()) <<
      errorString("copying of list was not done properly");
}

//-----------------------------------------------------------------
// overloadedAssignmentOperatorTest...depends on cons, remove and toString
//-----------------------------------------------------------------

TEST(overloadedAssignmentOperatorTest, ListWithOneElementRemove) {
   LList list;
   LList rtSideList;
   list.cons(17);
   rtSideList.cons(17);
   list = rtSideList;
   ASSERT_EQ(list.toString(), rtSideList.toString());
   EXPECT_TRUE(rtSideList.remove(17));
   EXPECT_NE(list.toString(), rtSideList.toString());
}

//-----------------------------------------------------------------
// destructorTest...depends on cons and toString
//-----------------------------------------------------------------
TEST(destructorTest, WithPointer) {
   LList* p = new LList;
   ASSERT_TRUE(p->isEmpty())  << 
      errorString("list pointed to should be empty => destructor test aborted");
   p->cons(1);
   p->cons(2);
   p->cons(3);
   p->cons(4);
   p->cons(5);
   delete p; // calling the destructor
   p = new LList;
   EXPECT_TRUE(p->isEmpty())  << 
      errorString("list pointed to should be empty");
   EXPECT_EQ("[" + LList::DELIMITER + "]", p->toString()) <<
      errorString("the list should be empty again");
   delete p; // calling the destructor .... it should not crash!
}

/*
*   Alp Deniz Senyurt
*   100342433
*   CPSC2150 - W02
*/


// CPSC 2150 started by Gladys Monagan based on sample1_unittest.cc
// which is copyrighted 2005, Google Inc.

// A sample program demonstrating using Google C++ testing framework.

// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "labFcts.h"

// you could put all your code in a namespace
// if you want to do so, uncomment the next line
// namespace{

// from faq.md
// So for simplicity, we just ask the users to avoid `_` in `TestSuiteName` and
// `TestName`. The rule is more constraining than necessary, but it's simple and
// easy to remember. It also gives googletest some wiggle room in case its
// implementation needs to change in the future.


// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.

  // <TechnicalDetails>
  //
  // EXPECT_EQ(expected, actual) is the same as
  //
  //   EXPECT_TRUE((expected) == (actual))


TEST(searchTest, OddArraySize1Found) {
   int A[] = { 11 };
   EXPECT_TRUE(search(11, A, 1));
}

TEST(searchTest, OddArraySize1Fail) {
   int A[] = { 11 };
   EXPECT_FALSE(search(22, A, 1));
}

TEST(searchTest, OddArraySize3Found) {
   int A[] = { 11, 33, 22 };
   EXPECT_TRUE(search(11, A, 3));
   EXPECT_TRUE(search(33, A, 3));
   EXPECT_TRUE(search(22, A, 3));
}

TEST(searchTest, OddArraySize3Fail) {
   int A[] = { 11, 33, 22 };
   EXPECT_FALSE(search(9, A, 3));
 }

 TEST(searchTest, EmptyArray) { // boundary case
   int A[] = { 11 };
   EXPECT_FALSE(search(11, A, 0));
}

 TEST(searchTest, EvenArraySize2Found) {
   int A[] = { 11, 12 };
   EXPECT_TRUE(search(11, A, 2));
}

 TEST(searchTest, EvenArraySize2Fail) {
   int A[] = { 11, 12 };
   EXPECT_FALSE(search(23, A, 2));
}

 TEST(searchTest, EvenArraySize4Found) {
   int A[] = { 11, -2, 88, 37 };
   EXPECT_TRUE(search(88, A, 4));
}

 TEST(searchTest, EvenArraySize4Fail) {
   int A[] = { 11, -2, 88, 37 };
   EXPECT_FALSE(search(93, A, 4));
}

// closing brace of the namespace
// } 

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?

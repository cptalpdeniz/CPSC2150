/* 
* Assignment #2, CPSC 2150, Test Program
* Gladys Monagan
* Testing does not depend on google test
*/
#include "LList.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void testOverloadedAssignment() {
   LList a;
   a.cons(1);
   a.append(2);

   LList b;
   b.cons(3);
   b = a;

   cout << "\na and b should be identical (as well as the internal representation)\n";
   cout << "a = " << a.toString() << endl;
   cout << "b = " << b.toString() << endl;
   cout << b.toString() << endl;

   cout << "\nadd only to b a few elements\n";
   b.append(11);
   b.append(12);
   b.append(13);
   b.append(14);
   cout << "\na and b differ now\n";
   cout << "expected a = [ 1 2 ]\n";
   cout << a.toString() << endl;
   cout << "expected b = [ 1 2 11 12 13 14 ]\n";
   cout << b.toString() << endl;
}

// test copy constructor, pass list by value
// the values of the list being passed is hardcoded to be [ 11 22 33 55 ]
void testCopyConstructor(LList other) {
   cout << "\n\tinside of the function testCopyConstructor ... copy made\n\t";
   cout << other.toString() << endl;
   cout << "\n\tremove 22 from the copy \n";
   if (!other.remove(22)) {
      cout << "\tERROR: removed 22 should have returned true\n";
   }
   cout << "\tremove 11 from the copy \n";
   if (!other.remove(11)) {
      cout << "\tERROR: removed 11 should have returned true\n";
   }
   cout << "\tremove 55 from the copy \n";
   if (!other.remove(55)) {
      cout << "\tERROR: removed 55 should have returned true\n";
   }
   cout << "\tcons 22 to the copy \n";
   other.cons(22);
   cout << "\texpecting [ 22 33 ] -- inside of the function \n\t";
   cout << other.toString() << endl;
   cout << "\n\treturning from the function testCopyConstructor\n";
}

// test consing onto the list
void testCons(LList& p, short x, string result) {
   cout << endl; 
   p.cons(x);
   cout << "consed '" << x << "' expecting: " << result << "\n";
   cout << p.toString() << endl; 
}

// see if removing x from the LList p is correct
void testRemove(LList& p, short x, string result) {
   cout << endl;
   if (p.remove(x)) {
      cout << "removed '" << x << "' expecting: " << result << "\n";
   }
   else {
      cout << "ERROR: removed '" << x << "' should have returned true\n";
   }
   cout << p.toString() << endl ;
}

// test appending onto the list .... it should succeed
void testAppend(LList& p, short x, string result) {
   cout << endl;
   p.append(x);
   cout << "appended '" << x << "' expecting: " << result << "\n";
   cout << p.toString() << endl;
}

void testSearch(LList& p, short x, bool expectedValue) {
   cout << endl;
   cout << "searching for " << x << " in " << p.toString();
   if (expectedValue) {
      if (p.search(x))
         cout << " search as expected";
      else
         cout << " NOT search which is an ERROR!!!!";
   }
   else {
      if (!p.search(x))
         cout << " NOT search as expected";
      else
         cout << " search which is an ERROR!!!!";
   }
   cout << endl;
}

int main() {
   // use the default constructor
   LList p;
   cout << "expecting [ ]\n";
   cout << p.toString() << endl;
   
   // 1 new list is an empty list
   cout << endl;
   if (p.isEmpty()) {
      cout << "p is empty as expected\n";
   }
   else {
      cout << "ERROR: p should have been empty\n";
   } 

   // insert into an empty list
   testCons(p, 3, "[ 3 ]");
   testCons(p, 2, "[ 2 3 ]");
   testCons(p, 1, "[ 1 2 3 ]");

   testSearch(p, 1, true);
   testSearch(p, 2, true);
   testSearch(p, 3, true);

   // test remove from middle of list
   testRemove(p, 2, "[ 1 3 ]");
 
   // remove 1 from the beginning of the list
   testRemove(p, 1, "[ 3 ]");

   // remove 3 as the single element
   testRemove(p, 3, "[ ]");
   
   // testing append into an empty list
   testAppend(p, 11, "[ 11 ]");
   testAppend(p, 22, "[ 11 22 ]");
   testAppend(p, 33, "[ 11 22 33 ]");
   testAppend(p, 44, "[ 11 22 33 44 ]");
   testAppend(p, 55, "[ 11 22 33 44 55 ]");

   // copy constructor
   LList q = LList(p);
   
   // remove a middle element of the list
   testRemove(p, 44, "[ 11 22 33 55 ]");

   if (q == p) {
      cout << "oh my! p and q are equal but p should no longer have 44\n";
   }
   else {
      cout << "p and q are different as expected";
   }
   
   // look for a removed element
   testSearch(p, 44, false);
  
   // test the copy constructor
   cout << "\nbefore the copy constructor is called\n";
   cout << p.toString() << endl;
   testCopyConstructor(p);   
   cout << "\nafter the copy constructor the original is still\n";
   cout << p.toString() << endl;
  
   // remove 11 from original
   testRemove(p, 11, "[ 22 33 55 ]");

   testOverloadedAssignment();
   
   // the destructors are called as p and q go out of scope
  
   return 0;
}


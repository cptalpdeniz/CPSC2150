/* 
Lab
Test Program of a growing array that does not use google test
Gladys Monagan, September 2020
*/
#include "GArray.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

void testOverloadedAssignment() {
   GArray a;
   a.append(1);
   a.append(2);
   a.append(3);
   a.append(4);
   cout << "a = " << a.toString() << endl;

   GArray b;
   b.append(300);
   b.append(200);
   cout << "b = " << b.toString() << endl;

   cout << "b = a \n";
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
   cout << "expected a = { 1 2 3 4 }\n";
   cout << a.toString() << endl;
   cout << "expected b = { 1 2 3 4 11 12 13 14 }\n";
   cout << b.toString() << endl;
}

void testFound(GArray& p, short x, bool expectedValue) {
   cout << "searching for " << x << " in " << p.toString();
   if (expectedValue) {
      if (p.search(x))
         cout << " found as expected";
      else
         cout << " NOT found which is an ERROR!!!!";
   }
   else {
      if (!p.search(x))
         cout << " NOT found as expected";
      else
         cout << " found which is an ERROR!!!!";
   }
   cout << endl;
}

// test copy constructor, pass gArray by value
// the values of the gArray being passed is hardcoded to be { 11 22 33 44 55 }
void testCopyConstructor(GArray other) {
   cout << "\n\tinside of the function testCopyConstructor ... copy made\n\t";
   cout << other.toString() << endl;
   cout << "\n\tappend 66 to the copy \n";
   other.append(66);
   
   cout << "\texpecting { 11 22 33 44 55 66 } -- inside of the function \n\t";
   cout << other.toString() << endl;
   cout << "\t";
   testFound(other, 66, true);
   cout << "\n\treturning from the function testCopyConstructor\n";
}

// test appending onto the gArray .... it should succeed
void testAppend(GArray& p, short x, string result) {
   cout << endl;
   p.append(x);
   cout << "appended '" << x << "' expecting: " << result << "\n";
   cout << p.toString() << endl;
}


int main() {
   // use the default constructor
   GArray p;
   cout << "expecting { }\n";
   cout << p.toString() << endl;
   
   // 1 new gArray is an empty gArray
   cout << endl;
   if (p.isEmpty()) {
      cout << "p is empty as expected\n";
   }
   else {
      cout << "ERROR: p should have been empty\n";
   } 

  // testing append into an empty gArray
   testAppend(p, 11, "{ 11 }");
   testAppend(p, 22, "{ 11 22 }");
   testAppend(p, 33, "{ 11 22 33 }");
   testAppend(p, 44, "{ 11 22 33 44 }");

   testFound(p, 11, true);
   testFound(p, 22, true);
   testFound(p, 33, true);
   testFound(p, 99, false);

   // copy constructor
   GArray q = GArray(p);
   
   testAppend(p, 55, "{ 11 22 33 44 55 }");

   if (q == p) {
      cout << "oh my! p and q are equal but p should have 55 at the end\n";
   }
   else {
      cout << "p and q are different as expected\n";
   }
   
   // look for 55 which should only be in p and NOT in q removed element
   testFound(p, 55, true);
   testFound(q, 55, false);
  
   // test the copy constructor
   cout << "\nbefore the copy constructor is called\n";
   cout << p.toString() << endl;
   testCopyConstructor(p);   
   cout << "\nafter the copy constructor the original is still\n";
   cout << p.toString() << endl;
   testFound(p, 66, false);
  
   testOverloadedAssignment();
   
   // the destructors are called as p and q go out of scope
  
   return 0;
}


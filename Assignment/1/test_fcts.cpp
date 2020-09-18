/* 
   a small sample test that does not use google test -- ridiculously small
   Gladys Monagan, CPSC 2150, September 9, 2020
*/ 
#include <iostream>
#include <string>
#include <bitset>
#include "fcts.h"

using std::string;
using std::cout;
using std::endl;

int main() {
   unsigned int n = 1025;
   std::bitset<32> binary(n);
   // code to remove leading zeros comes from
   // http://www.cplusplus.com/forum/beginner/154369/
   auto binaryString  = binary.to_string(); 
    
   // http://en.cppreference.com/w/cpp/string/basic_string/find
   auto firstOne = binaryString.find('1') ; // find the first '1'

   if( firstOne != std::string::npos ) { // found at least one '1'
      // get the substring that starts at firstOne
      binaryString = binaryString.substr(firstOne);
      // http://en.cppreference.com/w/cpp/string/basic_string/substr
   }
   else {
      binaryString = "0" ; // all the bits were zeroes
   }

   string myString = toBinaryString(n);
   cout << "toBinaryString(" << n << ") = " << myString; 
   if (myString != binaryString) {
      cout << " but expecting " << binaryString << "  !!!!!!!!";
   }
   cout << endl;

   return 0;
}

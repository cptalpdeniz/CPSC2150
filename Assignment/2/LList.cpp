/* 
Name:
Student Number: 
Assignment #2, CPSC 2150 (expand code started by Gladys Monagan)
*/

#include "LList.h"
#include <string>
#include <sstream>

using std::string;

const string LList::DELIMITER = string(" ");

// ASSIGNMENT requirement:
// initialize NOT_DEFINED

// constructor with no arguments, makes an empty list
// code can be modified below if you choose to have a dummy head node
LList::LList() {
   this->head = nullptr;  
}

// make a string from the values of the list in this->head and return it
// precondition:
//   LList::DELIMETER has been initialized
// postcondition:
//    return a string of the form 
//          [ DELIMITER element DELIMITER ... element DELIMITER ]
// code needs to be modified if you choose to have a dummy head node
string LList::toString() const {
   string str = "[";
   str += toString(this->head, DELIMITER);
   str += "]";
   return str;
}

// make a string from the elements in p using the delimiter to separated the elements
// postcondition:
//    return a string of the form 
//         [ delimiter element ... element delimiter element delimiter ]
string LList::toString(Node * p, string delimiter) {
   if (p == nullptr) {
      return delimiter;
   }
   std::stringstream ss;
   ss << delimiter;
   ss << p->item;
   ss << toString(p->link, delimiter);
   return ss.str();
}

// destructor
// ASSIGNMENT requirement:
// finish the comment on postcondition:
// postcondition: 
LList::~LList(){
   // NEEDS code .... empty for now
}

// Program to use (test) univariate polynomials with a user interface. 
// Commands supported 
// -> input two polynomials
// -> calculate their sum
// -> get the coefficients of some terms
// -> get the degree of the polynomial
// -> evaluate the polynomial given a specific value for x.
// -> get the number of terms in the polynomial
// -> possibly differentiate
// All the input from a user comes from standard input (std::cin) and the output
// with results and questions for the user are done to standard output (std::cout).

// usage: polyMath -batch < inFile.txt > outFile.txt
// to run program non-interactively obtaining data from inFile.txt
// putting the output into outFile.txt
//
// usage: polyMath
// renders an interactive session with commands

// Author: Gladys Monagan (with material from Jian hua Pan)
// DO NOT POST THIS ANYWHERE.
// This code is copyrighted.
// Use it exclusively for CPSC 2150 at Langara College in Vancouver

#include "Univariate.h"
#include "Commands.h"
#include <functional> // std::greater
#include <map>        // std::map
#include <iostream>   // std::cout std::cin
#include <string>     // std::string
using std::cout, std::string, std::cin;


// output to standard output a polynomial with its label
// precondition:
//    the operator << has been overloaded for Univariate
void printPoly(const string& label, const Univariate& poly) {
   cout << label << " = " << poly << "\n";
}

// output to standard output the polynomial's degree with its label
void printDegree(const string& label, const Univariate& poly) {
   cout << "degree of " << label << " = " << poly.degree() << "\n";
}

// output to standard output the polynomials a and b
// precondition:
//    aPoly, bPoly are bona fide polynomials 
//    (including the zero polynomial)
void printPolys(const Univariate& aPoly, const Univariate& bPoly) {
   printPoly("a", aPoly);
   printPoly("b", bPoly);
   printDegree("a", aPoly);
   printDegree("b", bPoly);
}

void differentiate(const Univariate& aPoly, const Univariate& bPoly) {
   cout << "********************differentiate is not implemented*********\n";
   // printPoly("da/dx", aPoly.differentiate());
   // printPoly("db/dx", bPoly.differentiate());
   printPoly("da/dx", aPoly);
   printPoly("db/dx", bPoly);
}

// output to standard output the coefficient and degree with a blurb
void printCoeffDegree(string label, int coefficient, int degree) {
   cout << "in " << label << ", " << coefficient;
   cout << " is the coefficient of the term of degree " << degree << "\n";
}

// output to standard output the polynomials a, b and their sum 
// precondition:
//    aPoly, bPoly and sumPoly are bona fide polynomials 
//    (including the zero polynomial)
void printPolys(const Univariate& aPoly, const Univariate& bPoly, const Univariate& sumPoly) {
   printPoly("a", aPoly);
   printPoly("b", bPoly);
   printPoly("a+b", sumPoly);
   printDegree("a", aPoly);
   printDegree("b", bPoly);
   printDegree("a+b", sumPoly);
}

// output to standard output the number of terms of the aPoly, bPoly and sumPoly if validSum
// validSum means that sumPoly is a valid polynomial
// precondition:
//    aPoly, bPoly, sumPoly are bona fide polynomials 
//    (including the zero polynomial)
void numberOfTerms(const Univariate& aPoly, const Univariate& bPoly, 
                  const Univariate& sumPoly, bool validSum) {
   cout << aPoly.numberOfTerms() << " term(s) in a = " << aPoly << "\n";
   cout << bPoly.numberOfTerms() << " term(s) in b = " << bPoly << "\n";
   if (validSum)
      cout << sumPoly.numberOfTerms() << " term(s) in sum = " << sumPoly<<"\n";
}

// read from standard input the info on the first polynomial (polynomial a)
// if successful, read the info on the second polynomial (polynomial b)
// expected for each polynomial is
// -> the number of terms
// -> pairs of numbers corresponding to the coefficient of the term and the degree
// precondition:
//    aPoly, bPoly, sumPoly are the zero polynomials
//    the operator << has been defined for Univariates
//    reading into a polynomial consists of
//        an integer n for the number of terms
//        coefficient degree pairs n times    
// postcondition: 
//    aPoly, bPoly are bona fide polynomials 
//    the input stream cin is cleared in case of having read non-numeric input
bool inputUnivariates(Univariate& aPoly, Univariate& bPoly) {
   bool successfulRead = true;
   cout << "for polynomial a, enter # of terms,";
   cout << " then \"coefficient degree\" pairs:\n";
   if (!(std::cin >> aPoly)) {
      cout << "ERROR in reading polynomial a\n";
      successfulRead = false;
   }
   if (successfulRead) {
      cout << "for polynomial b, enter # of terms,";
      cout << " then \"coefficient degree\" pairs:\n";
      if (!(std::cin >> bPoly)) {
         cout << "ERROR in reading polynomial b\n";
         successfulRead = false;
      }
   }
   clearClean(cin);
   return successfulRead;
}

// read from standard input the degree of the term whose coefficients will be printed
// for aPoly, bPoly and sumPoly (if validSum is true)
// if validSum is true, that means that sumPoly is valid
// if notInteractive is true, the degree read is echoed to standard output
// postcondition:
//    the input stream cin is cleared in case of having read non-numeric input
void getCoeffs(const Univariate& aPoly, const Univariate& bPoly, 
               const Univariate& sumPoly, bool validSum, bool notInteractive) {
   do {
      int degree;
      cout << "enter degree of polynomial term whose coefficient is needed ";
      cin >> degree;
      if (notInteractive) cout << degree << "\n";
      printCoeffDegree("a", aPoly.coefficient(degree), degree);
      printCoeffDegree("b", bPoly.coefficient(degree), degree);
      if (validSum) printCoeffDegree("a+b", sumPoly.coefficient(degree), degree);
      cout << "continue getting coefficients? (y/n): ";
   } while (yesAnswer(notInteractive));
   clearClean(cin);
}

// read from standard input the value of x to use in evaluating the polynomials
// evaluate aPoly, bPoly and sumPoly (if validSum is true) with the given value of x 
// and output the results
// if validSum is true, that means that sumPoly is valid
// if notInteractive is true, the read read is echoed to standard output
// postcondition:
//    the input stream cin is cleared in case of having read non-numeric input
void evalPolys(const Univariate& aPoly, const Univariate& bPoly, 
               const Univariate& sumPoly, bool validSum, bool notInteractive) {
   do {
      double x;
      cout << "enter the value of x: ";
      cin >> x;
      if (notInteractive) cout << x << "\n";
      cout << "when x = " << x << "\n";
      cout << "a = " << aPoly << " = " << aPoly.evaluate(x) << "\n";
      cout << "b = " << bPoly << " = " << bPoly.evaluate(x) << "\n";
      if (validSum) cout << "a+b = " << sumPoly << " = " << sumPoly.evaluate(x) << "\n";
      cout << "evaluate for another value of x? (y/n) : ";
   } while (yesAnswer(notInteractive));
   clearClean(cin);
}

// process the command 
//   read into aPoly and bPoly 
//   compute the polynomial which is the sum of aPoly and bPoly
//   print aPoly, bPoly and sumPoly
//   evaluate aPoly, bPoly and sumPoly asking the user for the value of x
//   get the coefficients of terms in aPoly, bPoly and sumPoly 
//   get the number of terms in aPoly, bPoly and sumPoly
//   print to standard output if an error was made
//   read a comment (or document) and echo it if necessary
// postcondition:
//   return true when the command is RESET or QUIT, returns false otherwise
//   validSum is set to true if the command SUM is executed
// 
bool process(Commands command, bool notInteractive, Univariate& aPoly, 
             Univariate& bPoly, Univariate& sumPoly, bool& validSum) { 
   bool doneProcessing = false;
   switch (command) {
      case INPUT:
         // using the overloaded operator << of Univariate to enter info
         if (inputUnivariates(aPoly, bPoly)) printPolys(aPoly, bPoly);
         break;
      case SUM:
         validSum = true;
         sumPoly = aPoly + bPoly;
         printPolys(aPoly, bPoly, sumPoly);
         break;
      case PRINT:
         validSum ? printPolys(aPoly, bPoly, sumPoly) : printPolys(aPoly,bPoly);
         break;
      case EVALUATE:
         // ask the user for the values of x and evaluate the polynomials
         evalPolys(aPoly, bPoly, sumPoly, validSum, notInteractive);
         break;
      case GET_COEFF:
         // ask for the degree of the term whose coefficient will be returned
         getCoeffs(aPoly, bPoly, sumPoly, validSum, notInteractive);
         break;
      case NUMBER_OF_TERMS:
         // output the number of terms of each polynomial
         numberOfTerms(aPoly, bPoly, sumPoly, validSum);
         break;
      case RESET:
         // will be used to restart the process eliminating the polynomials
         doneProcessing = true;
         break;
      case MENTION:
         getLineOutputLine(cin, cout, notInteractive);
         break;
      case DIFFERENTIATE:
         differentiate(aPoly, bPoly);
         break;
      case QUIT:
         // the task is done
         doneProcessing = true;
         break;
      case INVALID:
         cout << "invalid command, please input again!\n";
         break;
      default:
         std::cerr << "**** ERROR in the switch of processCommand ***\n";
         break;
   }
   return doneProcessing;
}

// determine if the "-batch" option was entered meaning that the
// session is NOT interactive
// return true if the string matches -batch, false otherwise
bool notInteractiveOption(string option) {
   return option == "-batch";
} 

// build the tree so that the degree is in descending order
struct MyFunctor {
   bool operator() (int a, int b) const {
      return a > b;
   }
};

// if the session is interactive, echo the input
// for each pair of polynomials read, process the command and
// finish once the command is quit
int main(int argc, char* argv[]) {
   bool notInteractive = false;
   if (argc > 1) {
      notInteractive = notInteractiveOption(argv[1]);
   }
   std::map<char, Commands> commands;
   buildCommands(commands);

   Commands cmd;
   do {
      if (!notInteractive) printCommandMenu();

      // process two polynomials (and their sum) 
      bool doneWithPolys = false;
      // with a lambda function
      Univariate aPoly([](int a, int b) -> bool {return a > b;});
      // with a default STL function
      Univariate bPoly((std::greater<int>()));
      // with a functor or function object
      MyFunctor descending;
      Univariate sumPoly(descending); 
      bool validSum = false; // set to true when the command is SUM
      do {
         cmd = getCommand(commands, notInteractive);
         doneWithPolys = process(cmd,notInteractive,aPoly,bPoly,sumPoly,validSum);
      } while (!doneWithPolys); // calls the destructors
      
   } while (cmd != QUIT); 
   return 0;
}

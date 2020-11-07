/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #6, CPSC 2150

NOTE:
Self explanatory variables and parameters will not be documented as they are, "self-explanatory".

*/

#include <iostream>
#include <fstream>  // for file input and output
#include <cstdlib>  // exit
#include <string>
#include <stdlib.h> // atoi
#include <cstring>  // strcmp

#include "canvas.h"

//string literal for line arguments
const char* usage = R"(usage: color [-help][-input <path>][-output <path>][-i <value>][-j <value>][-recursive][-queue][-stack]

help				prints the usage
input <path>			the inFile that has two integers the m rows and n columns followed by m by n b characters and r characters
output <path>			the outFile has m rows by n columns of R characters and blanks
i <value> 			an integer for the row of the starting pixel (origin is the upper left hand corner)
j <value> 			an integer for the column of the starting pixel (origin in the upper left hand corner)
recursive 			calls the recursive version
queue 				calls the version that uses the queue
stack 				calls the version of that uses an explicit stack)";

// returns true if the stream was opened successfully 
bool openedOutStream(char* fileName, std::ofstream& fout)
{
	fout.open(fileName);
	// cannot do it in one statement with return fout
	if (fout)
		return true;
	else
		return false;
}


int main(int argc, char* argv[])
{
	std::ifstream fin;
	std::ofstream fout;
	
	//some flags for line arguments
	int flagIN, flagOUT, flagI, flagJ;
	bool flagH, flagR, flagQ, flagS;
	flagH =  flagR = flagQ = flagS = false;
	flagIN = flagOUT = flagI = flagJ = -1;
	
	//Parsing line args
	for (int i = 1; i < argc; ++i)
	{
		if (!(std::strcmp(argv[i],"-help")))
			flagH = true;
		else if (!(std::strcmp(argv[i],"-input")))
			flagIN = i;
		else if (!(std::strcmp(argv[i],"-output")))
			flagOUT = i;
		else if (!(std::strcmp(argv[i],"-i")))
			flagI = i;
		else if (!(std::strcmp(argv[i],"-j")))
			flagJ = i;
		else if (!(std::strcmp(argv[i],"-recursive")))
			flagR = true;
		else if (!(std::strcmp(argv[i],"-queue")))
			flagQ = true;
		else if (!(std::strcmp(argv[i],"-stack")))
			flagS = true;
	}
	if (flagH || (flagIN == -1 || flagOUT == -1 || flagI == -1 || flagJ == -1) || ((flagR && flagQ) || (flagR && flagS) || (flagS && flagQ)))
	{
		std::cout << usage << std::endl;
		return flagH ? 0 : 1; //returning error code (if we reach this code without executinng -help, then the user made an error)
	}

	fin.open(argv[flagIN+1]);
	if (! openedOutStream(argv[flagOUT +1], fout))
		return 1;

	int r, c;
	r = atoi(argv[flagI + 1]);
	c = atoi(argv[flagJ + 1]);

	// fin is associate with the input file given as a line argument
	// fout is associated with the output file give as a line argument

	// read from the file the rows and cols
	int rows, cols;
	fin >> rows >> cols;
	// you may add more arguments to the constructor
	Canvas canvas(rows, cols);

	fin >> canvas;
	fin.close();

	//call requested function as per argument give to program
	if (flagR)
		canvas.colorRec(r, c);
	else if (flagS)
		canvas.colorStack(r, c);
	else if (flagQ)
		canvas.colorQueue(r, c);

	fout << canvas;
	fout.close();

	return 0;
}
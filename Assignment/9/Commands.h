// Author: Gladys Monagan 
// Commands and command processing including a function to make a map to store commands in
// Course: CPSC 2150
// Copyright 2020

#ifndef COMMANDS_H
#define COMMANDS_H

#include <map>        // std::map
#include <fstream>    // std::ifstream std::ofstream

// the commands allowed when interacting with the user
enum Commands
{
	INPUT,
	SUM,
	PRINT,
	NUMBER_OF_TERMS,
	EVALUATE,
	GET_COEFF,
	RESET,
	MENTION,
	DIFFERENTIATE,
	QUIT,
	INVALID
};

// output to std::cout the commands available
void printCommandMenu();

// make an associative array of the character (that will be obtained from input)
// and its associated command
// postcondition:
//   commands is filled
void buildCommands(std::map<char, Commands>& commands);

// read from standard input a command and obtain the first letter of that 
// command to match it to a corresponding value from the enum type Commands
// if notInteractive, the command read is echoed to standard output
// postcondition:
//    returns a command from Commands (including INVALID)
Commands getCommand(std::map<char, Commands>& commands, bool notInteractive);

// return true if the first letter entered (skipping blanks) from std::cin
// is 'y' or 'Y', false otherwise
// if notInteractive, the answer read is echoed onto standard output
bool yesAnswer(bool notInteractive = false);

// reset the input stream (possibly out of its fail state) and clear the buffer
// postcondition:
//    fin is ready to read again
void clearClean(std::istream &fin);

// consume the end-of-line of  the previous fin
// read a line using fin and output it to fout if notInteractive
void getLineOutputLine(std::istream& fin, std::ostream& fout, 
	bool notInteractive);

#endif
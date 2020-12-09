// Author: Gladys Monagan 
// A univariate polynomial term in x
// Course: CPSC 2150
// Copyright 2020

#include "Commands.h"
#include <sstream>    // std::stringstream
#include <map>        // std::map
#include <iostream>   // std::cin std::cout 
#include <string>     // std::string
#include <fstream>    // std::ifstream std::ofstream

using std::cout, std::cin, std::string;

// output the commands available
void printCommandMenu() {
	cout << "\n ------------------ command list ----------------------\n";
	cout << "(i) - input the polynomials a and b\n";
	cout << "(s) - sum up the polynomials a and b the polynomial a + b\n";
	cout << "(p) - print the polynomials a and b and a + b\n";
	cout << "(n) - number of terms in the polynomials a and b and a+b\n";
	cout << "(e) - evaluate a, b and a + b at a specific x value\n";
	cout << "(c) - coefficient of a term when the term's degree is supplied\n";
	cout << "(r) - reset or restart the process with two new polynomials\n";
	cout << "(m) - mention or comment, the subsequent line is ignored\n";
	cout << "(d) - differentiate the polynomials a and b\n";
	cout << "(q) - quit the program altogether\n";
	cout << " --------------------------------------------------------\n"; 
}

// make an associative array of the character (that will be obtained from input)
// and its associated command
void buildCommands(std::map<char, Commands>& commands) {
	commands.insert(std::pair('i', INPUT));
	commands.insert(std::pair('s', SUM));
	commands.insert(std::pair('p', PRINT));
	commands.insert(std::pair('n', NUMBER_OF_TERMS));
	commands.insert(std::pair('e', EVALUATE));
	commands.insert(std::pair('c', GET_COEFF));
	commands.insert(std::pair('r', RESET));
	commands.insert(std::pair('m', MENTION));
	commands.insert(std::pair('d', DIFFERENTIATE));
	commands.insert(std::pair('q', QUIT));
}

// read from standard input a command and obtain the first letter of that 
// command to match it to a corresponding value from the enum type Commands
// if notInteractive, the command read is echoed to standard output
// postcondition:
//    returns a command from Commands (including INVALID)
Commands getCommand(std::map<char, Commands>& commands, bool notInteractive) {
	cout << "\ncommand: ";
	string commandStr;
	cin >> commandStr;
	std::stringstream ss(commandStr);
	char ch;
	ss >> ch;
	if (notInteractive) cout << commandStr << "\n";  // echo what was read
	Commands cmd = INVALID;
	if (commands.find(ch) != commands.end())
		cmd = commands[ch];
	return cmd;
}

// read from standard input a single word and check if the first
// letter corresponds to 'y' or 'Y' (implying a yes)
// return true if the string read from cin starts with 'y' or 'Y', false otherwise
// if notInteractive, the answer read is echoed onto standard output
bool yesAnswer(bool notInteractive) {
	string answerStr;
	cin >> answerStr;
	if (notInteractive) cout << answerStr << "\n";
	return (answerStr[0] == 'Y' || answerStr[0] == 'y');
}

// reset the input stream (possibly out of its fail state) and clear the buffer
// postcondition:
//    fin is ready to read again
void clearClean(std::istream &fin) {
	static const int MAX_CHARACTERS_IN_BUFFER = 250;
	fin.clear();
	fin.ignore(MAX_CHARACTERS_IN_BUFFER, '\n');
}

// consume the end-of-line of  the previous fin
// read a line using fin and output it to fout if notInteractive
void getLineOutputLine(std::istream& fin, std::ostream& fout, 
	bool notInteractive) {
	string line;
	std::getline(fin, line); // consume the end-of-line
	std::getline(fin, line);
	if (notInteractive) 
		fout << line << "\n";
}
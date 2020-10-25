// CPSC 2150, Assignment #4, Fall 2020
/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #4, CPSC 2150

NOTE:
Self explanatory variables and parameters will not be documented as they are, "self-explanatory".

*/

#include "SList.h"
#include <iostream>
#include <cmath>

// every experiment is tried TRIALS times
const int TRIALS = 1000;


int main()
{
	SList list;
	std::cout << "Assignment 4:" << std::endl;
	//std::cout << "n\t\tn^3/2\t\tNum of Moves" << std::endl;
	std::cout << "# of Elements\t\tSearched Value\t\tif found\t\t# of Comparison\t\tComparison ratio (comp/n)" << std::endl;
	for (size_t i = 0; i < TRIALS; ++i)
	{
		int randomNumber = rand() % 10000 + 1;
		for (int i = 0; i < randomNumber; ++i)
		{
			list.insert(rand() % 10000 + 1);
		}
		//if you want to print the table in the terminal, uncomment the below line
		//std::cout << randomNumber << "\t\t" << sqrt(pow(randomNumber, 3)) << "\t\t" << list.getMoves() << std::endl;
		int comp = 0;
		int searchedVal = rand() % 10000 + 1;
		std::cout << randomNumber << "\t\t\t" << searchedVal << "\t\t\t" << list.search(searchedVal, comp) << "\t\t\t" << comp << "\t\t\t" << comp/static_cast<double>(randomNumber) << std::endl;
		list.reset();
	}
	return 0;
}
/* 
Name: Alp Deniz Senyurt
Student Number: 100342433
Assignment #8, CPSC 2150

NOTE:
Self explanatory variables and parameters will not be documented as they are, "self-explanatory".

*/


#include <iostream>
#include <cmath>
#include <utility>

const int empty = -1;

//1997 is the largest prime number that is less than 1999.
int h2 (int x)
{
	return 1997 - (x % 1997);
}

int h (int x)
{
	return (x % 1999);
}


int getKeys()
{
	return (std::rand() % (static_cast<int>(std::pow(2, 20))));
}

std::pair<bool,int> searchLP(int x, int* T, int size = 1999) 
{
	 // true/false if found, number of comparison

	int hash = h(x);
	int counter = 0;
	if (T[hash] == x)
	{
		return std::make_pair(true, 1);
	}
	else
	{
		while ((T[hash] != x && T[hash] != empty) && counter < size)
		{
			++hash;
			hash %= size;
			++counter;
		}
		if (counter >= size)
			return std::make_pair(false, counter+1);
	}
	return std::make_pair(T[hash] == x, counter + 1);
}


bool insertLP(int x, int* T, int size = 1999)
{
	int hash = h(x);
	int counter = 0;
	if (T[hash] == empty)
	{
		T[hash] = x;
	}
	else
	{
		while (T[hash] != empty && counter < size)
		{
			++hash;
			hash %= size;
			++counter;
		}
		if (counter >= size)
			return false;
		T[hash] = x;
	}
	return true;
}

std::pair<bool,int> searchQP(int x, int* T, int size = 1999)
{
	int hash = h(x);
	int counter = 0;
	int temp = hash;
	if (T[hash] == x)
	{
		return std::make_pair(true, 1);
	}
	else
	{		
		while ((T[temp] != x && T[temp] != empty) && counter < 3996001) //1999^2, arbitrary limit for worst case scenario as in number of checks
		{
			++counter;
			temp = (hash + static_cast<int>(std::pow(counter,2)) * ((-2 * ((counter + 1) % 2)) + 1) % size);
		}
		if (counter >= 3996001)
			return std::make_pair(false, 3996001 + 1);
	}
	return std::make_pair(T[temp] == x, counter + 1);
}

bool insertQP(int x, int* T, int size = 1999)
{
	int hash = h(x);
	int counter = 0;
	if (T[hash] == empty)
	{
		T[hash] = x;
	}
	else
	{		
		int temp = hash;
		while (T[temp] != empty && counter < 3996001) //1999^2, arbitrary limit for worst case scenario as in number of checks
		{
			++counter;
			temp = (hash + static_cast<int>(std::pow(counter,2)) * ((-2 * ((counter + 1) % 2)) + 1) % size);
		}
		if (counter >= 3996001)
			return false;
		T[hash] = x;
	}
	return true;
}

std::pair<bool,int> searchDH(int x, int* T, int size = 1999)
{
	int hash = h(x);
	int counter = 0;
	int temp = hash;
	if (T[hash] == x)
	{
		return std::make_pair(true, 1);
	}
	else
	{		
		while ((T[temp] != x && T[temp] != empty) && counter < 3996001) //1999^2, arbitrary limit for worst case scenario as in number of checks
		{
			++counter;
			temp = ((hash + counter * h2(x)) % size);
		}
		if (counter >= 3996001)
			return std::make_pair(false, 3996001 + 1);
	}
	return std::make_pair(T[temp] == x, counter + 1);
}

bool insertDH(int x, int* T, int size = 1999)
{
	int hash = h(x);
	int counter = 0;
	if (T[hash] == empty)
	{
		T[hash] = x;
	}
	else
	{		
		int temp = hash;
		while (T[temp] != empty && counter < 3996001) //1999^2, arbitrary limit for worst case scenario as in number of checks
		{
			++counter;
			temp = ((hash + counter * h2(x)) % size);
		}
		if (counter >= 3996001)
			return false;
		T[hash] = x;
	}
	return true;
}

int main()
{
	//comparison say
	std::cout << "Assignment 8\n\nLinear Probing" << std::endl;
	int T[1999];

	double avgArr[6] = {0};
	for (int i = 0; i < 100; ++i)
	{
		for (int i = 0; i < 1999; ++i)
		{
			T[i] = -1;
		}
		for (int j = 0; j < 1000; ++j)
		{
			int var = getKeys();
			if (searchLP(var, T, 1999).first)
			{
				--j;
				continue;
			}
			static_cast<void>(insertLP(var, T, 1999));
		}
		double avg = 0;


		//LINEAR PROBING
		std::cout << "Is X In T\t\tSearched Value\t\t# of Comparison" << std::endl;
		std::cout << "Starting search through array T " << i << std::endl; 
		int k = 0;
		while (k < 1999)
		{
			if (T[k] != empty)
			{
				std::pair<bool, int> p = searchLP(T[k], T, 1999);
				std::cout << (p.first ? "true" : "false") << "\t\t\t" << T[k] << "\t\t\t" << p.second << std::endl;
				avg += p.second;
			}
			++k;
		}
		avgArr[0] += avg;
		avg = 0;
		k = 0;
		while (k < 1000)
		{
			int temp = getKeys();
			std::pair<bool, int> p = searchLP(temp, T, 1999);
			if (! p.first)
			{
				std::cout << (p.first ? "true" : "false") << "\t\t\t" << T[k] << "\t\t\t" << p.second << std::endl;
				avg += p.second;
				++k;
			}
		}
		avgArr[1] += avg;
		avg = 0;
		k = 0;


		//QUADRATIC PROBING
		for (int i = 0; i < 1999; ++i)
		{
			T[i] = -1;
		}
		for (int j = 0; j < 1000; ++j)
		{
			int var = getKeys();
			if (searchQP(var, T, 1999).first)
			{
				--j;
				continue;
			}
			static_cast<void>(insertQP(var, T, 1999));
		}

		std::cout << "Is X In T\t\tSearched Value\t\t# of Comparison" << std::endl;
		std::cout << "Starting search through array T " << i << std::endl; 
		k = 0;
		while (k < 1999)
		{
			if (T[k] != empty)
			{
				std::pair<bool, int> p = searchQP(T[k], T, 1999);
				std::cout << (p.first ? "true" : "false") << "\t\t\t" << T[k] << "\t\t\t" << p.second << std::endl;
				avg += p.second;
			}
			++k;
		}
		avgArr[2] += avg;
		avg = 0;
		k = 0;
		while (k < 1000)
		{
			int temp = getKeys();
			std::pair<bool, int> p = searchQP(temp, T, 1999);
			if (! p.first)
			{
				std::cout << (p.first ? "true" : "false") << "\t\t\t" << T[k] << "\t\t\t" << p.second << std::endl;
				avg += p.second;
				++k;
			}
		}
		avgArr[3] += avg;
		avg = 0;
		k = 0;


		// DOUBLE HASHING
		for (int i = 0; i < 1999; ++i)
		{
			T[i] = -1;
		}
		for (int j = 0; j < 1000; ++j)
		{
			int var = getKeys();
			if (searchDH(var, T, 1999).first)
			{
				--j;
				continue;
			}
			static_cast<void>(insertDH(var, T, 1999));
		}

		std::cout << "Is X In T\t\tSearched Value\t\t# of Comparison" << std::endl;
		std::cout << "Starting search through array T " << i << std::endl; 
		k = 0;
		while (k < 1999)
		{
			if (T[k] != empty)
			{
				std::pair<bool, int> p = searchDH(T[k], T, 1999);
				std::cout << (p.first ? "true" : "false") << "\t\t\t" << T[k] << "\t\t\t" << p.second << std::endl;
				avg += p.second;
			}
			++k;
		}
		avgArr[4] += avg;
		avg = 0;
		k = 0;
		while (k < 1000)
		{
			int temp = getKeys();
			std::pair<bool, int> p = searchDH(temp, T, 1999);
			if (! p.first)
			{
				std::cout << (p.first ? "true" : "false") << "\t\t\t" << T[k] << "\t\t\t" << p.second << std::endl;
				avg += p.second;
				++k;
			}
		}
		avgArr[5] += avg;
		avg = 0;
		k = 0;
	}
	avgArr[0] /= 100000;
	avgArr[1] /= 100000;
	avgArr[2] /= 100000;
	avgArr[3] /= 100000;
	avgArr[4] /= 100000;
	avgArr[5] /= 100000;
	std::cout << "Average numbers:\n" << avgArr[0] << "\t" << avgArr[1] << "\t" << avgArr[2] << "\t" << avgArr[3] << "\t" << avgArr[4] << "\t" << avgArr[5] << "\nThe list is for LP(true), LP(false), QP(true), QP(false), DH(true), DH(false), where true means X exists in T." << std::endl;
	return 0;
}
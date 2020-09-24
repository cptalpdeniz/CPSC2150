#include <iostream>
#include <stack>
#include <chrono>
#include "Stack.h"
#include <cstdlib>

static unsigned long long current_millis()
{
	// code from https://Stackoverflow.com/a/56107709
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

// operations
/*
	1000
	2000
	4000
	8000
	16000
*/
template <class T> static long long time_data_structure(size_t size)
{
	T s;
	long long avg = 0;
	for (int i = 0; i < 100; ++i)
	{
		unsigned long long const start = current_millis();

		for (size_t i = 0; i < size; i++)
		{
			s.push(std::rand());
		}
		//
		unsigned long long const end = current_millis();
		avg += end - start;
	}
	return (avg/100);
}

int main()
{
	std::cout.setf(std::ios::unitbuf);
	std::cout << "Here's the table of average of time it takes to execute each push operation 100 times\n\n";
	std::cout << "n\t\t1000\t\t2000\t\t4000\t\t8000\t\t16000" << std::endl;
	std::cout << "by one\t\t" << time_data_structure<Stack<int, method::ONE>>(1000) << "\t\t" << time_data_structure<Stack<int, method::ONE>>(2000) << "\t\t" << time_data_structure<Stack<int, method::ONE>>(4000) << "\t\t" << time_data_structure<Stack<int, method::ONE>>(8000) << "\t\t" << time_data_structure<Stack<int, method::ONE>>(16000) << std::endl;
	std::cout << "by ten\t\t" << time_data_structure<Stack<int, method::TEN>>(1000) << "\t\t" << time_data_structure<Stack<int, method::TEN>>(2000) << "\t\t" << time_data_structure<Stack<int, method::TEN>>(4000) << "\t\t" << time_data_structure<Stack<int, method::TEN>>(8000) << "\t\t" << time_data_structure<Stack<int, method::TEN>>(16000) << std::endl;
	std::cout << "double\t\t" << time_data_structure<Stack<int, method::DBL>>(1000) << "\t\t" << time_data_structure<Stack<int, method::DBL>>(2000) << "\t\t" << time_data_structure<Stack<int, method::DBL>>(4000) << "\t\t" << time_data_structure<Stack<int, method::DBL>>(8000) << "\t\t" << time_data_structure<Stack<int, method::DBL>>(16000) << std::endl;
	std::cout << "STL\t\t" << time_data_structure<std::stack<int>>(1000) << "\t\t" << time_data_structure<std::stack<int>>(2000) << "\t\t" << time_data_structure<std::stack<int>>(4000) << "\t\t" << time_data_structure<std::stack<int>>(8000) << "\t\t" << time_data_structure<std::stack<int>>(16000) << std::endl;
}
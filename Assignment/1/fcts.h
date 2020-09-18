// Assignment #1, CPSC 2150, Gladys Monagan
#ifndef FCTS_H
#define FCTS_H

#include <string>

// 1. Exercise 3.8 toBinaryString on page 5
std::string toBinaryString(unsigned int n);

// 2. Exercise 3.9 toBitsString on page 6
std::string toBitsString(unsigned int n);

// 3. Exercise 5.6 minimum positive number on page 11
int minimumPositive(const int A[], int n);

// 4. Exercise 5.13 swapPairsRightToLeft on page 15
void swapPairsRightToLeft(int A[], int n);

// 5. Exercise 7.3 equalsChar on page 19
bool equalsChar(const std::string& strA, const std::string& strB, char ch);

#endif

#include <iostream>
#include <climits>
#include <string>

#define CHECK_BIT(var,pos) (var & (1 << pos))


std::string toFinalStr(unsigned int n, unsigned int reqNumOfChars, unsigned int numOfChars)
{
	if (n == 0)
	{
		if (reqNumOfChars != numOfChars)
			return toFinalStr(n, reqNumOfChars, numOfChars++) + "0";
	}
	else
		return toFinalStr(n >> 1, reqNumOfChars, numOfChars++) + (CHECK_BIT(n, 0) ? "1" : "0");
}

std::string toBitsString(unsigned int n)
{
	return toFinalStr(n, sizeof(n) * CHAR_BIT, 0);
}

int main()
{
	std::cout << toBitsString(12) << std::endl;
}
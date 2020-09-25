Conclusion:

Here's the table showing increase method and average of 100 tests running n operation

n			1000		2000		4000		8000		16000
by one		86.83		345.98		1392.97		5732.48		24329
by ten		8.75		34.85		139.89		583.96		2426.77
double		0.02		0.02		0.04		0.08		0.16
STL			0.05		0.12		0.23		0.44		0.88


As expected by one is the slowest method. However what’s surprising is doubling is way faster than STL (std::stack). 
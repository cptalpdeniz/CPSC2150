// Name: 
// started by Gladys Monagan, CPSC 2150, Assignment #6, 2020

#include <iostream>
#include <fstream>  // for file input and output
#include <cstdlib>  // exit
#include <stack>    // from the STL
#include <queue>    // from the STL
#include <utility>
#include "canvas.h"

//Constructor
Canvas::Canvas(int n, int m)
{
	this->n = n;
	this->m = m;
	canvas = new bool*[n];
	for (int i = 0; i < n; ++i)
	{
		canvas[i] = new bool[m](); //default initilization of bool is false
	}
}

int Canvas::getColumns()
{
	return m;
}

int Canvas::getRows()
{
	return n;
}

//Copy Constructor
Canvas::Canvas(const Canvas& other)
{
	n = 0;
	m = 0;
	(*this) = other;
}

//Assignment operator
Canvas& Canvas::operator =(const Canvas& rtSide)
{
	if (this != (&rtSide))
	{
		if (n != rtSide.n || m != rtSide.m)
		{
			//delete rows
			for (int i = 0; i < n; ++i)
			{
				delete [] canvas[i];
			}
			canvas = new bool*[rtSide.n];
			for (int i = 0; i < rtSide.n; ++i)
			{
				canvas[i] = new bool[rtSide.m](); //default initilization of bool is false
			}
			this->n = rtSide.n;
			this->m = rtSide.m;
		}
		//do a deep copy of the canvas
		for (int i = 0; i < rtSide.n; ++i)
		{
			for (int j = 0; j < rtSide.m; ++j)
			{
				canvas[i][j] = rtSide.canvas[i][j];
			}
		}
	}
	return (*this);
}

Canvas::~Canvas() 
{
	for (int i = 0; i < n; ++i)
	{
		delete [] canvas[i];
	}
}

//Color using STL STACK
//int r = row
//int c = column
void Canvas::colorStack(int r, int c)
{
	if ((r >= n || r < 0 || c >= m || c < 0) || canvas[r][c])
		return;
	//create std::pair for origin
	std::pair<int, int> p = std::make_pair(r,c);

	//create stack of pairs (x,y) or (r,c)
	std::stack<std::pair<int,int>> s;
	s.push(p);

	std::stack<std::pair<int, int>> s2;
	s2.push(p);

	//iterate through the canvas
	//left -> right -> up -> down
	while (! s.empty())
	{
		p = s.top();
		s.pop();
		int tempR = std::get<0>(p)-1;
		int tempC = std::get<1>(p);
		while (tempR >= 0 && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			--tempR;
		}
		tempR = std::get<0>(p)+1;
		tempC = std::get<1>(p);
		while (tempR < n && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			++tempR;
		}
		tempR = std::get<0>(p);
		tempC = std::get<1>(p)-1;
		while (tempC >= 0 && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			--tempC;
		}
		tempR = std::get<0>(p);
		tempC = std::get<1>(p)+1;
		while (tempC < m && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			++tempC;
		}
		//after going through all directions (where possible) set the blue pixels to red
	    while (!s2.empty())
		{
			std::pair<int, int> p1 = s2.top();
			canvas[p1.first][p1.second] = true;
			s2.pop();
		}
	}
}

//Color using STL QUEUE
//int r = row
//int c = column
void Canvas::colorQueue(int r, int c)
{
	if ((r >= n || r < 0 || c >= m || c < 0) || canvas[r][c])
		return;

	//create std::pair for origin
	std::pair<int, int> p = std::make_pair(r,c);

	//create queue of pairs (x,y) or (r,c)
	std::queue<std::pair<int,int>> s;
	s.push(p);

	std::queue<std::pair<int,int>> s2;
	s2.push(p);

	//iterate through the canvas
	//left -> right -> up -> down
	while (! s.empty())
	{
		p = s.front();
		s.pop();
		int tempR = std::get<0>(p)-1;
		int tempC = std::get<1>(p);
		while (tempR >= 0 &&  !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			--tempR;
		}
		tempR = std::get<0>(p)+1;
		tempC = std::get<1>(p);
		while (tempR < n && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			++tempR;
		}
		tempR = std::get<0>(p);
		tempC = std::get<1>(p)-1;
		while (tempC >= 0 && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			--tempC;
		}
		tempR = std::get<0>(p);
		tempC = std::get<1>(p)+1;
		while (tempC < m && !(canvas[tempR][tempC]))
		{
			s.push(std::make_pair(tempR, tempC));
			s2.push(std::make_pair(tempR, tempC));
			++tempC;
		}
		//after going through all directions (where possible) set the blue pixels to red
	    while (!s2.empty())
		{
			std::pair<int, int> p1 = s2.front();
			canvas[p1.first][p1.second] = true;
			s2.pop();
		}
	}
}

//Do the same coloring operation recursively
//LMAO ONLY 5 LINES
void Canvas::colorRec(int r, int c)
{
	if ((r >= n || r < 0 || c >= m || c < 0) || canvas[r][c])
		return;
	canvas[r][c] = true;
	colorRec(r-1,c); //up
	colorRec(r+1,c); //down
	colorRec(r,c-1); //left
	colorRec(r,c+1); //right
}



// read row by row
// expected values are Canvas::IN_RED_PIXEL and Canvas::IN_BLUE_PIXEL
// and if these are not found, abort the whole program (ouch!)
std::istream& operator >> (std::istream& in, Canvas& canvas)
{
	char ch;
	for (int i = 0; i < canvas.n; i++)
	{
		for (int j = 0; j < canvas.m; j++)
		{
			in >> ch;
			if (ch == Canvas::IN_RED_PIXEL)
				canvas.canvas[i][j] = true;
			else if (ch == Canvas::IN_BLUE_PIXEL)
				canvas.canvas[i][j] = false;
			else
			{
				std::cerr << "spurious DATA at (" << i << ", " << j << ")...bye\n";
				exit(1);
			}
		} // for j
	} // for i
	return in;
}

std::ostream& operator << (std::ostream& out, const Canvas& canvas)
{
	for (int i = 0; i < canvas.n; i++)
	{
		for (int j = 0; j < canvas.m; j++)
		{
			if (canvas.canvas[i][j])
				out << Canvas::RED_PIXEL_OUT;
			else
				out << Canvas::BLUE_PIXEL_OUT;
		} // for j
		out << "\n";
	} // for i
	return out;
}
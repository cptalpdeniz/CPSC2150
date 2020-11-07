// Name:
// started by Gladys Monagan, CPSC 2150, Assignment #6, 2020

#ifndef CANVAS_H
#define CANVAS_H

#include <fstream> 
#include <stack>    // from the STL
#include <queue>    // from the STL

class Canvas {
public:
	// create a canvas (of pixels) with dimensions n x m
	Canvas(int n, int m);

	// the number of columns
	int getColumns();

	// the number of rows
	int getRows();

	// used when reading from an inputStream using the operator >>
	static const char IN_RED_PIXEL = 'r';
	static const char IN_BLUE_PIXEL = 'b';

	// read (getRows() x getColumns()) values
	// postcondition:
	//    the canvas values are read in 
	//    aborts if a non IN_RED_PIXEL or a non IN_BLUE_PIXEL is encountered
	friend std::istream& operator >> (std::istream& inputStream, Canvas&);

	// used when drawing the pixels to an outputStream using the operator <<
	static const char RED_PIXEL_OUT = 'R';
	static const char BLUE_PIXEL_OUT = ' ';

	// print (getRows() x getColumns()) values
	// postcondition:
	//    output to the outputStream the values RED_PIXEL_OUT and BLUE_PIXEL_OUT
	friend std::ostream& operator << (std::ostream& outputStream, const Canvas&);
	
	// copy constructor
	Canvas(const Canvas&);  

	// overloaded assignment operator
	Canvas& operator = (const Canvas& rtSide);

	// destructor
	~Canvas();

	void colorStack(int, int);
	void colorQueue(int, int);
	void colorRec(int, int);

private:
	int n; //row
	int m; //column
	bool** canvas; //red = true
};
#endif



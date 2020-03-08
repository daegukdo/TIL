// c++ code-war
/*
@ Issue title

Perimeter of squares in a rectangle

@ Description

The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. 

It's easy to see that the sum of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:

alternative text

ref : 01_img.png

#Hint: See Fibonacci sequence

#Ref: http://oeis.org/A000045

The function perimeter has for parameter n where n + 1 is the number of squares (they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216
*/

#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

class SumFct
{
public:
	static ull perimeter(int n);
};

ull SumFct::perimeter(int n)
{
	// Fibonacci sequence : 1 1 2 3 5 8 13 21 34 ... //

	// define Fib. variable ... dynamic variable
	ull step = n+1;
	ull *numArray = new ull[step]();

	// first setup step
	numArray[0] = 1;
	numArray[1] = 1;

	// iter. step
	for(int i = 2; i < step; i++)
	{
		numArray[i] = numArray[i-1] + numArray[i-2];
	}

	// cal. rect. area //

	// define rectArea variable
	ull rectArea = 0;

	// cal.
	for(int i = 0; i < step; i++)
	{
		rectArea += numArray[i];
	}

	rectArea *= 4;

	// del. Fib. variable ... dynamic variable
	delete[] numArray;

	return rectArea;
}

int main()
{
	ull r1 = SumFct::perimeter(5);
	return 0;
}
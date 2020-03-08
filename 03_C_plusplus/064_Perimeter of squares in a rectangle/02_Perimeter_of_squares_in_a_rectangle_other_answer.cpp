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
  ull a = 1, b = 1, t = 1;
  for (int i = 0; i < n + 2; ++i)
  {
    t = a + b; a = b; b = t;
  }
  return 4 * (a - 1);
}

int main()
{
	ull r1 = SumFct::perimeter(5);
	return 0;
}
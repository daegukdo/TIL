// c++ code-war
/*
issue description

Complete the function that takes two numbers as input, num and nth and return the nth digit of num (counting from right to left).

Note
If num is negative, ignore its sign and treat it as a positive value
If nth is not positive, return -1
Keep in mind that 42 = 00042. This means that findDigit(42, 5) would return 0

Examples
findDigit(5673, 4)     returns 5
findDigit(129, 2)      returns 2
findDigit(-2825, 3)    returns 8
findDigit(-456, 4)     returns 0
findDigit(0, 20)       returns 0
findDigit(65, 0)       returns -1
findDigit(24, -8)      returns -1
*/

#include <string>
#include <cmath>

using namespace std;

int findDigit(int num, int nth);

int main()
{
	int a = findDigit(4222, 2);
	int b = findDigit(65, 0);
	int c = findDigit(24, -8);
	int d = findDigit(-2825, 3);
	int e = findDigit(-2825, 300);

	return 0;
}

int findDigit(int num, int nth){
    int pos = 0, digit;
    if (nth < 1) return -1;              //return -1 if nth position is 0 or negative
    if (num < 0) num *= -1;              //make number positive if it's negative
    while (num > 0)                      //while there are digits in the number
    {
      pos++;                             //increase the position counter
      digit = num % 10;                  //get the last digit of the number
      if (pos == nth) return digit;      //return digit if we are on the right position
      num /= 10;                         //cut the last digit by dividing number 10
    }
    return 0;                            //if we haven't reached the nth position, it means that nth is bigger 
}                                        //than number length, return 0
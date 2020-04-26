// c++ code-war
/*
@ issue description

Number of trailing zeros of N!

@ Description

Write a program that will calculate the number of trailing zeros in a factorial of a given number.

N! = 1 * 2 * 3 * ... * N

Be careful 1000! has 2568 digits...

For more info, see: http://mathworld.wolfram.com/Factorial.html

Examples
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros
1 2 3 4 5 6 7 8 9 10 11 12 ... 2 * 5 // 10
Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.
*/

#include <string>
using namespace std;

long zeros(long n);

int main()
{
	long r1 = zeros(6);
	long r2 = zeros(12);
	long r3 = zeros(30);
	long r4 = zeros(100);

	return 0;
}

long zeros(long n)
{
	// cal. num. of 10 ... find num. of 5
	long numOfFive = 0;
	
	long tmpLongRs = 0;
	long tmpLongRm = 0;

	for(int i = 0; i <= n; i = i + 5)
	{
		tmpLongRs = i;
		do
		{
			tmpLongRm = tmpLongRs % 5;
			tmpLongRs = tmpLongRs / 5;

			if(tmpLongRm == 0 && tmpLongRs != 0)
			{
				numOfFive++;
			}
		}
		while(tmpLongRs % 5 == 0 && tmpLongRs != 0);
	}
	return numOfFive;
}
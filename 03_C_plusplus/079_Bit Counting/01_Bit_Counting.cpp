/* 
@ issue description
Bit Counting

Write a function that takes an integer as input, and returns the number of bits that are equal to one in the binary representation of that number. 

You can guarantee that input is non-negative.

Example: 

The binary representation of 1234 is 10011010010, so the function should return 5 in this case
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned int countBits(unsigned long long n);

int main() 
{
	unsigned int t1 = countBits(1234);

	return 0;
}

unsigned int countBits(unsigned long long n)
{
	if(n > 0)
	{
		const int bitsElement = 2;

		int bitsOrder = 1;
		unsigned long long bits2dec = 1;

		while(true)
		{
			bits2dec = pow(bitsElement, bitsOrder);
			if(n >= bits2dec)
			{
				bitsOrder++;
			}
			else
			{
				bitsOrder--;
				bits2dec = pow(bitsElement, bitsOrder);
				break;
			}
		}

		return (1 + countBits(n - bits2dec));
	}
	else
	{
		return 0;
	}
}

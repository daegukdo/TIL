// c++ code-war
/*
@ issue description

A Rule of Divisibility by 13

@ Description

When you divide the successive powers of 10 by 13 you get the following remainders of the integer divisions:

1, 10, 9, 12, 3, 4.

Then the whole pattern repeats.

Hence the following method: 
 Multiply the right most digit of the number with the left most number in the sequence shown above, the second right most digit to the second left most digit of the number in the sequence. 
 The cycle goes on and you sum all these products. Repeat this process until the sequence of sums is stationary.

...........................................................................

Example: What is the remainder when 1234567 is divided by 13?

7�1 + 6�10 + 5�9 + 4�12 + 3�3 + 2�4 + 1�1 = 178

We repeat the process with 178:

8x1 + 7x10 + 1x9 = 87

and again with 87:

7x1 + 8x10 = 87

...........................................................................

From now on the sequence is stationary and the remainder of 1234567 by 13 is the same as the remainder of 87 by 13: 9

Call thirt the function which processes this sequence of operations on an integer n (>=0). thirt will return the stationary number.

thirt(1234567) calculates 178, then 87, then 87 and returns 87.

thirt(321) calculates 48, 48 and returns 48
*/

#include <iostream>
#include <string>

using namespace std;

class Thirteen
{
public:
    static long long thirt(long long n);
};

long long Thirteen::thirt(long long n)
{
	long long nInput = n;

	long long divisionsList [6] = {1, 10, 9, 12, 3, 4};
	int divCount = 0;

	string nData = to_string(nInput);
	int lengthNData = nData.length();

	long long nTmp = 0;
	bool looper = true;

	while(true)
	{
		for(int i = lengthNData-1; i >= 0; i--)
		{
			nTmp += (nData[i] - '0') * divisionsList[divCount];
			
			divCount++;

			if(divCount == 6)
			{
				divCount = 0;
			}
		}

		if(nInput != nTmp)
		{
			nInput = nTmp;
		}
		else
		{
			break;
		}

		nTmp = 0;
		divCount = 0;
		nData = to_string(nInput);
	    lengthNData = nData.length();
	}

	return nInput;
}

int main()
{
	long long r1 = Thirteen::thirt(1234567);

	return 0;
}
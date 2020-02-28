// c++ code-war
/*
issue description

Backwards Read Primes

Description

Backwards Read Primes are primes that when read backwards in base 10 (from right to left) are a different prime. (This rules out primes which are palindromes.)

Examples:
13 17 31 37 71 73 are Backwards Read Primes
13 is such because it's prime and read from right to left writes 31 which is prime too. Same for the others.

Task
Find all Backwards Read Primes between two positive given numbers (both inclusive), the second one always being greater than or equal to the first one. 

The resulting array or the resulting string will be ordered following the natural order of the prime numbers.

Example
backwardsPrime(2, 100) => [13, 17, 31, 37, 71, 73, 79, 97] backwardsPrime(9900, 10000) => [9923, 9931, 9941, 9967] backwardsPrime(501, 599) => []

Note for Forth
Return only the first backwards-read prime between start and end or 0 if you don't find any

backwardsPrime(2, 100) => "13 17 31 37 71 73 79 97"
backwardsPrime(9900, 10000) => "9923 9931 9941 9967"
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class BackWardsPrime
{
public:
	static std::string backwardsPrime(long long start, long long end);
private:
	static long long reverseNum(long long number);
	static bool isPrimeNums(long long number1, long long number2);
};

std::string BackWardsPrime::backwardsPrime(long long start, long long end)
{
	std::string result = "";

	long long toRightNum = 0;
	long long toLeftNum = 0;

	for(long long i = start; i < end; i++)
	{
		toRightNum = i;
		toLeftNum = BackWardsPrime::reverseNum(i);

		if(toRightNum <= 10)
		{
			// pass
		}
		else
		{
			if(isPrimeNums(toRightNum, toLeftNum))
			{
				if(result == "")
				{
					result += to_string(toRightNum);
				}
				else
				{
					result += " ";
					result += to_string(toRightNum);
				}
			}
		}
	}

	return result;
}

long long BackWardsPrime::reverseNum(long long number)
{
	string reverseStr = "";

	string numStr = to_string(number);
	int numLength = numStr.length();

	for(int i = numLength-1; i>-1; i--)
	{
		reverseStr = reverseStr + numStr[i];
	}

	return stoll(reverseStr);
}

bool BackWardsPrime::isPrimeNums(long long number1, long long number2)
{
	// 에라토스테네스의 접근 sqrt(n) > x ... all x devieded after x++

	long long num1Checker = ceil(sqrtl(number1));
	long long num2Checker = ceil(sqrtl(number2));

	long long count = 0;

	if(num1Checker > num2Checker)
	{
		count = num1Checker;
	}
	else
	{
		count = num2Checker;
	}

	for(long long i = 2; i < count; i++)
	{
		if((num1Checker % i == 0) || (num2Checker % i == 0))
		{
			return false;
		}
		else
		{
			// pass
		}
	}

	return true;
}

int main()
{
	string r1 = BackWardsPrime::backwardsPrime(2, 100);

	return 0;
}

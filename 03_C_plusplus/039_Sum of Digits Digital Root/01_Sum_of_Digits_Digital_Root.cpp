// c++ code-war
/*
issue description

Sum of Digits / Digital Root

In this kata, you must create a digital root function.

A digital root is the recursive sum of all the digits in a number. 

Given n, take the sum of the digits of n. 

If that value has more than one digit, continue reducing in this way until a single-digit number is produced. 

This is only applicable to the natural numbers.

Here's how it works:

digital_root(16)
=> 1 + 6
=> 7

digital_root(942)
=> 9 + 4 + 2
=> 15 ...
=> 1 + 5
=> 6

digital_root(132189)
=> 1 + 3 + 2 + 1 + 8 + 9
=> 24 ...
=> 2 + 4
=> 6

digital_root(493193)
=> 4 + 9 + 3 + 1 + 9 + 3
=> 29 ...
=> 2 + 9
=> 11 ...
=> 1 + 1
=> 2
*/

#include<string>

int digital_root(int n);

int main()
{
	int r = digital_root(942);
	return 0;
}

int digital_root(int n)
{
	int resultOfSum = 0;
	std::string data = std::to_string(n);
	int lengthOfDigits = data.length();

	for(int i = 0; i < lengthOfDigits; i++)
	{
		resultOfSum += (data[i] - '0');
	}

	if(resultOfSum >= 10)
	{
		return digital_root(resultOfSum);
	}
	else
	{
		return resultOfSum;
	}
}
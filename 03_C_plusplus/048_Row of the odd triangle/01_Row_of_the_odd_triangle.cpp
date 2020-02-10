// c++ code-war
/*
issue description

Row of the odd triangle

Given a triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
find the triangle's row knowing its index (the rows are 1-indexed), e.g.:

odd_row(1)  ==  [1]
odd_row(2)  ==  [3, 5]
odd_row(3)  ==  [7, 9, 11]
Note: your code should be optimized to handle big inputs.

The idea for this kata was taken from this kata: Sum of odd numbers
*/

#include <vector>

std::vector<unsigned long long> odd_row(unsigned int n);
unsigned long firstOdd(unsigned int n);

int main()
{
	std::vector<unsigned long long> r1 = odd_row(4);

	return 0;
}

std::vector<unsigned long long> odd_row(unsigned int n)
{
	std::vector<unsigned long long> resultOfOddRow;
	resultOfOddRow.reserve(n);

	unsigned long firstOddNum = firstOdd(n);

	for(int i = 0; i < n; i++)
	{
		resultOfOddRow.push_back(firstOddNum + (i* 2));
	}

	return resultOfOddRow;
}

unsigned long firstOdd(unsigned int n)
{
	unsigned long tmp = 2 * (n-1);

	if(tmp == 0)
	{
		return 1;
	}

	return tmp + firstOdd(n-1);
}
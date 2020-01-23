// c++ code-war
/*
issue description

Multiples of 3 or 5

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 

The sum of these multiples is 23.

Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.

Note: If the number is a multiple of both 3 and 5, only count it once.

Courtesy of ProjectEuler.net

*/

#include <iostream>

using namespace std;

int solution(int number);

int main()
{
	int a = solution(10);

	return 0;
}

int solution(int number) 
{
	int result = 0;
	int topDiv3 = 0;
	int topDiv5 = 0;
	int topDiv15 = 0;

	for(int i = number-1; i >= 0; i--)
	{
		if((topDiv3 == 0) && (i % 3 == 0))
		{
			// 3으로 나누어 떨어지는 가장 큰 수
			topDiv3 = i;
		}

		if((topDiv5 == 0) && (i % 5 == 0))
		{
			// 5으로 나누어 떨어지는 가장 큰 수
			topDiv5 = i;
		}

		if((topDiv15 == 0) && (i % 15 == 0))
		{
			// 15으로 나누어 떨어지는 가장 큰 수
			topDiv15 = i;
		}
	}
	
	int sumOf3s = 0;
	int sumOf5s = 0;
	int sumOf15s = 0;

	// 3으로 나누어 떨어지는 수들의 합
	for(int i = 0; i <= (topDiv3/3); i++)
	{
		sumOf3s += i;
	}

	// 5로 나누어 떨어지는 수들의 합
	for(int i = 0; i <= (topDiv5/5); i++)
	{
		sumOf5s += i;
	}

	// 15로 나누어떨어지는 수들의 합
	for(int i = 0; i <= (topDiv15/15); i++)
	{
		sumOf15s += i;
	}

	result = sumOf3s*3 + sumOf5s*5 - sumOf15s*15;

	return result;
}
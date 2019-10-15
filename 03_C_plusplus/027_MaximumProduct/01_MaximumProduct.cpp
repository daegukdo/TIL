// c++ code-war
/*
issue description

Given an array of integers , Find the maximum product obtained from multiplying 2 adjacent numbers in the array.

Notes
Array/list size is at least 2.

Array/list numbers could be a mixture of positives, negatives also zeroes .

Input >> Output Examples
adjacentElementsProduct([1, 2, 3]); ==> return 6
Explanation:
The maximum product obtained from multiplying 2 * 3 = 6, and they're adjacent numbers in the array.
adjacentElementsProduct([9, 5, 10, 2, 24, -1, -48]); ==> return 50
Explanation:
Max product obtained from multiplying 5 * 10 = 50.

adjacentElementsProduct([-23, 4, -5, 99, -27, 329, -2, 7, -921])  ==>  return -14
Explanation:
The maximum product obtained from multiplying -2 * 7 = -14, and they're adjacent numbers in the array.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int adjacentElementsProduct(vector<int> inputArray) ;

int main()
{
	int numbers1[9] = {-23, 4, -5, 99, -27, 329, -2, 7, -921};

	std::vector<int> v1(numbers1, numbers1 + sizeof numbers1 / sizeof numbers1[0]);

	int a = adjacentElementsProduct(v1);

	return 0;
}

int adjacentElementsProduct(vector<int> inputArray) 
{
	int maxValue = inputArray[0] * inputArray[1];
	int temp = 0;

	for(int i = 0; i<(inputArray.size()-1); i++)
	{
		temp = inputArray[i] * inputArray[i+1];

		if(maxValue < temp)
		{
			maxValue = temp;
		}
	}

    return maxValue;
}
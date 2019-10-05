// c++ code-war
/*
issue description

The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4});
//should be 6: {4, -1, 2, 1}
Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. 
If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. 

Note that the empty list or array is also a valid sublist/subarray.
*/

#include <iostream>
#include <vector>

using namespace std;

int maxSequence(const vector<int>& arr);

int main()
{
	int numbers1[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int numbers2[6] = {};
	int numbers3[3] = {-1, -1, -1};

	std::vector<int> v1(numbers1, numbers1 + sizeof numbers1 / sizeof numbers1[0]);
	std::vector<int> v2(numbers2, numbers2 + sizeof numbers2 / sizeof numbers2[0]);
	std::vector<int> v3(numbers3, numbers3 + sizeof numbers3 / sizeof numbers3[0]);
	
	int r1 = maxSequence(v1);
	int r2 = maxSequence(v2);
	int r3 = maxSequence(v3);

	return 0;
}

int maxSequence(const vector<int>& arr)
{
	int arrSize = arr.size();

	int *array = new int[arrSize];
	memset(array, 0, arrSize * sizeof(int));
	int arrIndicator = 0;
	int temp = 0;

	// re-collect array 
	for (int index = 0; index < arrSize; index++)
	{
		array[arrIndicator] += arr[index];

		if(((temp>0) && (arr[index]>0)) || ((temp<0) && (arr[index]<0)))
		{
			// nothing
		}
		else
		{
			arrIndicator++;
		}

		temp = arr[index];
	}

	// calculate subarray
	if((arrIndicator == 1) && (array[arrIndicator] > 0))
	{
		delete[] array;
		return array[arrIndicator];
	}
	else if((arrIndicator == 1) && (array[arrIndicator] < 0))
	{
		delete[] array;
		return 0;
	}

	temp = 0;
	int maxValueIndicator = 0;
	for (int index = 0; index < arrSize; index++)
	{
		int b = array[index];
		if(temp < array[index])
		{
			temp = array[index];
			maxValueIndicator = index;
		}
	}

	int temp1 = 0;
	int temp2 = 0;

	int result1 = array[maxValueIndicator];
	int result2 = array[maxValueIndicator];

	for (int index = maxValueIndicator+1; index < arrSize; index++)
	{
		temp1 = result1 + array[index];

		if(temp1 > result1)
		{
			result1 = temp1;
		}
	}

	for (int index = maxValueIndicator-1; index >= 0; index--)
	{
		temp2 = result2 + array[index];

		if(temp2 > result2)
		{
			result2 = temp2;
		}
	}

	if(result1 >= result2)
	{
		delete[] array;
		return result1;
	}
	else
	{
		delete[] array;
		return result2;
	}
}

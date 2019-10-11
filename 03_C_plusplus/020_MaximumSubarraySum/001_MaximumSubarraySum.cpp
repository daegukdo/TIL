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
#include <numeric>
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

	// check data
	int checkData = 0;

	for(int i = 0; i<arrSize; i++)
	{
		if(arr[i] > 0)
		{
			checkData++;
		}
	}

	if((arrSize == 0) && (checkData == 0))
	{
		return 0;
	}
	else if(arrSize == checkData)
	{
		return std::accumulate(arr.begin(), arr.end(), 0);
	}

	// find subarray summation
	int subArrNum = 0;
	int maximumOfSubarray = 0;
	int subSum = 0;

	for(int i = 0; i<arrSize; i++)
	{
		subArrNum++;
		for(int j = 0; j<arrSize; j++)
		{
			int temp = 0;

			for(int k = j; (k<j+subArrNum) && (k<arrSize); k++)
			{
				temp += arr[k];
			}

			if(maximumOfSubarray < temp)
			{
				maximumOfSubarray = temp;
			}
		}
	}

	return maximumOfSubarray;
}
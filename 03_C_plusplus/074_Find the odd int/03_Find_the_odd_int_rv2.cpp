// c++ code-war
/*
@ issue description

Find the odd int

@ Description

Given an array, find the integer that appears an odd number of times.

There will always be only one integer that appears an odd number of times.
*/

#include <vector>

using namespace std;

int findOdd(const std::vector<int>& numbers);

int main()
{
	int arr1[] = { 20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
  
    vector<int> v1(arr1, arr1 + n1); 

	return 0;
}

int findOdd(const std::vector<int>& numbers)
{
	for(int i = 0; i < numbers.size(); i++)
	{
		int tmpInt = numbers[i];
		int count = 0;

		for(int j = 0; j < numbers.size(); j++)
		{
			if(numbers[j] == tmpInt)
			{
				count++;
			}
		}

		if(count % 2 == 1)
		{
			return tmpInt;
		}
	}
}
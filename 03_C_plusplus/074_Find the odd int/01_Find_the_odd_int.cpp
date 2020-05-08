// c++ code-war
/*
@ issue description

Find the odd int

@ Description

Given an array, find the integer that appears an odd number of times.

There will always be only one integer that appears an odd number of times.
*/

#include <vector>
#include <utility>

using namespace std;

int findOdd(const std::vector<int>& numbers);

int main()
{
	int arr1[] = { 1, 2, 2, 3, 3 }; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
  
    vector<int> v1(arr1, arr1 + n1); 

	int r1 = findOdd(v1);

	return 0;
}

int findOdd(const std::vector<int>& numbers)
{
	vector<pair<int, int>> numNcnt;

	bool isContain = false;

	for(int i = 0; i < numbers.size(); i++)
	{
		isContain = false;

		for(int j = 0; j < numNcnt.size(); j++)
		{
			if(numbers[i] == numNcnt[j].first)
			{
				numNcnt[j].second = numNcnt[j].second + 1;
				isContain = true;
			}
		}

		if(!isContain)
		{
			numNcnt.push_back(make_pair(numbers[i], 1));
		}
	}

	for(int i = 0; i < numNcnt.size(); i++)
	{
		if(numNcnt[i].second % 2 == 1)
		{
			return numNcnt[i].first;
		}
	}
}
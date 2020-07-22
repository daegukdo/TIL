/* 
@ LeetCode

Find Pivot Index

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. 

If there are multiple pivot indexes, you should return the left-most pivot index.
*/

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);

		int sumLeft = 0;

		for(int i = 0; i < nums.size(); i++)
		{
			if(sumLeft == sum - sumLeft - nums[i])
			{
				return i;
			}

			sumLeft += nums[i];
		}

        return -1;
    }
};

int main() 
{
	int a[6] = {-1,-1,-1,0,1,1};
    vector<int> v(a, *(&a + 1));

	Solution s;

	int r0 = s.pivotIndex(v);

	return 0;
}

/* 
@ LeetCode

Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.


Example 1:

Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.


Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.


Clarification:

Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.


Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1173/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int rst = 0;

		int numsSize = nums.size();
		if(numsSize == 0) { return 0; }

		int tmp = INT_MAX;
		for(int i = numsSize - 1; i >= 0; i--){
			if(tmp != nums[i]){ rst++; }
			else{ nums.erase(nums.begin() + i); }
			tmp = nums[i];
		}

        return rst;
    }
};

int main() {
	int numsArr[10] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums(numsArr, *(&numsArr + 1));

	Solution sol;

	int r = sol.removeDuplicates(nums);

	return 0;
}

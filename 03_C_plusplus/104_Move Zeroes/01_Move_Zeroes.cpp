/* 
@ LeetCode

Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1174/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		// 0�� ������ ã�� (������� ���� + 0�� �ƴϸ� break)
		// 0�� ������ �Է� vector�� size�� ������ return
		// 0�� ã���� ���� (�ڿ��� ����)
		// 0�� ������ŭ �����ϸ� break
		// ���� 0�� ������ŭ 0�� vector�� �������� �߰�
		int numsSize = nums.size();
		if(numsSize == 0) { return; }

		vector<int> numsSorted(numsSize);
		copy(nums.begin(), nums.end(), numsSorted.begin());
		sort(numsSorted.begin(), numsSorted.end());

		int numOfZero = 0;
		for(int i = 0; i < numsSize; i++){
			if(numsSorted[i] == 0) { numOfZero++; }
			else if(numsSorted[i] > 0) { break; }
		}

		if(numOfZero == numsSize) { return; }

		int numOfEraseZero = 0;
		for(int i = numsSize-1; i >= 0; i--){
			if(nums[i] == 0) { nums.erase(nums.begin() + i); numOfEraseZero++; }
			if(numOfEraseZero == numOfZero) { break; }
		}

		for(int i = 0; i < numOfZero; i++){
			nums.push_back(0);
		}

        return;
    }
};

int main() {
	int numsArr[3] = {1,0,0};
	vector<int> nums(numsArr, *(&numsArr + 1));

	Solution sol;

	sol.moveZeroes(nums);

	return 0;
}

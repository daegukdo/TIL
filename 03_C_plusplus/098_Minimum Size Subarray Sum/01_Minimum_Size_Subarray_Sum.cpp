/* 
@ LeetCode

Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s,
find the minimal length of a contiguous subarray of which the sum �� s. 
If there isn't one, return 0 instead.

Example: 
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2

Explanation: 
the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

ref : https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1299/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		// ���� nums�� �Ϻκ� �� s�� �Ѿ�� ������� ã�� --> ���ٸ� return 0
		// ���� �� ������� ���� ���� int�� s�� �Ѿ�� ��� ã��
        return 0;
    }
};

int main() {
	int numsArr[6] = {2,3,1,2,4,3};
	vector<int> nums(numsArr, *(&numsArr + 1));

	int s = 7;

	Solution sol;

	int r = sol.minSubArrayLen(s, nums);

	return 0;
}

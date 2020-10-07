/* 
@ LeetCode

Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space? 

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:
1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0

ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1182/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		// nums와 같은 사이즈(ns)의 vector를 하나 생성 = tmpVct
		// 0부터 뒤에서 k칸만큼 이동한 위치(ns-k-1)까지를
		// tmpVct에 k위치부터 붙여넣기
		// 이후 0 ~ k-1까지는 남은 값을 작성

        return;
    }
};

int main() {
	int numsArr[7] = {1,2,3,4,5,6,7};
	vector<int> nums(numsArr, *(&numsArr + 1));

	int k = 3;

	Solution sol;

	sol.rotate(nums, k);

	return 0;
}

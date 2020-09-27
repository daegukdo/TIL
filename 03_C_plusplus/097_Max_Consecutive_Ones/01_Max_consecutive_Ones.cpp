/* 
@ LeetCode

Max Consecutive Ones

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3

Explanation: 
The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.

Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

ref : https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1301/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // 1의 숫자가 연속하는 횟수가 가장 긴 것을 찾아내는 것
        // 스트링으로바꾸고
        // 0으로 스플릿
        // 이후 스플릿 된 1들의 합 중 가장 큰 것을 반환?
        return 0;
    }
};


int main() {
	int numsArr[6] = {1,1,0,1,1,1};
	vector<int> nums(numsArr, *(&numsArr + 1));

	Solution s;

	int r = s.findMaxConsecutiveOnes(nums);

	return 0;
}

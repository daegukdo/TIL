/* 
@ LeetCode
Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s,
find the minimal length of a contiguous subarray of which the sum ≥ s. 
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
#include <numeric>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		// 먼저 nums의 일부분 중 s를 넘어서는 결과값을 찾기 --> 없다면 return 0
		// 이후 이 결과값이 보다 작은 int로 s를 넘어서는 어레이 찾기

		if(nums.size() == 0) { return 0; }

		int minSubArrayLenResult = 0;
		int tmpSubArrayLen = 0;

		int tmpSum = 0;
		while(tmpSum < s){
			if(tmpSubArrayLen == nums.size()){ return 0; }
			tmpSum += nums[tmpSubArrayLen];
			tmpSubArrayLen++;
		}

		int idx = 0;
		tmpSum = 0;
		while(true){
		    tmpSum = accumulate(nums.begin() + idx, nums.begin() + idx + tmpSubArrayLen, 0);
			idx++;
			if(tmpSum >= s){ 
				minSubArrayLenResult = tmpSubArrayLen; 
				idx = 0; tmpSubArrayLen--; 
			}
			if(idx + tmpSubArrayLen == nums.size() + 1) { 
				idx = 0; tmpSubArrayLen--; 
			}
			if(tmpSubArrayLen == 0) { 
				if(minSubArrayLenResult == 0) { 
					return 0; 
				} else { 
					break; 
				} 
			}
		}

        return minSubArrayLenResult;
    }
};

int main() {
	int numsArr[3] = {1,4,4};
	vector<int> nums(numsArr, *(&numsArr + 1));

	int s = 4;

	Solution sol;

	int r = sol.minSubArrayLen(s, nums);

	return 0;
}
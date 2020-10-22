/* 
@ LeetCode

Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
 
Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

ref : https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1176/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int rst = 0;
        vector<int> vctKey;
        vector<int> vctNumOfKey;
		int count = 0;

		for(int i = 0; i < nums.size(); i++){
		    auto it = find(vctKey.begin(), vctKey.end(), nums[i]);
			if(it == vctKey.end()){
				vctKey.push_back(nums[i]);
				vctNumOfKey.push_back(1);
			}
			else{
				vctNumOfKey[distance(vctKey.begin(), it)] += 1;
			}
		}

		for(int i = 0; i < vctNumOfKey.size(); i++){
			if(vctNumOfKey[i] == 1){
				rst = vctKey[i];
			}
		}

		return rst;
    }
};

int main() {
	int numsArr[3] = {2,2,1};
    vector<int> nums(begin(numsArr), end(numsArr));
	
	Solution sol;

	int rst = sol.singleNumber(nums);

	cout << "dup!" << endl;

	return 0;
}

/* 
@ LeetCode

Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
2 <= nums.length <= 105
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

ref : https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1115/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> numsIndexVct;

		vector<int> vct1(nums);
		vector<int> vct2(nums);
		int numsSize = nums.size();

		for(int i = 1; i < numsSize; i++){
			rotate(vct1.begin(), vct1.begin() + 1, vct1.end());
			for(int j = 0; j < numsSize; j++){
				if(vct1[j] + vct2[j] == target){
					numsIndexVct.push_back(j);
					if(i + j >= numsSize){ numsIndexVct.push_back(i + j - numsSize); }
					else{ numsIndexVct.push_back(i + j); }
					sort(numsIndexVct.begin(), numsIndexVct.end());
					return numsIndexVct;
				}
			}
		}

		return numsIndexVct;
    }
};

int main() {
	int arr[3] = {2,3,4};
	vector<int> nums(begin(arr), end(arr));
	int target = 6;

	Solution sol;

	vector<int> rst = sol.twoSum(nums, target);

	cout << "dup!" << endl;

	return 0;
}

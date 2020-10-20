/* 
@ LeetCode

Contains Duplicate

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array,
and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

ref : https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1112/
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
		for (int num : nums) {
			if (hashset.count(num) > 0) {
				return true;
			}
			hashset.insert(num);
		}
		return false;
    }
};

int main() {
	int numsArr[4] = {1,2,3,1};
    vector<int> nums(begin(numsArr), end(numsArr));
	
	Solution sol;

	bool rst = sol.containsDuplicate(nums);

	if(rst) { cout << "dup!" << endl; }
	else { cout << "no, dup!" << endl;; }

	return 0;
}

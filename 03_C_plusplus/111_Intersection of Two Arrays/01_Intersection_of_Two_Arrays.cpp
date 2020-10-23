/* 
@ LeetCode

Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
Each element in the result must be unique.
The result can be in any order.

ref : https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1105/
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> intersectionVct;

		unordered_set<int> num1Set(nums1.begin(), nums1.end());
		unordered_set<int> num2Set(nums2.begin(), nums2.end());

		for(int i : num1Set){
			for(int j : num2Set){
				if(i == j){ 
					intersectionVct.push_back(j); 
					break; 
				}
			}
		}

        return intersectionVct;
    }
};

int main() {
	int nums1Arr[3] = {4,9,5};
    vector<int> nums1(begin(nums1Arr), end(nums1Arr));

	int nums2Arr[5] = {9,4,9,8,4};
    vector<int> nums2(begin(nums2Arr), end(nums2Arr));
	
	Solution sol;

	vector<int> rst = sol.intersection(nums1, nums2);

	cout << "dup!" << endl;

	return 0;
}

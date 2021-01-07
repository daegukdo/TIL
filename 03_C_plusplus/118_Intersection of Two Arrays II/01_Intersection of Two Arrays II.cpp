/* 
@ LeetCode
Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

ref : https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1178/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rst;

		unordered_map<int, int> nums1UoMap;
		unordered_map<int, int> nums2UoMap;
		
		int nums1Size = nums1.size();
		int nums2Size = nums2.size();

		bool is1shorter = false;
		if(nums1Size<nums2Size){ is1shorter = true; }

		// add elements to map1
		nums1UoMap = _vct2UnordMapWithOverlap(nums1);

		// add elements to map2
		nums2UoMap = _vct2UnordMapWithOverlap(nums2);

		// find intersect
		if(is1shorter){
			rst = _findMinValueBtwMap1NMap2(nums1UoMap, nums2UoMap);
		}
		else{
			rst = _findMinValueBtwMap1NMap2(nums2UoMap, nums1UoMap);
		}

		return rst;
    }
private:
	unordered_map<int, int> _vct2UnordMapWithOverlap(vector<int>& vct){
		unordered_map<int, int> rst;

		for(int i = 0; i < vct.size(); i++){
			auto elm = rst.find(vct[i]);
			if(elm == rst.end()){
				rst.insert(make_pair(vct[i], 1));
			}
			else{
				elm->second++;
			}
		}

		return rst;
	}
	vector<int> _findMinValueBtwMap1NMap2(unordered_map<int, int>& map1, unordered_map<int, int>& map2){
		vector<int> rst;

		for(auto iter = map1.begin(); iter != map1.end(); iter++){
				auto elm = map2.find(iter->first);
				if(elm != map2.end()){
					int numOfintersect = 0;
					if(iter->second > elm->second){ numOfintersect = elm->second; }
					else{ numOfintersect = iter->second; }
					for(int i = 0; i < numOfintersect; i++){
						rst.push_back(elm->first);
					}
				}
			}

		return rst;
	}
};

int main() {
	int list1[3] = {4,9,5};
	int list2[5] = {9,4,9,8,4};

	vector<int> vctList1(begin(list1), end(list1));
	vector<int> vctList2(begin(list2), end(list2));
		
	Solution sol;

	vector<int> rst = sol.intersect(vctList1, vctList2);

	cout << "end" << endl;

	return 0;
}

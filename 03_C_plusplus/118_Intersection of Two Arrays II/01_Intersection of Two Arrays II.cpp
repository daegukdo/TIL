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
		// 각각 벡터의 길이를 확인하여 작은 벡터에서 하나씩 확인하도록
		// unordered_map을 각각 생성
		// 작은 맵의 원소를 하나씩 골라서 큰 맵에서 찾고 value값들을 비교
		// 있다면 작은 value 값만큼 결과 벡터에 추가
		// 함수화!

        vector<int> rst;

		unordered_map<int, int> nums1UoMap;
		unordered_map<int, int> nums2UoMap;
		
		int nums1Size = nums1.size();
		int nums2Size = nums2.size();

		bool is1shorter = false;
		if(nums1Size<nums2Size){ is1shorter = true; }

		// add elements to map1
		for(int i = 0; i < nums1Size; i++){
			auto elm = nums1UoMap.find(nums1[i]);
			if(elm == nums1UoMap.end()){
				nums1UoMap.insert(make_pair(nums1[i], 1));
			}
			else{
				elm->second++;
			}
		}

		// add elements to map2
		for(int i = 0; i < nums2Size; i++){
			auto elm = nums2UoMap.find(nums2[i]);
			if(elm == nums2UoMap.end()){
				nums2UoMap.insert(make_pair(nums2[i], 1));
			}
			else{
				elm->second++;
			}
		}

		// find intersect
		if(is1shorter){
			for(auto iter = nums1UoMap.begin(); iter != nums1UoMap.end(); iter++){
				auto elm = nums2UoMap.find(iter->first);
				int numOfintersect = 0;
				if(iter->second > elm->second){ numOfintersect = elm->second; }
				else{ numOfintersect = iter->second; }
				if(elm != nums2UoMap.end()){
					for(int i = 0; i < numOfintersect; i++){
						rst.push_back(elm->first);
					}
				}
			}
		}
		else{
			for(auto iter = nums2UoMap.begin(); iter != nums2UoMap.end(); iter++){
				auto elm = nums1UoMap.find(iter->first);
				int numOfintersect = 0;
				if(iter->second > elm->second){ numOfintersect = elm->second; }
				else{ numOfintersect = iter->second; }
				if(elm != nums1UoMap.end()){
					for(int i = 0; i < numOfintersect; i++){
						rst.push_back(elm->first);
					}
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

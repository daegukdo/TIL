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
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		// ���� ������ ���̸� Ȯ���Ͽ� ���� ���Ϳ��� �ϳ��� Ȯ���ϵ���
		// unordered_map�� ���� ����
		// ���� ���� ���Ҹ� �ϳ��� ��� ū �ʿ��� ã�� value������ ��
		// �ִٸ� ���� value ����ŭ ��� ���Ϳ� �߰�

        vector<int> rst;
		
		int nums1Size = nums1.size();
		int nums2Size = nums2.size();

		return rst;
    }
};

int main() {
	int list1[4] = {1,2,2,1};
	int list2[3] = {2,2};

	vector<int> vctList1(begin(list1), end(list1));
	vector<int> vctList2(begin(list2), end(list2));
		
	Solution sol;

	vector<int> rst = sol.intersect(vctList1, vctList2);

	cout << "end" << endl;

	return 0;
}

/* 
@ LeetCode

Contains Duplicate II

Given an array of integers and an integer k,
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

ref : https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1121/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // ���� ���� Ȯ��, index ��, k �̳� �ΰ�?
		// map ����� int�� key�� ������ vecter<int>�� value�� ���� ... �� vecter�� index�� �߰��� ����
		// ���� key�� ���´ٸ� vecter�� index�� �߰�
		// map���� �ϳ��� ������(iter) vecter ���� ����(index)���� ������� ��
		// �� ���̰� k�̳��� ���� �ϳ��� �ִٸ� true�� ��ȯ ���ٸ� false�� ��ȯ
		unordered_map<int, vector<int>> uoMap_Int_VctInt;

		for(int i = 0; i < nums.size(); i++){
			int n = nums[i];
			auto elm = uoMap_Int_VctInt.find(n);
			if(elm == uoMap_Int_VctInt.end()){
				vector<int> vctIndex;
				vctIndex.push_back(i);
				uoMap_Int_VctInt.insert(make_pair(n, vctIndex));
			}
			else{
				elm->second.push_back(i);
			}
		}

		for(auto iter = uoMap_Int_VctInt.begin(); iter != uoMap_Int_VctInt.end(); iter++){
			vector<int> vctTmp = iter->second;
			for(int i = 0; i < vctTmp.size() - 1; i++){
				if(vctTmp[i+1]-vctTmp[i] <= k){
					return true;
				}
			}
		}

		return false;
    }
};

int main() {
	int nums[6] = {1,2,3,1,2,3};
	vector<int> numsVct(begin(nums), end(nums));
	int k = 2;
		
	Solution sol;

	bool rst = sol.containsNearbyDuplicate(numsVct, k);

	cout << "end" << endl;

	return 0;
}

/* 
@ LeetCode

Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

ref : https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1133/
ref : https://stackoverflow.com/questions/31323135/sort-an-unordered-map-using-sort
ref : https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // map 정의
        // find를 사용하여 map에 하나씩 넣기, 중복처리
        // unordered map을 value 기준으로 sort? vct로 바꾸어서 sort!
		// 이후 k의 수만큼 반복해서 저장을 해둠
        unordered_map<int, int> map;
        
        for(auto iter = nums.begin(); iter != nums.end(); iter++){
            int tmpInt = *iter;
            auto elm = map.find(tmpInt);
            if(elm != map.end()){
                elm->second++;
            }
            else{
                map.insert(make_pair(tmpInt, 1));
            }
        }

		vector<pair<int, int>> map2Vct(map.begin(), map.end());
		sort(map2Vct.begin(), map2Vct.end(), compPairIntIntValue);
        
        vector<int> rst;
        
        for(int i = 0; i < k; i++){
			rst.push_back(map2Vct[i].first);
		}
        
        return rst;
    }

private:
	static bool compPairIntIntValue(pair<int,int> a, pair<int,int> b) {
		return (a.second > b.second);
	}
};

int main() {
	int nums[6] = {1, 1, 1, 2, 2, 3};
	vector<int> numsVct(begin(nums), end(nums));
	int k = 2;
	
	Solution sol;

	vector<int> rst = sol.topKFrequent(numsVct, k);
	
	cout << "rst" << endl;

	return 0;
}

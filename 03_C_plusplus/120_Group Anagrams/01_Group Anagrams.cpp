/* 
@ LeetCode
Group Anagrams

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 
Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

ref : https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1124/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// unordered_map 생성
		// 이때 key는 string이며 value는 vector<string>
		// string vector 속의 string을 하나 받아서 글자순 정렬
		// 정렬된 값을 unordered_map에서 비교하여 없다면 추가 (이때 key는 정렬된 string 값, value는 원래의 string 값)
		// 있다면 정렬된 string 값을 key로하여 value에 원래의 string 값을 추가
		// 마지막으로 unordered_map의 value인 vector<string>을 vector<vector<string>>에 하나씩 추가
		
		vector<vector<string>> rst;
		unordered_map<string, vector<string>> map;

		for(auto iter = strs.begin(); iter!=strs.end(); iter++){
			string tmpStr = *iter;
			sort(begin(tmpStr), end(tmpStr));
			auto tmpElm = map.find(tmpStr);
			if(tmpElm == map.end()){
				vector<string> tmpVct;
				tmpVct.push_back(*iter);
				map.insert(make_pair(tmpStr, tmpVct));
			}
			else{
				tmpElm->second.push_back(*iter);
			}
		}

		for(auto iter = map.begin(); iter!=map.end(); iter++){
			rst.push_back(iter->second);
		}

        return rst;
    }
};

int main() {
	string list1[6] = {"eat","tea","tan","ate","nat","bat"};
	vector<string> list1Vct(begin(list1), end(list1));
	
	Solution sol;

	vector<vector<string>> rst = sol.groupAnagrams(list1Vct);

	return 0;
}

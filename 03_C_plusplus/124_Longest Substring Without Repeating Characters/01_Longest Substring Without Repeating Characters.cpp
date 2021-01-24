/* 
@ LeetCode
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0
 
Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

ref : https://leetcode.com/explore/learn/card/hash-table/187/conclusion-hash-table/1135/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 문자열의 값을 하나하나 map에 넣으며 확인
		// 반복되지 않으면 find에서 end를 반환
		// 이 경우 map에 값을 추가하고, maxLenSubStr 값을 +1
		// 만약 반복된다면 maxLenSubStr와 rst 값을 비교하여 큰 값을 rst에 저장
		// 또 map을 초기화 및 현재 char 값을 추가 maxLenSubStr를 1로 변경
		// 모든 문자열의 요소에 대하여 반복
		
		int rst = 0;
		int maxLenSubStr = 0;

		unordered_map<char, int> map;

		for(auto iter = s.begin(); iter != s.end(); iter++){
			char tmpChar = *iter;
			auto elm = map.find(tmpChar);

			if(elm == map.end()){
				map.insert(make_pair(tmpChar, 1));
				maxLenSubStr++;
			}
			else{
				if(rst < maxLenSubStr){	rst = maxLenSubStr; }
				map.clear();
				map.insert(make_pair(tmpChar, 1));
				maxLenSubStr = 1;
			}
		}

		if(rst < maxLenSubStr){	rst = maxLenSubStr; }

		return rst;
    }
};

int main() {
	string s = " ";

	Solution sol;

	int rst = sol.lengthOfLongestSubstring(s);

	return 0;
}

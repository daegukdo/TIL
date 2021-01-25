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
		// 시작 문자열을 지정, 이를 기준으로 최대 연속 문자열 길이를 확인
        // 문자열의 값을 하나하나 map에 넣으며 확인
		// 반복되지 않으면 find에서 end를 반환
		// 이 경우 map에 값을 추가하고, maxLenSubStr 값을 +1
		// 만약 반복된다면 for loop 멈춤
		// 최대값을 확인하여 rst에 저장하고 maxLenSubStr를 0으로 변경
		// 시작 문자열을 올리고 다시 반복
		
		int rst = 0;
		int maxLenSubStr = 0;

		auto iterStr = s.begin();

		while(iterStr != s.end()){
			unordered_map<char, int> map;
			for(auto iter = iterStr; iter != s.end(); iter++){
				char tmpChar = *iter;
				auto elm = map.find(tmpChar);

				if(elm == map.end()){
					map.insert(make_pair(tmpChar, 1));
					maxLenSubStr++;
				}
				else{
					break;
				}
			}
			if(rst < maxLenSubStr){	rst = maxLenSubStr; }
			maxLenSubStr = 0;

			iterStr++;
		}

		return rst;
    }
};

int main() {
	string s = "asjrgapa";

	Solution sol;

	int rst = sol.lengthOfLongestSubstring(s);

	return 0;
}

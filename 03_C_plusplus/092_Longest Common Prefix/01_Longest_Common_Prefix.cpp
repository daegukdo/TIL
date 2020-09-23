/* 
@ LeetCode
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: ["flower","flow","flight"]
Output: "fl"
Example 2:
Input: ["dog","racecar","car"]
Output: ""
... Explanation: There is no common prefix among the input strings.
Note:
All given inputs are in lowercase letters a-z.
ref : https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1162/
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		// 공통된 부분을 어떻게 찾지
		// prefix라는 부분에 집중?

		// strs[0]의 char를 하나 선택
		// for로 [1][2]...에 대하여 strStr이 0인지 확인 ... 이때 needle은 length가 0이 아니어야 함
		// 만약 하나라도 0이 아니면 ""
		// 만약 모두 0이면 char를 2개로 늘려서 반복
		// 모두 통과하고 다음 char 넘어갈  fail이면 이 char들을 출력 "xxxx"

		if(strs.size() == 0) { return ""; }

		string compareStr = strs[0];
		string tmpComparer = "";

		for(int i = 0; i < compareStr.length(); i++)
		{
			tmpComparer += compareStr[i];
			for(int j = 1; j < strs.size(); j++)
			{
				int tmpInt = strStr(strs[j], tmpComparer);
				if(tmpInt != 0)
				{
					if(tmpComparer.length() == 1)
					{
						return "";
					}
					else
					{
						return tmpComparer.substr(0, tmpComparer.length() - 1);
					}
				}
			}
		}

        return compareStr;
    }

private:
	int strStr(string haystack, string needle) {
		// needle = "" -> 0
		// haystack include  needle -> first index
		// haystack does not include needle -> -1
		size_t indexSize_t = haystack.find(needle);
		int indexInt = static_cast<int>(indexSize_t);
        return indexInt;
    }
};

int main() {
	string a[1] = {"a"}; // ex : ["dog","racecar","car"]
    vector<string> v(a, *(&a + 1));

	Solution s;

	string r = s.longestCommonPrefix(v);

	return 0;
}

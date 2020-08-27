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
		// ����� �κ��� ��� ã��
		// prefix��� �κп� ����?

		// test
		int a = strStr("flower", "fl"); // result == 0: true

		// strs[0]�� char�� �ϳ� ����
		// for�� [1][2]...�� ���Ͽ� strStr�� 0���� Ȯ�� ... �̶� needle�� length�� 0�� �ƴϾ�� ��
		// ���� �ϳ��� 0�� �ƴϸ� ""
		// ���� ��� 0�̸� char�� 2���� �÷��� �ݺ�
		// ��� ����ϰ� ���� char �Ѿ �� fail�̸� �� char���� ��� "xxxx"

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

        return "";
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
	string a[3] = {"flower","flow","flight"}; // ex : ["dog","racecar","car"]
    vector<string> v(a, *(&a + 1));

	Solution s;

	string r = s.longestCommonPrefix(v);

	return 0;
}

/* 
@ LeetCode

Implement strStr()

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Constraints:
haystack and needle consist only of lowercase English characters.

ref : https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1161/
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		size_t indexSize_t = haystack.find(needle);
		int indexInt = static_cast<int>(indexSize_t);

        return indexInt;
    }
};

int main() {
	string haystack = "aaaaa"; // "aaaaa"
	string needle = ""; // "bba"

	Solution s;

	int r = s.strStr(haystack, needle);

	return 0;
}

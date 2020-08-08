/* 
@ LeetCode

Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

Each string consists only of '0' or '1' characters.

1 <= a.length, b.length <= 10^4

Each string is either "0" or doesn't contain any leading zero.

ref : https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1160/
*/

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
	{
		// string to longlong
		// string to longlong
		// add 2 data
		// iter. check is 2 over?

		int aInt = atoi(a.c_str());
		int bInt = atoi(b.c_str());

        return "";
    }
};

int main() 
{
	string a = "11";
	string b = "1";

	Solution s;

	string r = s.addBinary(a ,b);

	return 0;
}

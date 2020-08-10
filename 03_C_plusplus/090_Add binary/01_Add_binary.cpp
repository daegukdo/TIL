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

		long long aInt = stoll(a.c_str());
		long long bInt = stoll(b.c_str());

		long long addDataInt = aInt + bInt;

		long long divInt = 1;
		long long tmpIntSomeOrder = 0;

		while((addDataInt / divInt) >= 1)
		{
			tmpIntSomeOrder = ((addDataInt % (divInt * 10)) - (addDataInt % divInt)) / divInt;

			if(tmpIntSomeOrder >= 2)
			{
				addDataInt = addDataInt - 2 * divInt;
				addDataInt = addDataInt + (divInt * 10);
			}

			divInt = divInt * 10;
		}

        return to_string(addDataInt);
    }
};

int main() 
{
	string a = "111";
	string b = "11";

	Solution s;

	string r = s.addBinary(a ,b);

	return 0;
}

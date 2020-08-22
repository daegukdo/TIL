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
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
	{
		// use only string type?
		// make binary adder 
		// loop string length 

		string binResultInverse = "";

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int aStrMaxIndex = a.length();
		int bStrMaxIndex = b.length();

		string smallStr = "";
		string largeStr = "";
		int smallIndex = 0;
		int largeIndex = 0;

		if(aStrMaxIndex >= bStrMaxIndex)
		{
			smallIndex = bStrMaxIndex;
			largeIndex = aStrMaxIndex;
			smallStr = b;
			largeStr = a;
		}
		else
		{
			smallIndex = aStrMaxIndex;
			largeIndex = bStrMaxIndex;
			smallStr = a;
			largeStr = b;
		}

		for(int i = 0; i < smallIndex; i++)
		{
			binResultInverse = binResultInverse + _calBinDigit(smallStr[i], largeStr[i]);
		}

		for(int i = smallIndex; i < largeIndex; i++)
		{
			binResultInverse = binResultInverse + largeStr[i];
		}

		for(int i = 0; i <= largeIndex; i++)
		{
			if(_isOrderUp(binResultInverse[i]))
			{
				binResultInverse = _addUpBit(binResultInverse, i);
			}
		}

		reverse(binResultInverse.begin(), binResultInverse.end());

        return binResultInverse;
    }

private:
	char _calBinDigit(char a, char b)
	{
		if(a == '1' && b == '1')
		{
			return '2';
		}

		if(a == '0' && b == '0')
		{
			return '0';
		}

		if(a == '2' || b == '2')
		{
			return '3';
		}

		return '1';
	}

	bool _isOrderUp(char ch)
	{
		if(ch >= '2')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string _addUpBit(string reverseOrderBitStr, int order)
	{
		string tmpStr = reverseOrderBitStr;
		int tmpStrLength = tmpStr.length() - 1;

		if(tmpStr[order] == '2')
		{
			tmpStr[order] = '0';

			if(order == tmpStrLength)
			{
				tmpStr = tmpStr + '1';
			}
			else
			{
				tmpStr[order + 1] = _calBinDigit(tmpStr[order + 1] , '1');
			}
		}
		else if(tmpStr[order] == '3')
		{
			tmpStr[order] = '1';

			if(order == tmpStrLength)
			{
				tmpStr = tmpStr + '1';
			}
			else
			{
				tmpStr[order + 1] = _calBinDigit(tmpStr[order + 1] , '1');
			}
		}

		return tmpStr;
	}
};

int main() 
{
	string a = "1";
	string b = "111";

	Solution s;

	string r = s.addBinary(a ,b);

	return 0;
}

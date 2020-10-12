/* 
@ LeetCode

Reverse Words in a String III

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string.

ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1165/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> strChunkVct; 
        istringstream iss(s); 
        for(string _s; iss >> _s; ) 
            strChunkVct.push_back(_s);

	    int numStrChunk = strChunkVct.size();
        string result = "";
		string tmp = "";

		for(int i = 0; i < numStrChunk; i++){
			tmp = strChunkVct[i];
			reverse(tmp.begin(), tmp.end());
            result += tmp;
			tmp.clear();
            if(i != numStrChunk - 1){ result += " "; }
        }

        return result;
    }
};

int main() {
	string  s = "Let's take LeetCode contest";

	Solution sol;

	string r = sol.reverseWords(s);

	return 0;
}

/* 
@ LeetCode

Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words.
Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Example 4:
Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"

Example 5:
Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
 
Constraints:
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 
Follow up:
Could you solve it in-place with O(1) extra space?

ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1164/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
        
        for(int i = numStrChunk - 1; i >= 0; i--){
            result += strChunkVct[i];
            if(i != 0){ result += " "; }
        }
            
        return result;
    }
};

int main() {
	string strData = "the sky is blue";
	
	Solution sol;

	string rst = sol.reverseWords(strData);

    cout << rst << endl;

	return 0;
}

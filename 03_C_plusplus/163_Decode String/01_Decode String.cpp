/*
@ LeetCode - Decode String

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.

For example, there won't be input like 3a or 2[4].


Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Example 4:
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

ref : https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1379/
*/

#include <iostream>  
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    char leftBrk = '[';
    char rightBrk = ']';

    int _findRightBrkIdx(string s) {
        int rst = 0;
        stack<int> stackIntIdxLeftBrk;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == leftBrk) {
                stackIntIdxLeftBrk.push(i);
            }
            else if (s[i] == rightBrk) {
                stackIntIdxLeftBrk.pop();
                if (stackIntIdxLeftBrk.empty()) {
                    return i;
                }
            }
        }

        return rst;
    }

public:
    string decodeString(string s) {
        string rst = "";
        stack<string> strStack;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                int beginIntIdx = i;
                int endIntIdx = 0;
                for (int j = beginIntIdx; j < s.length(); j++) {
                    if (s[j] == leftBrk) {
                        endIntIdx = j - 1;
                        break;
                    }
                }

                int repeatNum = 0;
                if (beginIntIdx == endIntIdx) {
                    repeatNum = s[i] - '0';
                }
                else {
                    repeatNum = stoi(s.substr(beginIntIdx, endIntIdx - beginIntIdx + 1));
                }

                int beginIdx = endIntIdx + 1;
                int endIdx = beginIdx + _findRightBrkIdx(s.substr(beginIdx, s.length() - beginIdx));

                string tmpStr = "";
                for (int r = 0; r < repeatNum; r++) {
                    tmpStr = tmpStr + decodeString(s.substr(beginIdx + 1, endIdx - beginIdx - 1));
                }
                strStack.push(tmpStr);
                s.erase(i, endIdx - i);
            }
            else {
                string tmpStr = "";
                tmpStr = tmpStr + s[i];
                strStack.push(tmpStr);
            }
        }

        while (!strStack.empty()) {
            rst = strStack.top() + rst;
            strStack.pop();
        }

        return rst;
    }
};

int main() {
    string s = "3[2[leet]code]";

    Solution sol;

    string rst = sol.decodeString(s);

    return 0;
}

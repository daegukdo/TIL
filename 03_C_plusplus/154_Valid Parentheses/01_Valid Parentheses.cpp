/*
@ LeetCode - Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

Hint #1
An interesting property about a valid parenthesis expression is that a sub-expression of a valid expression should also be a valid expression.
(Not every sub-expression) e.g.
{ { } [ ] [ [ [ ] ] ] } is VALID expression
          [ [ [ ] ] ]    is VALID sub-expression
  { } [ ]                is VALID sub-expression
Can we exploit this recursive structure somehow?

Hint #2
What if whenever we encounter a matching pair of parenthesis in the expression, we simply remove it from the expression?
This would keep on shortening the expression. e.g.
{ { ( { } ) } }
      |_|

{ { (      ) } }
    |______|

{ {          } }
  |__________|

{                }
|________________|

VALID EXPRESSION!

Hint #3
The stack data structure can come in handy here in representing this recursive structure of the problem.
We can't really process this from the inside out because we don't have an idea about the overall structure.
But, the stack can help us process this recursively i.e. from outside to inwards.

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1361/
ref : https://stackoverflow.com/questions/43629363/how-to-check-if-a-string-contains-a-char
*/

#include <iostream>  
#include <string>
#include <stack>

using namespace std;

const string fail = "X";
const char b_0 = '{';
const char d_0 = '}';
const char b_1 = '[';
const char d_1 = ']';
const char b_2 = '(';
const char d_2 = ')';

class Solution {
private:
    string _eleminateBracket(string _s, char bracket_L, char bracket_R) {
        while (_s.find(bracket_L) != string::npos) {
            int strStartLen = _s.size();

            int ref = 0;
            for (int i = 0; i < strStartLen; i++) {
                if (_s[i] == bracket_L) {
                    ref = i;
                    break;
                }
            }

            int trg = 0;
            for (int i = ref; i < strStartLen; i++) {
                if (_s[i] == bracket_R) {
                    trg = i;
                    break;
                }
            }

            _s[ref] = ' ';
            _s[trg] = ' ';
            string subStr = _s.substr(ref + 1, trg - ref - 1);
            if (!_isOnlySpace(subStr)) {
                return fail;
            }
        }

        return _s;
    }
    bool _isOnlySpace(string _s) {
        for (int i = 0; i < _s.size(); i++) {
            if (_s[i] != ' ') {
                return false;
            }
        }
        return true;
    }

public:
    bool isValid(string s) {
        // nearst ã��?
        string r0 = _eleminateBracket(s, b_0, d_0);
        if (r0 == fail) { return false; }
        string r1 = _eleminateBracket(r0, b_1, d_1);
        if (r1 == fail) { return false; }
        string r2 = _eleminateBracket(r1, b_2, d_2);
        if (r2 == fail) { return false; }

        return true;
    }
};

int main() {
    string s = "{[]}";

    Solution sol;
    bool rst = sol.isValid(s);

    return 0;
}
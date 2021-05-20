/*
@ LeetCode - Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid.

That means the expression would always evaluate to a result, and there will not be any division by zero operation.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

Constraints:
1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1394/
ref : https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
ref : https://fist0512.tistory.com/68
*/

#include <iostream>  
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    stack<string> stackStr;

    bool isOperator(string token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") return true;
        else return false;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<string> input;

        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i]) == true) {
                if (tokens[i] == "+") {
                    int second = atoi(input.top().c_str());
                    input.pop();

                    int first = atoi(input.top().c_str());
                    input.pop();

                    input.push(to_string(first + second));
                }
                else if (tokens[i] == "-") {
                    int second = atoi(input.top().c_str());
                    input.pop();

                    int first = atoi(input.top().c_str());
                    input.pop();

                    input.push(to_string(first - second));
                }
                else if (tokens[i] == "*") {
                    int second = atoi(input.top().c_str());
                    input.pop();

                    int first = atoi(input.top().c_str());
                    input.pop();

                    input.push(to_string(first * second));
                }
                else if (tokens[i] == "/") {
                    int second = atoi(input.top().c_str());
                    input.pop();

                    int first = atoi(input.top().c_str());
                    input.pop();

                    input.push(to_string(first / second)); //if first is zero : need exception case
                }
            }
            else {
                input.push(tokens[i]);
            }
        }

        return atoi(input.top().c_str());
    }
};

int main() {
    /* Explanationl; Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] => Output: 22
    * "10","6","9","3","+","-11","*","/","*","17","+","5","+" => ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    * "10","6","12","-11","*","/","*","17","+","5","+" => ((10 * (6 / (12 * -11))) + 17) + 5
    * "10","6","-132","/","*","17","+","5","+" => ((10 * (6 / -132)) + 17) + 5
    * "10","0","*","17","+","5","+" => ((10 * 0) + 17) + 5
    * "0","17","+","5","+" => (0 + 17) + 5
    * "17","5","+" => 17 + 5
    * "22" => rst!
    */
    string oprArr[13] = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    vector<string> oprVct(begin(oprArr), end(oprArr));

    Solution sol;
    int rst = sol.evalRPN(oprVct);

    return 0;
}

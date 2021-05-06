/*
@ LeetCode - Daily Temperatures

Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature.
If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000].
Each temperature will be an integer in the range [30, 100].

If the temperature is say, 70 today, then in the future a warmer temperature must be either 71, 72, 73, ..., 99, or 100.
We could remember when all of them occur next.

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1358/
ref : https://www.tutorialspoint.com/daily-temperatures-in-cplusplus
*/

#include <iostream>  
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    stack<int> stackTemp;
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> rst;
        int n = T.size();
        
        for (int i = 0; i < n; i++) {
            rst.push_back(0);
            while (!stackTemp.empty() && T[stackTemp.top()] < T[i]) {
                int j = stackTemp.top();
                stackTemp.pop();
                rst[j] = i - j;
            }
            stackTemp.push(i);
        }

        return rst;
    }
};

int main() {
    int tempArr[8] = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> tempVct(begin(tempArr), end(tempArr));

    Solution sol;
    vector<int> rst = sol.dailyTemperatures(tempVct);

    return 0;
}

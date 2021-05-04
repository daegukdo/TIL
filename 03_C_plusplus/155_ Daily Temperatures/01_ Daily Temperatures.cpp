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
*/

#include <iostream>  
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> stackTemp;
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // define rstVct
        vector<int> rst;
        
        // set stack and init. vct
        for(int i = 0; i < T.size(); i++){
            stackTemp.push(T[i]);
            rst.push_back(0);
        }
        
        // compare LAST IN element
        while(stackTemp.size() != 0){
            int temp = stackTemp.top();
            int idx = stackTemp.size() - 1;
            
            for(int i = idx; i > -1; i--){
                int tmpInt = T[i];
                if(tmpInt < temp){
                    rst[i] = idx - i;
                }
            }
            
            stackTemp.pop();
        }
        
        // 몇일 뒤에 따듯해질까요?
        for(int i = 0; i < rst.size(); i++){
            cout << rst[i] << endl;
        }
        
        return rst;
    }
};

int main() {
    int tempArr[8] = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> tempVct(begin(tempArr), end(tempArr));
    
    Solution sol;
    vector<int> rst = sol.dailyTemperatures(tempVct);
    
    return 0;
}

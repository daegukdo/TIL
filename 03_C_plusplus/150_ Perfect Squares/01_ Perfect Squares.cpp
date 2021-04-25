/*
@ LeetCode

Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer;
 in other words, it is the product of some integer with itself. 
 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:
1 <= n <= 10^4

ref : https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1371/
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int rstStep = 1;
        int perfectNum = 1;
        int perfectNumStep = 1;
        
        while(n >= perfectNum){
            int tmpInt = n;
            int tmpStep = 0;
            while(tmpInt >= perfectNum){
                tmpInt = tmpInt - perfectNum;
                tmpStep++;
                //debugOutputInt(tmpStep);
            }
            if(tmpInt > 0){
                tmpStep += numSquares(tmpInt);
                tmpInt = 0;
                //debugOutputInt(tmpStep);
            }
            if(tmpInt == 0){
                if((rstStep != 1 & rstStep > tmpStep) || (rstStep == 1))
                {
                    rstStep = tmpStep;
                }
            }
            perfectNumStep++;
            perfectNum = perfectNumStep * perfectNumStep;
            //debugOutputInt(-9999);
        }
        
        return rstStep;
    }
private:
    void debugOutputInt(int n){
        cout << n << endl;
    }
};

int main() {
    Solution s;
    int rst = s.numSquares(13);

    cout << rst << endl;

	return 0;
}

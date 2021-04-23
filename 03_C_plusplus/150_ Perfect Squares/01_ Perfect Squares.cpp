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


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int rstStep = 1;
        int perfectNum = 0;
        int perfectNumStep = 1;
        
        while(n > perfectNum){
            perfectNum = perfectNumStep * perfectNumStep;
            debugOutputInt(perfectNum);
            int tmpInt = n;
            int tmpStep = 0;
            while(tmpInt >= perfectNum){
                tmpInt = tmpInt - perfectNum;
                tmpStep++;
            }
            if(tmpInt > 0){
                tmpStep += numSquares(tmpInt);
            }
            if(rstStep < tmpStep){
                rstStep = tmpStep;
            }
            perfectNumStep++;
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
    int rst = s.numSquares(2);

    cout << rst << endl;

	return 0;
}

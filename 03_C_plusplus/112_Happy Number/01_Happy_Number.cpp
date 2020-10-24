/* 
@ LeetCode

Happy Number

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1. 

Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 
Input: 19
Output: true

Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

ref : https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1131/
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> vctNum;
        int startNum = n - 0;
        int sum = 0;
        int tmpInt = 0;
        string tmpStr = "";
        
        while(true){
            tmpStr = to_string(startNum);
            for(int i = 0; i < tmpStr.length(); i++){
                tmpInt = tmpStr[i] - '0';
                vctNum.push_back(tmpInt);
            }
            
            for(int i : vctNum){
                sum += i * i;
            }
            
            if(sum == 1){
                return true;
            }else if(sum == n){
                return false;
            }
            
            startNum = sum - 0;
            sum = 0;
            vctNum.clear();
        }
        
        return false;
    }
};

int main() {
    int n = 19;
	
	Solution sol;

	bool rst = sol.isHappy(n);
	
	if(rst) { cout << "dup!" << endl; }

	return 0;
}

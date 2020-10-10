/* 
@ LeetCode

Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.
Notice that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:
Could you optimize your algorithm to use only O(k) extra space?

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
 
Constraints:
0 <= rowIndex <= 40

ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1171/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows;
        rows.push_back(1);
        
        for(int i = 0; i < rowIndex; i++){
            vector<int> tmpVct(rows.size(), 0);
            copy(rows.begin(), rows.end(), tmpVct.begin());
            rows.clear();
            tmpVct.insert(tmpVct.begin(), 0);
            tmpVct.push_back(0);
            for(int k = 0; k < tmpVct.size() - 1; k++){
                rows.push_back(tmpVct[k] + tmpVct[k + 1]);
            }
        }
        
        return rows;    
    }
};

int main() {
	int rowIndex = 3;

	Solution sol;

	vector<int> rst = sol.getRow(rowIndex);

    for(int i = 0; i < rst.size(); i++){
        cout << rst[i] << endl;
    }

	return 0;
}

/*
@ LeetCode - 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

ref : https://leetcode.com/explore/learn/card/queue-stack/239/conclusion/1388/
*/

#include <iostream>  
#include <vector>

using namespace std;

class Solution {
private: 
    void _updateMatrix(vector<vector<int>>& mat, int row, int col) {
        if (mat[row][col] != 0) {
            mat[row][col] = _findNumOfStepZero(mat, row, col, 1);
        }
    }

    int _findNumOfStepZero(vector<vector<int>>& mat, int row, int col, int startStep) {
        int stepCol = startStep + 0;
        int stepRow = startStep + 0;

        int matColMin = 0;
        int matRowMin = 0;
        int matColMax = mat[0].size();
        int matRowMax = mat.size();

        int colSign = 1;
        int rowSign = 1;

        // is need visited?
        // circle loop!

        return _findNumOfStepZero(mat, row, col, startStep + 1);
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for (int row = 0; row < mat.size(); row++) {
            for (int col = 0; col < mat[0].size(); col++) {
                _updateMatrix(mat, row, col);
            }
        }
    }
};

int main() {

    return 0;
}

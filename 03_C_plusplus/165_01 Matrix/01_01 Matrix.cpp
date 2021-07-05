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
ref : https://butter-shower.tistory.com/176
*/

#include <iostream>  
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
private: 
    vector<pair<int, int>> vctRowCol;

    void _updateMatrix(vector<vector<int>>& mat, int row, int col) {
        if (mat[row][col] != 0) {
            mat[row][col] = _findNumOfStepZero(mat, row, col, 1);
        }
    }

    int _findNumOfStepZero(vector<vector<int>>& mat, int row, int col, int startStep) {
        int result = INT_MAX;

        for (auto iter = vctRowCol.begin(); iter != vctRowCol.end(); iter++) {
            int diff = abs(iter->first - row) + abs(iter->second - col);
            if (result > diff) {
                result = diff;
            }
        }

        return result;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for (int row = 0; row < mat.size(); row++) {
            for (int col = 0; col < mat[0].size(); col++) {
                if (mat[row][col] == 0) {
                    vctRowCol.push_back(make_pair(row, col));
                }
            }
        }

        for (int row = 0; row < mat.size(); row++) {
            for (int col = 0; col < mat[0].size(); col++) {
                _updateMatrix(mat, row, col);
            }
        }

        return mat;
    }
};

int main() {

    return 0;
}

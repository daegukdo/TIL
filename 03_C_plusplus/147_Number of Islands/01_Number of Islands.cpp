/*
@ LeetCode

Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 

You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

ref : https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1374/
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int numOfIsland = 0;

		const char land = '1';
		const char water = '0';

		int m = grid.size();
		int n = grid[0].size();
		
		queue<int> qFirst;
		queue<int> qSecond;

		// 순서대로 비교하여 같은 것이 있으면 이어진 land로 간주

        return 0;
    }
};

int main() {

	return 0;
}
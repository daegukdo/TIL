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
ref : https://gamjatwigim.tistory.com/146
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	const char land = '1';
	const char water = '0';

	void land2waterBFS(vector<vector<char>>& grid, int _i, int _j) {
		int mPos = _i;
		int nPos = _j;

		int m = grid.size();
		int n = grid[0].size();

		queue<pair<int, int>> q;

		for (int i = mPos; i < m; i++) {
			for (int j = nPos; j < n; j++) {
				if (grid[i][j] == land) {
					q.push(make_pair(i, j));
				}
				else {
					break;
				}
			}
		}

		return;
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		int numOfIsland = 0;

		int m = grid.size();
		int n = grid[0].size();

		queue<int> qFirst;
		queue<int> qPast;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == land) {
					numOfIsland++;
					land2waterBFS(grid, i, j);
				}
			}
		}

		return 0;
	}
};

int main() {

	return 0;
}
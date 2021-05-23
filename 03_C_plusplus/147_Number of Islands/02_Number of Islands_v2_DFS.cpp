/*
@ LeetCode -  Number of Islands

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

ref : https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1380/
*/

#include <iostream>  
#include <vector>

using namespace std;
 
class Solution {
private:
	void visitedLandDFS(vector<vector<char>>& grid, int r, int c){
		/*cout << r;
		cout << ", ";
		cout << c << endl;*/

		if(grid[r][c] == '1'){
			grid[r][c] = 0;
		}

		if(c < grid[r].size() -1  && grid[r][c+1] == '1' ){
			visitedLandDFS(grid, r, c+1);
		}
		if(c > 0                  && grid[r][c-1] == '1'){
			visitedLandDFS(grid, r, c-1);
		}
		if(r < grid.size() -1     && grid[r+1][c] == '1'){
			visitedLandDFS(grid, r+1, c);
		}
		if(r > 0                  && grid[r-1][c] == '1'){
			visitedLandDFS(grid, r-1, c);
		}
	}

public:
    int numIslands(vector<vector<char>>& grid) {
    	int rst = 0;

		int row = grid.size();
		int col = grid[0].size();

		for(int r = 0; r < row; r++){
			for(int c = 0; c < col; c++){
				if(grid[r][c] == '1'){
					rst++;
					visitedLandDFS(grid, r, c);
				}
			}
		}

        return rst;
    }
};
 
int main()
{
	vector<vector<char>> grid;

	// row 4; col 5; 
	char M[][5] = { { '1', '1', '0', '0', '0' },
                    { '1', '1', '0', '0', '0' },
                    { '0', '0', '1', '0', '0' },
                    { '0', '0', '0', '1', '1' } };

	for(int r = 0; r < 4; r++){
		vector<char> tmpVectChar(begin(M[r]), end(M[r]));
		grid.push_back(tmpVectChar);
	}

	//char c0[5] = {'1','1','1','1','0'};
	//char c1[5] = {'1','1','0','1','0'};
	//char c2[5] = {'1','1','0','0','0'};
	//char c3[5] = {'0','0','0','0','0'};
	//vector<char> v0(begin(c0), end(c0));
	//vector<char> v1(begin(c1), end(c1));
	//vector<char> v2(begin(c2), end(c2));
	//vector<char> v3(begin(c3), end(c3));

	//vector<vector<char>> grid;
	//grid.push_back(v0);
	//grid.push_back(v1);
	//grid.push_back(v2);
	//grid.push_back(v3);

	Solution sol;

	int rst = sol.numIslands(grid);

    return 0;
}
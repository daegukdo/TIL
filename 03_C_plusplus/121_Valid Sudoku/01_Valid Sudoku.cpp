/* 
@ LeetCode
Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 
Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false

Explanation: 
Same as Example 1, except with the 5 in the top left corner being modified to 8. 
Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 
Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.

ref : https://leetcode.com/explore/learn/card/hash-table/185/hash_table_design_the_key/1126/
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		// vct[행][열]

		// 행 검사를 위한 unordered_map을 생성하고 1~9까지 키를 가질 수 있게 함
		// 열 검사를 위한 unordered_map을 생성하고 1~9까지 키를 가질 수 있게 함
		// 네모 검사를 위한 unordered_map을 생성하고 1~9까지 키를 가질 수 있게 함

		// 행 검사
		// 열 검사
		// 네모 검사

        return true;
    }
};

int main() {
	char list1[9][9] = {{'5', '3', '.',  '.', '7', '.',  '.', '.', '.'},
						{'6', '.', '.',  '1', '9', '5',  '.', '.', '.'},
				      	{'.', '9', '8',  '.', '.', '.',  '.', '6', '.'},

				    	{'8', '.', '.',  '.', '6', '.',  '.', '.', '3'},
					    {'4', '.', '.',  '8', '.', '3',  '.', '.', '1'},
					    {'7', '.', '.',  '.', '2', '.',  '.', '.', '6'},

					    {'.', '6', '.',  '.', '.', '.',  '2', '8', '.'},
					    {'.', '.', '.',  '4', '1', '9',  '.', '.', '5'},
					    {'.', '.', '.',  '.', '8', '.',  '.', '7', '9'}};

	vector<vector<char>> list1Vct;

	int row = sizeof(list1) / sizeof(list1[0]);
	int col = sizeof(list1[0]) / sizeof(list1[0][0]);

	for(int i = 0; i < row; i++){
		vector<char> tmpVct;
		for(int j = 0; j < col; j++){
			tmpVct.push_back(list1[i][j]);
		}
		list1Vct.push_back(tmpVct);
	}
	
	Solution sol;

	bool rst = sol.isValidSudoku(list1Vct);

	return 0;
}

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

		vector<vector<char>> rowVct(9, vector<char>(9, ' '));
		vector<vector<char>> colVct(9, vector<char>(9, ' '));
		vector<vector<char>> boxVct(9, vector<char>());

		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size(); j++){
				rowVct[i][j] = board[i][j];
				colVct[j][i] = board[i][j];
				
				if(j >= 0 && j < 3 && i >= 0 && i < 3){
					boxVct[0].push_back(board[i][j]);
				}
				else if(j >= 3 && j < 6 && i >= 0 && i < 3){
					boxVct[1].push_back(board[i][j]);
				}
				else if(j >= 6 && j < 9 && i >= 0 && i < 3){
					boxVct[2].push_back(board[i][j]);
				}
				else if(j >= 0 && j < 3 && i >= 3 && i < 6){
					boxVct[3].push_back(board[i][j]);
				}
				else if(j >= 3 && j < 6 && i >= 3 && i < 6){
					boxVct[4].push_back(board[i][j]);
				}
				else if(j >= 6 && j < 9 && i >= 3 && i < 6){
					boxVct[5].push_back(board[i][j]);
				}
				else if(j >= 0 && j < 3 && i >= 6 && i < 9){
					boxVct[6].push_back(board[i][j]);
				}
				else if(j >= 3 && j < 6 && i >= 6 && i < 9){
					boxVct[7].push_back(board[i][j]);
				}
				else if(j >= 6 && j < 9 && i >= 6 && i < 9){
					boxVct[8].push_back(board[i][j]);
				}
			}
		}

        return true;
    }

private:
	bool isValidVct(vector<char>& vct){
		unordered_map<int, char> map;

		
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

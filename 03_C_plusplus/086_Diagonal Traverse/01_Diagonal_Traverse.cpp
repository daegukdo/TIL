/* 
@ LeetCode

Diagonal Traverse

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Note:

The total number of elements of the given matrix will not exceed 10,000.

ref : https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1167/
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
	{
        vector<int> diagonalTraverseResult;
		
		bool iter = true;

		int checker = 0;
		bool isUp = true;
		bool isReduce = false;

		int tracerM = 0;
		int tracerN = 0;
		
		while(iter)
		{
			vector<int> tmpVct;

			int m = 0;
			int n = checker;

			for(int i = 0; i <= checker; i++)
			{
				tmpVct.push_back(matrix[m][n]);

				if(!isReduce)
				{
				    m++;
				    n--;
				}
				else
				{
				    m--;
				    n++;
				}
			}

			if((checker == matrix[0].size() - 1) && !isReduce)
			{
				isReduce = true;
			}
			
			if(!isReduce)
			{
			    checker++;
			}
			else
			{
				checker--;
			}


			diagonalTraverseResult.insert(diagonalTraverseResult.end(), tmpVct.begin(), tmpVct.end());

			if(diagonalTraverseResult.size() == matrix[0].size() * matrix.size())
			{
				iter = false;
			}
		}

		return diagonalTraverseResult;
    }
};

template <size_t m, size_t n>

vector<vector<int>> mtx2VctArray(int (&mtx)[m][n]) 
{
	vector<vector<int>> vctArray;

    for (int i = 0; i < m; ++i) 
	{
		vector<int> tmpVct;
        for (int j = 0; j < n; ++j) 
		{
			// for printing
            // cout << mtx[i][j] << " ";
			tmpVct.push_back(mtx[i][j]);
        }
		// for printing
        // cout << endl;
		vctArray.push_back(tmpVct);
    }
	
	return vctArray;
}

int main() 
{
	const size_t rowsM = 3;
	const size_t columnsN = 3;

	int mtx[rowsM][columnsN] = {1,2,3,4,5,6,7,8,9};

	Solution s;

	vector<int> r0 = s.findDiagonalOrder(mtx2VctArray(mtx));

	return 0;
}

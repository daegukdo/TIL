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
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
	{
        vector<int> diagonalTraverseResult;
		
		bool iter = true;
		bool isUp = true;
		bool isReduce = false;

		int checker = 0;

		int tracerM = 0;
		int tracerN = 0;
		
		while(iter)
		{
			// cal. each diagonal line   //////////
			vector<int> tmpVct;

			if(isReduce)
			{
				checker--;
			}
			else
			{
				checker++;
			}

			if(checker % 2 == 1)
			{
				isUp = true;
			}
			else
			{
				isUp = false;
			}

			int m = tracerM;
			int n = tracerN;

			for(int i = 0; i < checker; i++)
			{
				tmpVct.push_back(matrix[m][n]);

				m++;
				n--;
			}

			if(tracerN != matrix.size() - 1)
			{
			    tracerN++;
			}
			else
			{
				tracerM++;

				if(!isReduce)
				{
				    isReduce = true;
				}
			}
			// end cal. each diagonal line //////////

			if(isUp)
			{
				reverse(tmpVct.begin(), tmpVct.end());
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

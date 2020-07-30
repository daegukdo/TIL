/* 
@ LeetCode

 - Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 - Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output: [1,2,3,6,9,8,7,4,5]

 - Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]

Output: [1,2,3,4,8,12,11,10,9,5,6,7]

ref : https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1168/
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		// xUp, xDown, yUp, yDown
		vector<bool> direction;
		direction.push_back(false);
		direction.push_back(false);
		direction.push_back(false);
		direction.push_back(false);

		// axis max
		int mMax = 0;
		int nMax = 0;

        return;
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

	vector<int> r0 = s.spiralOrder(mtx2VctArray(mtx));

	return 0;
}

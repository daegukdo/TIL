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
		vector<int> spiralOrderVct;

		// xUp = 0, yDown = 1, xDown = 2, yUp = 3
		int directionInt = 0;

		// axis max : y, x
		int mMax = matrix.size() - 1;
		int nMax = matrix[0].size() - 1;
		int mMin = 0;
		int nMin = 0;

		bool isIter = true;

		int numOfIter = 0;

		int m = 0;
		int n = 0;

		// working step
		while(isIter)
		{
			int maxValue = 0;

			switch (directionInt)
			{
			case 0:
				if(nMax == n) { directionInt++; mMin++; }
				else { spiralOrderVct.push_back(matrix[m][n]); n++; }
				break;
			case 1:
				if(mMax == m) { directionInt++; nMax--; }
				else { spiralOrderVct.push_back(matrix[m][n]); m++; }
				break;
			case 2:
				if(nMin == n) { directionInt++; mMax--; }
				else { spiralOrderVct.push_back(matrix[m][n]); n--; }
				break;
			case 3:
				if(nMin == m) { directionInt++; nMin++; }
				else { spiralOrderVct.push_back(matrix[m][n]); m--; }
				break;
			}

			if(directionInt == 4)
			{
				directionInt = 0;
				m = mMin;
				n = nMin;
			}

			if(spiralOrderVct.size() == matrix.size() * matrix[0].size())
			{
				isIter = false;
			}
		}

        return spiralOrderVct;
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

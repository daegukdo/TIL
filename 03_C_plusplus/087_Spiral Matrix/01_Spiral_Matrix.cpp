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
		int mMtx = static_cast<int>(matrix.size());
		int nMtx = static_cast<int>(matrix[0].size());

		vector<int> spiralOrderVct;

		if(mMtx == 0 || nMtx == 0)
		{
			return spiralOrderVct;
		}

		// xUp = 0, yDown = 1, xDown = 2, yUp = 3
		int directionInt = 0;

		// axis max : y, x
		int mMax = mMtx - 1;
		int nMax = nMtx - 1;
		int mMin = 0;
		int nMin = 0;

		bool isIter = true;

		int numOfIter = 0;

		int m = 0;
		int n = 0;

		int count = 0;

		// working step
		while(isIter)
		{
			int maxValue = 0;

			switch (directionInt)
			{
			case 0:
				spiralOrderVct.push_back(matrix[m][n]); n++;
				if(nMax == n) { directionInt++; }
				break;
			case 1:
				spiralOrderVct.push_back(matrix[m][n]); m++;
				if(mMax == m) { directionInt++; }
				break;
			case 2:
				spiralOrderVct.push_back(matrix[m][n]); n--;
				if(nMin == n) { directionInt++; }
				break;
			case 3:
				spiralOrderVct.push_back(matrix[m][n]); m--;
				if(nMin == m) { directionInt++; }
				break;
			}

			count++;

			if(directionInt == 4)
			{
				directionInt = 0;
				mMax--;
				mMin++;
				nMax--;
				nMin++;

				m++;
				n++;
			}

			if(count == mMtx * nMtx)
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
	const size_t columnsN = 4;

	int mtx[rowsM][columnsN] = {1,2,3,4,5,6,7,8,9,10,11,12};

	Solution s;

	vector<int> r0 = s.spiralOrder(mtx2VctArray(mtx));

	return 0;
}

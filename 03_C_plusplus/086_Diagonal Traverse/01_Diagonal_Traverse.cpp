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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
  {
    vector<int> diagonalTraverseResult;

	if(matrix.size() == 0) { return diagonalTraverseResult; }
    
    int lineM = matrix.size();
    int lineN = matrix[0].size();
    int matAllEle = lineM * lineN;
    
    bool isIter = true;
    int iterCount = 0;
    
    int diagonalLinerM = 0;
    int diagonalLinerN = 0;
    int countEle = 0;
    
    while(isIter)
    {
      int m = diagonalLinerM;
      int n = diagonalLinerN;
      vector<int> tmpVct;
    
      while(true)
      {
        cout << m << endl;
        cout << n << endl;
        tmpVct.push_back(matrix[m][n]);
        countEle++;
        m--;
        n++;
      
        if((m < 0) || (n >= lineN))
        {
          break;
        }
      }
    
      if(iterCount % 2 != 0)
      {
        reverse(tmpVct.begin(), tmpVct.end());
      }
    
      diagonalTraverseResult.insert(diagonalTraverseResult.end(), tmpVct.begin(), tmpVct.end());
    
      if(diagonalLinerM < lineM - 1)
      {
        diagonalLinerM++;
      }
      else
      {
        diagonalLinerN++;
      }
    
      if(matAllEle == countEle)
      {
        isIter = false;
      }
    
      iterCount++;
    
      cout << "---" << endl;
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
	  tmpVct.push_back(mtx[i][j]);
    }
		vctArray.push_back(tmpVct);
  }
  return vctArray;
}

int main() 
{
  const size_t rowsM = 1;
  const size_t columnsN = 1;

  int mtx[rowsM][columnsN] = {1};

  Solution s;
	
  vector<vector<int>> vctArray = mtx2VctArray(mtx);

  vector<int> r0 = s.findDiagonalOrder(vctArray);
	
  cout << "___result___" << endl;
	
  for(int i = 0; i < r0.size(); i++)
  {
    cout << r0[i] << endl;
  }
	
  cout << "___------___" << endl;
  cout << "___endrst___" << endl;

  return 0;
}

/* 
@ LeetCode

Pascal's Triangle

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5

Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

ref : https://leetcode.com/explore/learn/card/array-and-string/202/introduction-to-2d-array/1170/
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
	{
		vector<vector<int>> pascalVct;
		vector<int> lineVct;
		vector<int> lineNextVct;

		if(numRows == 0)
		{
			return pascalVct;
		}

		if(numRows >= 1)
		{
			lineVct.push_back(1);

			pascalVct.push_back(lineVct);

			for(int i = 1; i < numRows; i++)
			{
				lineVct.insert(lineVct.begin(), 0);
				lineVct.push_back(0);

				for(int j = 0; j < i + 1; j++)
				{
					lineNextVct.push_back(lineVct[j] + lineVct[j + 1]);
				}

				pascalVct.push_back(lineNextVct);
				lineVct = lineNextVct;
				lineNextVct.clear();
			}
		}

        return pascalVct;
    }
};

int main() 
{
	int inputNumber = 4;

	Solution s;

	vector<vector<int>> r0 = s.generate(inputNumber);

	return 0;
}

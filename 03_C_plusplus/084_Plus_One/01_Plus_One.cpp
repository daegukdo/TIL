/* 
@ LeetCode

Plus One

Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
	{
		vector<int> tmpVct(digits.size() ,0);
		tmpVct.assign(digits.begin(), digits.end());

		bool isRecursive = true;
		int digitsOrder = tmpVct.size() - 1;

		while(isRecursive)
		{
			tmpVct[digitsOrder]++;
			if(tmpVct[digitsOrder] == 10)
			{
				tmpVct[digitsOrder] = 0;
				digitsOrder--;
				if(digitsOrder < 0)
				{
					tmpVct.insert(tmpVct.begin(), 1);
					isRecursive = false;
				}
			}
			else
			{
				isRecursive = false;
			}
		}

		return tmpVct;
    }
};

int main() 
{
	int a[4] = {4,3,9,9};
    vector<int> v(a, *(&a + 1));

	Solution s;

	vector<int> r0 = s.plusOne(v);

	return 0;
}

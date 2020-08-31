/* 
@ LeetCode

Array Partition I

Given an array of 2n integers, your task is to group these integers into n pairs of integer,
say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:
1. n is a positive integer, which is in the range of [1, 10000].
2. All the integers in the array will be in the range of [-10000, 10000].

ref : https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1154/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        return 0;
    }
};

int main() 
{
	int a[4] = {1,4,3,2};
	vector<int> v(a, *(&a + 1));

	Solution s;

	int r = s.arrayPairSum(v);

	return 0;
}

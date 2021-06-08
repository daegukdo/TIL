/*
@ LeetCode - Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

ref : https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1389/
ref : https://www.tutorialcup.com/interview/dynamic-programming/target-sum.htm
*/

#include <iostream>  
#include <vector>

using namespace std;

class Solution
{
public:
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        calculate(nums, 0, 0, S);
        return count;
    }
    void calculate(vector<int>& nums, int pos, int sum, int S)
    {
        if (pos == nums.size())
        {
            if (sum == S)
                count++;
            return;
        }
        calculate(nums, pos + 1, sum + nums[pos], S);
        calculate(nums, pos + 1, sum - nums[pos], S);
    }
};

int main() {
	vector<int> nums{ 1,1,1,1,1 };
	int target = 3;

	Solution sol;
	int rst = sol.findTargetSumWays(nums, target);

	return 0;
}

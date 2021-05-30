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
*/

#include <iostream>  
#include <vector>
#include <set>

using namespace std;
class Solution {
private:
	set<vector<char>> visitedOperators;

	int summationData(char operatorChar, int ref, int trg){
		int rst = 0;

		if(operatorChar == '+')
			rst = ref + trg;
		else if(operatorChar == '-')
			rst = ref - trg;

		return rst;
	}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // nums의 size만큼 vector<char> 생성 ex) + + +
		// set<vector<char>> 생성해서 방문여부를 확인
		// 없다면 추가하고 연산해서 target이라면 결과값에 플러스
		// 아니라면 vector<char>의 값을 바꿈
		int rst = 0;

		vector<char> operators;
		for(int i = 0; i < nums.size(); i++){
			operators.push_back('+');
		}

		//.... time and resource?

		return rst;
    }
};

int main() {

    return 0;
}

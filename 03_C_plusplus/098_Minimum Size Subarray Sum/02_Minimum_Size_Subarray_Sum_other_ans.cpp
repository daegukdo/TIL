/* 
@ LeetCode
Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s,
find the minimal length of a contiguous subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.
Example: 
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: 
the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
ref : https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1299/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		// vct 사이즈 및 0에 대한 예외 처리
		int n = nums.size();
		if (n == 0) return 0;

		// 정답 변수 선언 및 accumulate sum 변수 선언
		int ans = INT_MAX;
		vector<int> sums(n + 1, 0);

		// accumulation 변수 값 저장
		// 예 : nums가 [2,3,1,2,4,3]라면 sums는 [0,2,5,6,8,12,15]
		// 예 : nums가 [1,4,4]라면 sums는 [0,1,5,9]
		for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];

		for (int i = 1; i <= n; i++) {
			// 처음은 s값만을 사용하여 찾기 ... 이후 sums의 값도 합쳐서 찾기
			// 예 : nums가 [2,3,1,2,4,3]이고 sums는 [0,2,5,6,8,12,15]이고 s가 7이라면
			// ... 전체에서 찾기 시(s = 7), 4번째인 8에서 멈추고 0을 빼므로 4개의 값을 합치면 커짐
			// ... 첫번째를 빼고 찾기 시(s = 9; 첫번째를 포함), 5번째인 12에서 멈추고 1을 빼므로 4개의 값을 합치면 커짐
			// ... 첫번째와 두번째를 빼고 찾기 시(s = 12; 첫번째와 두번째를 포함), 5번째인 12에서 멈추고 2을 빼므로 3개의 값을 합치면 커짐
			// ... 첫번째와 두번째와 세번째를 빼고 찾기 시(s = 13; 첫번째와 두번째와 세번째를 포함), 6번째인 15에서 멈추고 3을 빼므로 3개의 값을 합치면 커짐
			// ... 1~4를 빼고 찾기 시(s = 15; 1~4를 포함), 6번째인 15에서 멈추고 4을 빼므로 2개의 값을 합치면 커짐
			// ... 1~5를 빼고 찾기 시(s = 19; 1~5를 포함), 큰 값이 없으므로 end
			// ... ...
			int to_find = s + sums[i - 1];
			auto bound = lower_bound(sums.begin(), sums.end(), to_find);

			// end가 아니면 기존의 ans와 비교하여 작은 값을 저장 
			if (bound != sums.end()) {
				ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
			}
		}

		// ans가 변경되지 않았다면 0을 반환하고, 아니면 ans를 반환
		return (ans != INT_MAX) ? ans : 0;
    }
};

int main() {
	int numsArr[6] = {2,3,1,2,4,3};
	vector<int> nums(numsArr, *(&numsArr + 1));

	int s = 7;

	Solution sol;

	int r = sol.minSubArrayLen(s, nums);

	return 0;
}

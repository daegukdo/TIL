/* 
@ LeetCode
Two Sum II - Input array is sorted

Given an array of integers that is already sorted in ascending order,
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]

Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]

Constraints:

2 <= nums.length <= 3 * 104
-1000 <= nums[i] <= 1000
nums is sorted in increasing order.
-1000 <= target <= 1000

https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1183/

solution of other people 
ref : https://velog.io/@madpotato1713/Leet-Code-167.-Two-Sum-II-Input-array-is-sortedC
*/

#include <iostream>
#include <vector>

using namespace std;

/*
array 안의 두 숫자의 합이 target이 되는 두 인덱스를 리턴하는 문제이다.
2중 for문으로 풀라고 낸 문제는 아닌게 분명하고(혹시 제출해 봤지만 역시나 time limit exceeded 였다.), O(n) 시간 안에 풀 수 있을 것이라는 느낌이 왔다.
이에 필자는 array의 왼쪽, 오른쪽 끝에서의 합(sum)이 target보다 작으면 왼쪽 index를 하나 더해주고, 반대면 오른쪽 index를 하나 빼주면서 sum == target이 될 때 return하는 로직을 코드로 구현했다.
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> res;
		int left = 0, right = numbers.size() - 1;

		while (left < right) {
			int sum = numbers[left] + numbers[right];
			if (sum == target) {
				res.push_back(left + 1);
				res.push_back(right + 1);
				return res;
			}
			else if (sum < target) {
				left++;
			}
			else {
				right--;
			}
		}

		return res;
	}
};

int main() {
  int a[5] = {2, 7, 11, 15};
  vector<int> v(a, *(&a + 1));

  int i = 9;

	Solution s;

	vector<int> r = s.twoSum(v, i);

  for(int i = 0; i < r.size(); i++){
    cout << r[i] << endl;
  }

	return 0;
}

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
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // target - numbers[i]는 tmp이다
        // 이 tmp가 numbers[i]를 제외한 다른 값과 같은게 있다면 그 index를 반환
        // 비교하다가 tmp보다 큰 값이 나오면 멈춤
        // 그리고 target - numbers[i+1]을 tmp로 두고 반복~ 
        vector<int> result;
        
        int tmp = 0;
        
        for(int i = 0; i < numbers.size(); i++){
          tmp = target - numbers[i];
          
        }
        
        return result;
    }
};

int main() {
  int a[5] = {2, 7, 11, 15};
  vector<int> v(a, *(&a + 1));

  int i = 9;

	Solution s;

	vector<int> r = s.twoSum(v, i);

	return 0;
}

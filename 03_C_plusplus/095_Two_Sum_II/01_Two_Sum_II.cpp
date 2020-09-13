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

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
		
    int leftIndex = 0;
    int rightIndex = numbers.size() - 1;

    while(true){
      int tmpInt = numbers[leftIndex] + numbers[rightIndex];
      if(tmpInt == target){
        result.push_back(leftIndex  + 1);
        result.push_back(rightIndex + 1);
        break;
      }
      else if(tmpInt > target){ rightIndex--; }
      else if(tmpInt < target){  leftIndex++; }
    }

    return result;
  }
};

int main() {
  int a[4] = {2, 7, 11, 15};
  vector<int> v(a, *(&a + 1));

  int i = 9;

  Solution s;

  vector<int> r = s.twoSum(v, i);

  for(int i = 0; i < r.size(); i++){
    cout << r[i] << endl;
  }
	
  return 0;
}

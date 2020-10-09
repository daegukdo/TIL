/* 
@ LeetCode
Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.
Follow up:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space? 
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:
1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0
ref : https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1182/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = nums.size();
        if(numsSize <= k){
            do
                k -= numsSize;
            while( numsSize <= k );
        }
        if(numsSize == 0 || k == 0) { return; }
        
        vector<int> tmpVct; //(numsSize + 1, 0);
        
        for(int i = numsSize - k; i < numsSize; i++){
            tmpVct.push_back(nums[i]);
        }
        
        for(int i = 0; i < numsSize - k; i++){
            tmpVct.push_back(nums[i]);
        }
        
        copy(tmpVct.begin(), tmpVct.end(), nums.begin());
    }
};

int main() {
    int numsArr[7] = {1,2,3,4,5,6,7};
    vector<int> nums(numsArr, *(&numsArr + 1));

    int k = 9;

    Solution sol;

    sol.rotate(nums, k);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }

    return 0;
}

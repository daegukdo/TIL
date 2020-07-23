/* 
@ LeetCode

Largest Number At Least Twice of Others

In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 

Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 

Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
	{
		// 1) 예외 처리? ... 요소가 1개인 경우
		// 2) 가장 큰 수 찾기
		// 3) 두번째로 큰 수 찾기
		// 4) 1은 2의 2배 이상인가?
		// 5) 맞다면 인덱스 틀리면 -1

		if(nums.size() == 1)
		{
			return 0;
		}

		vector<int> tmpVct(nums.size() ,0);
		tmpVct.assign(nums.begin(), nums.end());

		int max1stElementIndex = max_element(tmpVct.begin(), tmpVct.end()) - tmpVct.begin();
		int max1stElement = *max_element(tmpVct.begin(), tmpVct.end());

		tmpVct.erase(tmpVct.begin() + max1stElementIndex);

		int max2stElementIndex = max_element(tmpVct.begin(), tmpVct.end()) - tmpVct.begin();
		int max2stElement = *max_element(tmpVct.begin(), tmpVct.end());

		if(max1stElement >= max2stElement * 2)
		{
			return max1stElementIndex;
		}

        return -1;
    }
};

int main() 
{
	int a[1] = {1};
    vector<int> v(a, *(&a + 1));

	Solution s;

	int r0 = s.dominantIndex(v);

	return 0;
}

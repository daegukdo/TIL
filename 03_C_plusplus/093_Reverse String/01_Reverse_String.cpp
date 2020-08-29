/* 
@ LeetCode
Reverse String

Write a function that reverses a string. 

The input string is given as an array of characters char[].

Do not allocate extra space for another array,
 you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Hide Hint #1  
The entire logic for reversing a string is based on using the opposite directional two-pointer approach!

https://leetcode.com/explore/learn/card/array-and-string/205/array-two-pointer-technique/1183/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

int main() {
  char a[5] = {'h', 'e', 'l', 'l', 'o'};
  vector<char> v(a, *(&a + 1));

	Solution s;

	s.reverseString(v);

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }

	return 0;
}

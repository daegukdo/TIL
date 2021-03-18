/*
@ LeetCode
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

ref : https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1228/
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode rst = ListNode(0);
		ListNode* rstIter = &rst;
		ListNode* l1Iter = l1;
		ListNode* l2Iter = l2;
		
		int tmpInt = 0;



		return rst.next;
    }
};

int main() {
	ListNode* ln1 = new ListNode(1);
	ln1->next = new ListNode(2);
	ln1->next->next = new ListNode(4);
	
	ListNode* ln2 = new ListNode(1);
	ln2->next = new ListNode(3);
	ln2->next->next = new ListNode(4);

	Solution sol;

	ListNode* lnRst = sol.addTwoNumbers(ln1, ln2);

	return 0;
}

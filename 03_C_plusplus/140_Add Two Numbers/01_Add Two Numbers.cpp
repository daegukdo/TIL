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
		bool isUp = false;

		while (l1Iter && l2Iter){
			if(isUp){
				tmpInt = l1Iter->val + l2Iter->val + 1;
				isUp = false;
			}
			else{
			    tmpInt = l1Iter->val + l2Iter->val;
			}

			if(tmpInt < 10){
				rstIter->next = new ListNode(tmpInt);
				rstIter = rstIter->next;
			}
			else{
				rstIter->next = new ListNode(tmpInt - 10);
				rstIter = rstIter->next;
				isUp = true;
			}

			l1Iter = l1Iter->next;
			l2Iter = l2Iter->next;
		}

		if(rstIter->next == NULL){
			if(l1Iter && !l2Iter){
				rstIter->next = l1Iter;
			}
			else if(!l1Iter && l2Iter){
				rstIter->next = l2Iter;
			}
		}
		else{
			if(l1Iter && !l2Iter){
				while (l1Iter){
					if(isUp){
						rstIter->next = new ListNode(l1Iter->val + 1);
						isUp = false;
					}
					else{
					    rstIter->next = l1Iter;
					}
				    rstIter = rstIter->next;
				    l1Iter = l1Iter->next;
				}
			}
			else if(!l1Iter && l2Iter){
				while (l2Iter){
					if(isUp){
						rstIter->next = new ListNode(l2Iter->val + 1);
						isUp = false;
					}
					else{
					    rstIter->next = l2Iter;
					}
				    rstIter = rstIter->next;
				    l2Iter = l2Iter->next;
				}
			}
		}

		if(isUp){
			rstIter->next = new ListNode(1);
			isUp = false;
		}

		return rst.next;
    }
};

int main() {
	ListNode* ln1 = new ListNode(1);
	ln1->next = new ListNode(2);
	ln1->next->next = new ListNode(6);
	
	ListNode* ln2 = new ListNode(1);
	ln2->next = new ListNode(3);
	ln2->next->next = new ListNode(4);

	Solution sol;

	ListNode* lnRst = sol.addTwoNumbers(ln1, ln2);

	return 0;
}

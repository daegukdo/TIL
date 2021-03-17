/*
@ LeetCode
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]
 
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

ref : https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1227/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode rst = ListNode(0);
		ListNode* rstIter = &rst;
		ListNode* l1Iter = l1;
		ListNode* l2Iter = l2;

		while (l1Iter && l2Iter){
			if(l1Iter->val < l2Iter->val){
				rstIter->next = l1Iter;
				rstIter = rstIter->next;
				l1Iter = l1Iter->next;
			}
			else if(l1Iter->val > l2Iter->val){
				rstIter->next = l2Iter;
				rstIter = rstIter->next;
				l2Iter = l2Iter->next;
			}
			else{
				rstIter->next = l1Iter;
				rstIter = rstIter->next;
				l1Iter = l1Iter->next;

				rstIter->next = l2Iter;
				rstIter = rstIter->next;
				l2Iter = l2Iter->next;
			}
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
					rstIter->next = l1Iter;
				    rstIter = rstIter->next;
				    l1Iter = l1Iter->next;
				}
			}
			else if(!l1Iter && l2Iter){
				while (l2Iter){
					rstIter->next = l2Iter;
				    rstIter = rstIter->next;
				    l2Iter = l2Iter->next;
				}
			}
		}

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

	ListNode* lnRst = sol.mergeTwoLists(ln1, ln2);

	return 0;
}

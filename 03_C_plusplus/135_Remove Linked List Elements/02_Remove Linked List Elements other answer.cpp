/* 
@ LeetCode
Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

ref : https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/
ref : https://medium.com/@jimdaosui/remove-linked-list-elements-6ec6b7560327
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(0);
		ListNode* it = &dummy;

		while (head) {
			if (head->val == val) {
				ListNode* toDel = head;
				head = head->next;
				delete toDel;
			} else {
				it->next = head;
				head = head->next;
				it = it->next;
			}
		}
		it->next = NULL;
    
		return dummy.next;
	}
};

int main() {
	ListNode* ln = new ListNode(1);
	ln->next = new ListNode(2);
	ln->next->next = new ListNode(3);
	ln->next->next->next = new ListNode(2);
	ln->next->next->next->next = new ListNode(5);

	Solution sol;

	ListNode* lnRst = sol.removeElements(ln, 2);

	return 0;
}

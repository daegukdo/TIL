/* 
@ LeetCode
Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

ref : https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1209/
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
    bool isPalindrome(ListNode* head) {
		ListNode reversedListNode(0), *iter = &reversedListNode; 

		if(head == NULL){ return true; }
		ListNode* tmpHeadIter = head;
		if(head->next == NULL){ return true; }
		ListNode* tmpNextIter = head->next;

		while(true){
			if(tmpNextIter->next == NULL){ break; }
			ListNode* tmp = tmpNextIter->next;
			tmpNextIter->next = tmpHeadIter;
			tmpHeadIter->next = tmp;
			tmpHeadIter = 
		}

		if(reversedListNode.next == NULL){ return false; }

        return true;
    }
};

int main() {
	ListNode* ln = new ListNode(1);
	ln->next = new ListNode(2);
	ln->next->next = new ListNode(3);
	ln->next->next->next = new ListNode(4);
	ln->next->next->next->next = new ListNode(5);

	Solution sol;

	bool lnRst = sol.isPalindrome(ln);

	return 0;
}

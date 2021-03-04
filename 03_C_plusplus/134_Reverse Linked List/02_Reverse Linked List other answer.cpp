/* 
@ LeetCode
Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:
Input: head = [1,2]
Output: [2,1]
Example 3:
Input: head = []
Output: []
Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
ref : https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1205/
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
    ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* curr = head;
		while(curr != NULL){
		    ListNode* tmpNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmpNext;
		}

        return prev;
    }
};

int main() {
	// 1  2  3 4 5
	// 2 1  3  4 5
	// 3 2 1  4  5
	// 4 3 2 1  5
	ListNode* ln = new ListNode(1);
	ln->next = new ListNode(2);
	ln->next->next = new ListNode(3);
	ln->next->next->next = new ListNode(4);
	ln->next->next->next->next = new ListNode(5);

	Solution sol;

	ListNode* lnRst = sol.reverseList(ln);

	return 0;
}

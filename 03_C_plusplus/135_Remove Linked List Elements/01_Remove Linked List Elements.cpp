/* 
@ LeetCode
Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

ref : https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/
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
		if(head == NULL){
			return head;
		}

		ListNode* pre_Ln = NULL;
		ListNode* trg_Ln = head;
		ListNode* postLn = NULL;

		if(head->next != NULL){
			postLn = head->next;
		}

		while(true){
			if(trg_Ln->val == val){
				if(pre_Ln != NULL){
					// no first
					trg_Ln = NULL;
					pre_Ln->next = postLn;
					if(pre_Ln->next != NULL){ trg_Ln = pre_Ln->next; }
					else{ break; }
					if(trg_Ln->next != NULL){ postLn = trg_Ln->next; }
					else{ break; }
				}
				else{
					// do first
					head = postLn;
					trg_Ln = head;
					if(head->next != NULL){ postLn = head->next; }
					else{ break; }
				}
			}
			else{
				pre_Ln = trg_Ln;
				if(pre_Ln->next != NULL){ trg_Ln = pre_Ln->next; }
				else{ break; }
				if(trg_Ln->next != NULL){ postLn = trg_Ln->next; }
				else{ postLn = NULL; }
			}
		}

		return head;
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

	ListNode* lnRst = sol.removeElements(ln, 5);

	return 0;
}

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
		ListNode* trgLn = head;
		ListNode* preLn = NULL;
		ListNode* pstLn = NULL;
		while(true){
			if(trgLn->val == val){
				if(preLn == NULL){
					// do first
					pstLn = trgLn->next;
					trgLn = NULL;
					trgLn = pstLn;
				}
				else{
					// no first
					
				}
				preLn = pstLn;
			}
		}
    }
};

int main() {

	return 0;
}

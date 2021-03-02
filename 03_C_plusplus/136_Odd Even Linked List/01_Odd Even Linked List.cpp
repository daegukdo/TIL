/* 
@ LeetCode
Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 
Constraints:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].

ref : https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1208/
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
    ListNode* oddEvenList(ListNode* head) {
		ListNode odd_LN(0), *odd_Iter = &odd_LN;
		ListNode evenLN(0), *evenIter = &evenLN;
		int count = 1;

		ListNode* iter = head;

		if(iter == NULL){ 
			return head;
		}

		while(true){
			if(count % 2 == 1){
				// odd
				odd_Iter->next = iter;
				odd_Iter = odd_Iter->next;
			}
			else{
				// even
				evenIter->next = iter;
				evenIter = evenIter->next;
			}

			count++;

			if(iter->next != NULL){
				iter = iter->next;
			}
			else{
				break;
			}
		}

		if(evenLN.next != NULL){
		    odd_Iter->next = evenLN.next;
			evenIter->next = NULL;
		}

		return odd_LN.next;
    }
};

int main() {
	ListNode* ln = new ListNode(1);
	ln->next = new ListNode(2);
	ln->next->next = new ListNode(3);
	ln->next->next->next = new ListNode(4);
	ln->next->next->next->next = new ListNode(5);

	Solution sol;

	ListNode* lnRst = sol.oddEvenList(ln);

	return 0;
}

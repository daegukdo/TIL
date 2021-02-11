/* 
@ LeetCode
Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 

Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 
Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 
Follow up: Can you solve it using O(1) (i.e. constant) memory?

ref : https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1212/
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		// head가 NULL이면 cycle이 없으므로 false
        if(head == NULL){
			return false;
		}

		// define slow and fast
		ListNode *slow = head;
		ListNode *fast = head->next;

		// slow와 fast는 다르므로
		while(slow != fast){
			// NULL이 있다면 cycle이 없으므로 false
			if(fast == NULL || fast->next == NULL){
				return false;
			}

			// slow는 다음의 링크로 이동(move 1 step), fast는 다음의 다음 링크로 이동(move 2 step)
			slow = slow->next;
			fast = fast->next->next;
		}

		return true;
    }
};

int main() {
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	head->next->next->next->next = head->next;

	ListNode* _head = new ListNode(1);

	// TO DO : 1 1 1의 상황?

	Solution sol;

	bool rst = sol.hasCycle(_head);

	return 0;
}

/* 
@ LeetCode
Linked List Cycle II

Given a linked list, return the node where the cycle begins. 

If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 

Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 

Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 
Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 
Follow up: Can you solve it using O(1) (i.e. constant) memory?

ref : https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // head가 null인지 확인
		// first와 second를 생성
		// while로 반복해 가며 비교
		// cycle을 가지는지 확인
		// 가진다면 지금 위치에서 하나씩 map에 넣음
		// head의 처음부터 반복하며 map에 있는지 확인
		// 처음 있는 것이 나오면 그 LiastNode를 반환
		if(head == NULL){
			return NULL;
		}

		ListNode *fst = head;
		ListNode *snd = head->next;

		if(fst == snd){
			return head;
		}

		while(fst != snd){
			if(fst->next != NULL){
			    fst = fst->next;
			}
			else{
			    return NULL;
			}
			if(snd->next != NULL && snd->next->next != NULL){
			    snd = snd->next->next;
			}
			else{
			    return NULL;
			}

			if(fst == snd){
				break;
			}
		}

		unordered_map<ListNode*, int> map;
		while(true){
			auto elm = map.find(fst);
			if(elm != map.end()){
				break;
			}
			else{
				map.insert(make_pair(fst, 1));
			}
			fst = fst->next;
		}

		ListNode* iterNext = head;
		while(true){
			auto elm = map.find(iterNext);
			if(elm != map.end()){
				return iterNext;
			}
			iterNext = iterNext->next;
		}
    }
};

int main() {
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	head->next->next->next->next = head->next;
	
	Solution sol;

	ListNode* rst = sol.detectCycle(head);

	return 0;
}

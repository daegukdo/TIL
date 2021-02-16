/* 
@ LeetCode
Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Hide Hint #1  
Maintain two pointers and update one with a delay of n steps.

ref : https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1296/
*/

#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* vector 정의 
		// NULL이 나올 때까지 vector에 넣어가며 next를 찾기
		// NULL이 나타나면 멈춤
		// vector 개수 - n을 통해 from start로 변경 ... s
		// s-1의 next는 s+1
		vector<ListNode*> vctLN;
		ListNode* tmpLN = head;
		while(tmpLN != NULL){
			vctLN.push_back(tmpLN);
			tmpLN = tmpLN->next;
		}
		int vctCount = vctLN.size();
		if(vctCount > n){
			ListNode* preLN = vctLN[vctCount-n-1];
			ListNode* postLN = vctLN[vctCount-n+1];
			preLN->next = postLN;
			return head;
		}
		else{
			return NULL;
		}
    }
};

int main() {

	return 0;
}

/*
@ LeetCode
Rotate List

Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

ref : https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1295/
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
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || k == 0){
			return head;
		}

        ListNode* iter = head;
		int n = 0; // lenOfLn 
		int d = k; // decouplingIdx

		// cal. len. of ln and make ln to cycle
		while (iter){
			n++;
			if(iter->next == NULL) { 
				iter->next = head; 
				break;	
			}
			else{
			    iter = iter->next;
			}
		}

		// cal. decoupling idx
		while (true){
			if(d < n){
				d = n - d;
				break;
			}
			else{
			    d = d - n;
			}
		}

		// decouple ln and set head of ln
		for(int i = 0; i < d; i++){
			iter = iter->next;
		}
		head = iter->next;
		iter->next = NULL;

		return head;
    }
};

int main() {
	ListNode* n1 = new ListNode(1);
	n1->next = new ListNode(2);
	n1->next->next = new ListNode(3);
	int k = 2;

	Solution sol;

	ListNode* lnRst = sol.rotateRight(n1, k);

	return 0;
}

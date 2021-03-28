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
        ListNode* iter = head;
		int n = 0; // lenOfLn (by idx)
		int d = k - 1; // decouplingIdx

		while (iter){
			if(iter->next == NULL) { 
				iter->next = head; break;	
			}
			else{
			    iter = iter->next;
			    n++;
			}
		}

		while (true){
			d = d - n;
			if(d < n){
				break;
			}
		}

		iter = head;
		for(int i = 0; i <= d; i++){
			iter = iter->next;
		}
		head = iter->next;
		iter->next = NULL;

		return head;
    }
};

int main() {
	ListNode* n1 = new ListNode();
	int k = 0;

	Solution sol;

	ListNode* lnRst = sol.rotateRight(n1, k);

	return 0;
}

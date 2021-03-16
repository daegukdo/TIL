/*
@ LeetCode
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]
 
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.

ref : https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1227/
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* rst = NULL;
        vector<int> vctInt;



		return rst;
    }
};

int main() {
	ListNode* ln1 = new ListNode(1);
	ln1->next = new ListNode(2);
	ln1->next->next = new ListNode(4);
	
	ListNode* ln2 = new ListNode(1);
	ln2->next = new ListNode(3);
	ln2->next->next = new ListNode(4);

	Solution sol;

	ListNode* lnRst = sol.mergeTwoLists(ln1, ln2);

	return 0;
}

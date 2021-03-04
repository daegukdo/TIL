/* 
@ LeetCode
Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
 
Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 
Follow up: Could you do it in O(n) time and O(1) space?

ref : https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1209/
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
    bool isPalindrome(ListNode* head) {
		vector<int> vctInt;

		ListNode* iter = head;
		while(iter != NULL){
			vctInt.push_back(iter->val);
			iter = iter->next;
		}

		vector<int> vctIntRvs = vctInt;
		reverse(vctIntRvs.begin(), vctIntRvs.end());  

		if(vctIntRvs == vctInt){
			return true;
		}
		else{
			return false;
		}
    }
};

int main() {
	ListNode* ln = new ListNode(1);
	ln->next = new ListNode(2);
	ln->next->next = new ListNode(3);
	ln->next->next->next = new ListNode(4);
	ln->next->next->next->next = new ListNode(5);

	Solution sol;

	bool lnRst = sol.isPalindrome(ln);

	return 0;
}

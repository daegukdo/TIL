/*
@ LeetCode
Flatten a Multilevel Doubly Linked List

You are given a doubly linked list which in addition to the next and previous pointers,
 it could have a child pointer,
 which may or may not point to a separate doubly linked list. 
  
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. 

You are given the head of the first level of the list.


Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

Explanation:
The multilevel linked list in the input is as follows:
(figure)

After flattening the multilevel linked list it becomes:
(figure)

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]

Explanation:
The input multilevel linked list is as follows:
  1---2---NULL
  |
  3---NULL

Example 3:
Input: head = []
Output: []
 
How multilevel linked list is represented in test case:

We use the multilevel linked list from Example 1 above:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

The serialization of each level is as follows:
[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]

To serialize all levels together we will add nulls in each level to signify no node connects to the upper node of the previous level.

The serialization becomes:
[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]

Merging the serialization of each level and removing trailing nulls we obtain:
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 
Constraints:
The number of Nodes will not exceed 1000.
1 <= Node.val <= 105

ref : https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1225/
*/

#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
	Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
	Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
		Node rst = Node();
		Node* rstIter = &rst;
		Node* iter = head;

		while (iter){
			Node* tmp = new Node(); tmp->val = iter->val;
			if(!(rstIter->next == NULL) && !(rstIter->prev == NULL)){
				rstIter->next = tmp;
			}
			else{
				if(iter->child == NULL){
					tmp->prev = rstIter;
					rstIter->next = tmp;
				}
				else{
					tmp->prev = rstIter;
					rstIter->next = tmp;
				}
			}

			rstIter = rstIter->next;
			if(iter->child != NULL){
				Node* tmpChild = flatten(iter->child);
				tmpChild->prev = rstIter;
				rstIter->next = tmpChild;
				while (rstIter->next != NULL){
					rstIter = rstIter->next;
				}
			}
			iter = iter->next;
		}

		if(rst.next != NULL){ rst.next->prev = NULL; }
		return rst.next;
    }
};

int main() {
	Node* n1 = new Node(1);
	n1->next = new Node(2); n1->next->prev = n1;
	n1->next->next = new Node(3); n1->next->next->prev = n1->next; n1->next->next->child = new Node(1);
	n1->next->next->next = new Node(4); n1->next->next->next->prev = n1->next->next;

	Solution sol;

	Node* lnRst = sol.flatten(n1);

	return 0;
}

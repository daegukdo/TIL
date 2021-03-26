/*
@ LeetCode
Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. 
The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
Both the next and random pointer of the new nodes should point to new nodes in the copied list 
 such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y,
 then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. 
Each node is represented as a pair of [val, random_index] where:
 val: an integer representing Node.val
 random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Example 4:
Input: head = []
Output: []

Explanation: The given linked list is empty (null pointer), so return null.
 
Constraints:
0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.

Hint #1  
Just iterate the linked list and create copies of the nodes on the go. 
Since a node can be referenced from multiple nodes due to the random pointers, make sure you are not making multiple copies of the same node.

Hint #2  
You may want to use extra space to keep old node ---> new node mapping to prevent creating multiples copies of same node.

Hint #3  
We can avoid using extra space for old node ---> new node mapping, by tweaking the original linked list. 
Simply interweave the nodes of the old and copied list. For e.g.
Old List: A --> B --> C --> D
InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'

Hint #4  
The interweaving is done using next pointers and we can make use of interweaved structure to get the correct reference nodes for random pointers.

ref : https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1229/
*/

#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
		Node rst = Node(0);
        Node* rstIter = &rst;
		Node* iter = head;

		// deep copy?
		while(iter){
			rstIter = new Node(iter->val);
			rstIter = rstIter->next;
			iter = iter->next;

			// how do you check iter's random 'Node'?
		}

		return rst.next;
    }
};

int main() {
	Node* n1 = new Node(0);

	Solution sol;

	Node* lnRst = sol.copyRandomList(n1);

	return 0;
}

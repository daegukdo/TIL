/*
@ LeetCode
Design Linked List

Solution
Design your implementation of the linked list. You can choose to use a singly or
doubly linked list. A node in a singly linked list should have two attributes:
val and next. val is the value of the current node, and next is a
pointer/reference to the next node. If you want to use the doubly linked list,
you will need one more attribute prev to indicate the previous node in the
linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:
MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the
index is invalid, return -1. void addAtHead(int val) Add a node of value val
before the first element of the linked list. After the insertion, the new node
will be the first node of the linked list. void addAtTail(int val) Append a node
of value val as the last element of the linked list. void addAtIndex(int index,
int val) Add a node of value val before the indexth node in the linked list. If
index equals the length of the linked list, the node will be appended to the end
of the linked list. If index is greater than the length, the node will not be
inserted. void deleteAtIndex(int index) Delete the indexth node in the linked
list, if the index is valid.

Example 1:
Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex",
"get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3

Constraints:
0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and
deleteAtIndex.

ref :
https://leetcode.com/explore/learn/card/linked-list/210/doubly-linked-list/1294/
*/

#include <iostream>

using namespace std;

class MyLinkedList {
private:
    struct DoublyListNode {
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
    };
    DoublyListNode* doublyListNode = NULL;

public:
	/** Initialize your data structure here. */
	MyLinkedList() {
	}

	/** Get the value of the index-th node in the linked list. If the index is
	 * invalid, return -1. */
	int get(int index) {
	    return 0;
	}

	/** Add a node of value val before the first element of the linked list.
	 * After the insertion, the new node will be the first node of the linked
	 * list. */
	void addAtHead(int val) {
	    if(doublyListNode == NULL){
	        doublyListNode = new DoublyListNode(val);
	    }
	    else{
	        DoublyListNode* tmpDLN = new DoublyListNode(val);
	        doublyListNode->prev = tmpDLN;
	        tmpDLN->next = doublyListNode;
	        doublyListNode = tmpDLN;
	    }
	    cout << doublyListNode->val << endl;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
	    DoublyListNode* tmpDLN = doublyListNode;
	    while(true){
	        DoublyListNode* tmpPrevDLN = tmpDLN->prev;
	        if(tmpDLN == NULL){
	            tmpDLN = new DoublyListNode(val);
	            if(tmpDLN != NULL){
	                tmpPrevDLN->next = tmpDLN;
	                tmpDLN->prev = tmpPrevDLN;
	            }
	            break;
	        }
	        else{
	            tmpDLN = tmpDLN->next;
	        }
	    }
	    cout << tmpDLN->val << endl;
	    cout << tmpDLN->prev->val << endl;
	}

	/** Add a node of value val before the index-th node in the linked list. If
	 * index equals to the length of linked list, the node will be appended to
	 * the end of linked list. If index is greater than the length, the node
	 * will not be inserted. */
	void addAtIndex(int index, int val) {
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
	}
};

int main() {
	MyLinkedList* myLinkedList = new MyLinkedList();
	myLinkedList->addAtHead(1);
	myLinkedList->addAtTail(3);
	myLinkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
	int r1 = myLinkedList->get(1);   // return 2
	myLinkedList->deleteAtIndex(1);  // now the linked list is 1->3
	int r2 = myLinkedList->get(1);	 // return 3

	return 0;
}

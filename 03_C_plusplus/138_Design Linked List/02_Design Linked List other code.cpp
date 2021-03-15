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

ref : https://leetcode.com/explore/learn/card/linked-list/210/doubly-linked-list/1294/
ref : https://www.programmersought.com/article/4529371304/
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

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
       LinkedList = 0;
    } 
    ListNode *LinkedList;

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
		ListNode *head = LinkedList;
		while (head&&i<index) {
			head = head->next;
			i++;
		}
		if (head&&i == index) 
            return head->val;
		else return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *newnode = new ListNode(val);
        newnode->next = LinkedList;
        LinkedList = newnode;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *newnode = new ListNode(val);
        newnode->next = NULL;
        ListNode *head = LinkedList;
        if (!head) {
			LinkedList = newnode;
			return;
		}
		while (head&&head->next) {
			head = head->next;
		}
		head->next = newnode;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int i = 0;
		ListNode *head = LinkedList;
		if (!head&&index == 0) {
			ListNode *newnode = new ListNode(val);
			newnode->next = 0;
			LinkedList = newnode;
			return;
		}
		while (head&&i < index - 1) {
			head = head->next;
			i++;
		}
		if (head&&head->next == 0) {
			ListNode *newnode = new ListNode(val);
			newnode->next = 0;
			head->next = newnode;
		}
		else if (i == index - 1 && head&&head->next) {
			ListNode *newnode = new ListNode(val);
			newnode->next = head->next;
			head->next = newnode;
		}
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
     ListNode *head = LinkedList;
		int i = 0;
		while (head&&i < index - 1) {
			head = head->next;
			i++;
		}
		if (head == 0) return;
		if (head->next == 0 && index == 0) { // Only one node situation
			LinkedList = 0;
			return;
		}
		if (head->next) {
			ListNode *tmp = head->next;
			head->next = tmp->next;
			free(tmp);
		}
	}
};

int main() {
	
	MyLinkedList* myLinkedList = new MyLinkedList();

	myLinkedList->addAtHead(4);
	int r1 = myLinkedList->get(1);
	myLinkedList->addAtHead(1);
	myLinkedList->addAtHead(5);
	myLinkedList->deleteAtIndex(3);
	myLinkedList->addAtHead(7);
	int r2 = myLinkedList->get(0);
	int r3 = myLinkedList->get(3);
	int r4 = myLinkedList->get(3);
	myLinkedList->addAtHead(1);
	myLinkedList->deleteAtIndex(4);

	/*
	MyLinkedList* myLinkedList = new MyLinkedList();
	myLinkedList->addAtHead(1);
	myLinkedList->addAtTail(3);
	myLinkedList->addAtIndex(1, 2); 
	int r1 = myLinkedList->get(1);
	myLinkedList->deleteAtIndex(0);
	int r2 = myLinkedList->get(0);
	*/

	return 0;
}

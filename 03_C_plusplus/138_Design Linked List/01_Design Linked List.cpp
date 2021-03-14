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
    DoublyListNode* doublyListNode;

public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		doublyListNode = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is
	 * invalid, return -1. */
	int get(int index) {
	    int countIdx = 0;
		DoublyListNode* tmpDLN = doublyListNode;

		if(tmpDLN == NULL){
			return -1;
		}

		while(true){
			if(countIdx == index){
				break;
			}
			else{
				if(tmpDLN->next != NULL){
					tmpDLN = tmpDLN->next;
					countIdx++;
				}
				else{
					return -1;
				}
			}
		}

		return tmpDLN->val;
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
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if(doublyListNode == NULL){
	        doublyListNode = new DoublyListNode(val);
	    }
		else{
			DoublyListNode* tmpDLN = doublyListNode;
			DoublyListNode* tmpPrv = tmpDLN;
			while(true){
				if(tmpDLN->next == NULL){
					tmpDLN->next = new DoublyListNode(val);
					tmpDLN->next->prev = tmpPrv;
					break;
				}
				else{
					tmpPrv = tmpDLN;
					tmpDLN = tmpDLN->next;
				}
			}
		}
	}

	/** Add a node of value val before the index-th node in the linked list. If
	 * index equals to the length of linked list, the node will be appended to
	 * the end of linked list. If index is greater than the length, the node
	 * will not be inserted. */
	void addAtIndex(int index, int val) {
		if(doublyListNode == NULL){
			if(index == 0){
	            doublyListNode = new DoublyListNode(val);
			}
			else{
				return;
			}
	    }
		else{
			if(index == 0){
				DoublyListNode* tmpPrv = new DoublyListNode(val);
				DoublyListNode* tmpDLN = doublyListNode;
				tmpDLN->prev = tmpPrv;
				tmpPrv->next = tmpDLN;
				doublyListNode = tmpPrv;
			}
			else{
				int countIdx = 0;
				DoublyListNode* tmpDLN = doublyListNode;
				DoublyListNode* tmpPrv = tmpDLN;
				while(true){
					if(countIdx == index){
						if(tmpDLN != NULL){
							DoublyListNode* tmpBtw = new DoublyListNode(val);
							tmpBtw->next = tmpDLN;
							tmpDLN->prev = tmpBtw;
							tmpBtw->prev = tmpPrv;
							tmpPrv->next = tmpBtw;
							break;
						}
						else{
							DoublyListNode* tmpBtw = new DoublyListNode(val);
							tmpBtw->prev = tmpPrv;
							tmpPrv->next = tmpBtw;
							break;
						}
					}
					else{
						tmpPrv = tmpDLN;
						tmpDLN = tmpDLN->next;
					}
					countIdx++;
				}
			}
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if(doublyListNode == NULL){
			return;
	    }
		else{
			if(index == 0){
				if(doublyListNode->next != NULL){
					DoublyListNode* tmpDLN = doublyListNode->next;
					tmpDLN->prev = NULL;
					doublyListNode = tmpDLN;
				}
				else{
					doublyListNode = NULL;
				}
			}
			else{
				int countIdx = 0;
				DoublyListNode* tmpDLN = doublyListNode;
				DoublyListNode* tmpPrv = tmpDLN;
				while(true){
					if(countIdx == index){
						if(tmpDLN->next != NULL){
							tmpDLN->next->prev = tmpPrv;
							tmpPrv->next = tmpDLN->next;
							break;
						}
						else{
							tmpDLN->prev->next = NULL;
							break;
						}
					}
					else{
						if(tmpDLN->next != NULL){
							tmpPrv = tmpDLN;
							tmpDLN = tmpDLN->next;
						}
						else{
							break;
						}
					}
					countIdx++;
				}
			}
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
	int r2 = myLinkedList->get(3);
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

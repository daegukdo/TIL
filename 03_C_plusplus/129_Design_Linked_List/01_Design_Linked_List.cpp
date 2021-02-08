/*
@ LeetCode

Design Linked List

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next.
val is the value of the current node, and next is a pointer/reference to the next node.

If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list.
Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:
MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

Example 1:
Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
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
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.

ref : https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/
*/

#include <iostream>

using namespace std;

class MyLinkedList {
public:
    struct SinglyListNode {
        int val;
        SinglyListNode* next;
        SinglyListNode(int x) : val(x), next(NULL) {}
    };

    SinglyListNode* sln;
    int length;

    /** Initialize your data structure here. */
    MyLinkedList() {
        sln = NULL;
        length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if ((index > -1) & (index < length)) {
            return _returnSlnOnIndex(sln, index)->val;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* headSln = new SinglyListNode(val);
        headSln->next = sln;
        sln = headSln;
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode* tailSln = new SinglyListNode(val);
        if (sln == NULL) {
            sln = tailSln;
        }
        else {
            _returnSlnOnIndex(sln, length - 1)->next = tailSln;
        }
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > length) {
            return;
        }
        else if ((index > 0) & (index < length)) {
            SinglyListNode* postSln = _returnSlnOnIndex(sln, index);
            SinglyListNode* midSln = new SinglyListNode(val);
            midSln->next = postSln;

            _next2NullOnIdex(sln, index - 1);
            _pre2Post(sln, midSln);

            length++;
        }
        else if (index == 0) {
            addAtHead(val);
        }
        else if (index == length) {
            addAtTail(val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= length) {
            return;
        }
        else if ((index > 0) & (index < length - 1)) {
            SinglyListNode* postSln = _returnSlnOnIndex(sln, index + 1);

            _next2NullOnIdex(sln, index - 1);
            _pre2Post(sln, postSln);
        }
        else if (index == 0) {
            sln = _returnSlnOnIndex(sln, 1);
        }
        else if (index == length - 1) {
            _next2NullOnIdex(sln, length - 1);
        }
        length--;
    }
private:
    SinglyListNode* _returnSlnOnIndex(SinglyListNode* _sln, int _index) {
        if (_index > 0) {
            return _returnSlnOnIndex(_sln->next, _index - 1);
        }
        else {
            return _sln;
        }
    }

    void _next2NullOnIdex(SinglyListNode* _sln, int _index) {
        if (_index > 0) {
            _next2NullOnIdex(_sln->next, _index - 1);
        }
        else if (_index == 0) {
            _sln->next = NULL;
        }
    }

    void _pre2Post(SinglyListNode* preSln, SinglyListNode* postSln) {
        if (preSln->next != NULL) {
            _pre2Post(preSln->next, postSln);
        }
        else {
            preSln->next = postSln;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList* mll = new MyLinkedList();

    mll->addAtTail(1);

    int r0 = mll->get(0);

    return 0;
}

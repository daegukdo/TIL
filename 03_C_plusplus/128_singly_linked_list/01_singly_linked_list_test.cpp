/* 
@ LeetCode

singly-linked-list

test with struct

ref : https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1287/
ref : https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1288/
ref : https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1289/
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

int main() {
    SinglyListNode sln0 = {23};
    SinglyListNode sln1 = {6};
    SinglyListNode sln2 = {15};
    
    // cout << sln0.val << endl;

    sln0.next = &sln1;
    sln1.next = &sln2;
    
    cout << sln0.next->next->val << endl;

	return 0;
}

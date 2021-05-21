/*
@ LeetCode - DFS - Template I

As we mentioned in the chapter's description, in most cases, we can also use DFS when using BFS. 

But there is an important difference: the traversal order.

Different from BFS, the nodes you visit earlier might not be the nodes which are closer to the root node. 

As a result, the first path you found in DFS might not be the shortest path.

In this article, we will provide you a recursion template of DFS and show you how the stack helps with this process. 

And then we provide some exercise after this article for you to practice.

Template - Recursion

There are two ways to implement DFS. 

The first one is to do recursion which you might already be familiar with. 

Here we provide a template as reference:

ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1361/
*/

#include <iostream>  
#include <stack>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

bool DFS(Node* cur, Node* target, set<int> visited) {
    if(cur == target){
        return true;
    }

    if(cur->next != NULL){
        ;
    }

    return true if cur is target;

    for (next : each neighbor of cur) {
        if (next is not in visited) {
            add next to visted;
            return true if DFS(next, target, visited) == true;
        }
    }
    return false;
}

int main() {
    string s = "()[]{}";

    Solution sol;
    bool rst = sol.isValid(s);
    
    if(rst) { cout << "true!" << endl; }
    else    { cout << "false" << endl; }

    return 0;
}

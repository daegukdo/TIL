/*
@ LeetCode - Clone Graph

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). 

For example, the first node with val == 1, the second node with val == 2, and so on. 

The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. 

Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. 

You must return the copy of the given node as a reference to the cloned graph.


Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).


Example 2:
Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.


Example 3:
Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.


Example 4:
Input: adjList = [[2],[1]]
Output: [[2],[1]]


Constraints:
The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

ref : https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1392/
ref : https://leetcode.com/problems/clone-graph/discuss/1194067/Easy-C%2B%2B-solution-Clone-Graph
*/

#include <iostream>  
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#include <iostream>  
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    map<int,pair<bool,Node*>> mp;
    
    Node* cloneGraph(Node* node) {
        // if node is NULL then we return the NULL value  
        if(node==NULL)  return NULL; 
        
        if(mp.find(node->val)!=mp.end()) return mp[node->val].second ;

        // as our node is node null so we will create a new node having val=node->val 
        Node* newNode =  new Node(node->val);
       
        // we will mark this node visited by assigning true and we will store the node adress in map    
        mp[node->val] = make_pair(true, newNode);
       
        /*as each child of node can be traversed from vector (node->neighbors )  
        and will recur for each child node and store its address in our nnode 
        (new node vectore that is nnode->neighbors)*/
        
        for(auto it: node->neighbors){
            Node* ChildNode= cloneGraph(it);
            newNode->neighbors.push_back(ChildNode);
        }

        // after calling for all child return nnode pointer
        return newNode;
    }
};

int main() {
    Node* inputNode = new Node(1);
    Node* node1 = new Node(2);
    Node* node2 = new Node(3);
    Node* node3 = new Node(4);

    inputNode->neighbors.push_back(node1);
    inputNode->neighbors.push_back(node3);
    node1->neighbors.push_back(inputNode);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(inputNode);
    node3->neighbors.push_back(node2);

    Solution sol;
    Node* rst = sol.cloneGraph(inputNode);

    return 0;
}

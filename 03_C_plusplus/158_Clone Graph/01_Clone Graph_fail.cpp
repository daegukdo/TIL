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
ref : https://www.youtube.com/watch?v=S931KMpiKmQ&t=391s
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

class Solution {
private:
    int count = 0;;
    vector<int> visitedNodeValVct;
    vector<Node*> visitedNodeVct;

public:
    Node* cloneGraph(Node* node) {
        int breakRef = visitedNodeValVct.size();

        auto iter = find(visitedNodeValVct.begin(), visitedNodeValVct.end(), node->val);

        if (iter == visitedNodeValVct.end()) {
            Node* outputNode = new Node(node->val);
            visitedNodeValVct.push_back(outputNode->val);
            visitedNodeVct.push_back(outputNode);

            int inputNodeNumOfNeighbors = node->neighbors.size();
            if (inputNodeNumOfNeighbors != 0) {
                for (int i = 0; i < inputNodeNumOfNeighbors; i++) {
                    Node* tmpNode = new Node(node->neighbors[i]->val);
                    visitedNodeValVct.push_back(node->neighbors[i]->val);
                    visitedNodeVct.push_back(tmpNode);
                    tmpNode->neighbors.push_back(outputNode);
                    outputNode->neighbors.push_back(tmpNode);
                }
            }
        }
        else {
            int index = iter - visitedNodeValVct.begin();
            Node* outputNode = visitedNodeVct[index];

            int inputNodeNumOfNeighbors = node->neighbors.size();
            if (inputNodeNumOfNeighbors != 0) {
                for (int i = 0; i < inputNodeNumOfNeighbors; i++) {
                    auto tmpIter = find(visitedNodeValVct.begin(), visitedNodeValVct.end(), node->neighbors[i]->val);
                    if (tmpIter == visitedNodeValVct.end()) {
                        Node* tmpNode = new Node(node->neighbors[i]->val);
                        visitedNodeValVct.push_back(node->neighbors[i]->val);
                        visitedNodeVct.push_back(tmpNode);
                        tmpNode->neighbors.push_back(outputNode);
                        outputNode->neighbors.push_back(tmpNode);
                    }
                }
            }
        }

        count++;

        if (count == 1) {
            return cloneGraph(node->neighbors[0]);
        }

        if (breakRef != visitedNodeValVct.size()){
            int nextIdx = 0;
            int cprInt = INT_MIN;
            int inputNodeNumOfNeighbors = node->neighbors.size();
            if (inputNodeNumOfNeighbors != 0) {
                for (int i = 0; i < inputNodeNumOfNeighbors; i++) {
                    if (cprInt < node->neighbors[i]->val) {
                        cprInt = node->neighbors[i]->val;
                        nextIdx = i;
                    }
                }
            }
            return cloneGraph(node->neighbors[nextIdx]);
        }
        else {
            return visitedNodeVct[0];
        }
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

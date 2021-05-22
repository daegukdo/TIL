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

ref : https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1377/
ref : https://leetcode.com/explore/learn/card/queue-stack/230/usage-stack/1361/
ref : https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
*/

#include <iostream>  
#include <map>
#include <vector>

using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    for (auto iter = adj[v].begin(); iter != adj[v].end(); ++iter)
        if (!visited[*iter])
            DFS(*iter);
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1, 4);

    g.addEdge(2, 4);
    g.addEdge(2, 5);
    
    g.addEdge(3, 6);
 
    g.addEdge(5, 6);

    cout << "Following is Depth First Traversal : " << endl;
    g.DFS(0);
 
    return 0;
}
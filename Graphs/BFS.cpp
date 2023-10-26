/*
-------------------------------------------------------------
Graph construction using Adjacency list and BFS 
-------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using
// adjacency list representation
class Graph {
 
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    vector<vector<int>> adj;
 
public:
    // Constructor
    Graph(int V);
 
    // Function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints BFS traversal from a given source s
    void BFS(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V, false);
 
    // Create a queue for BFS
    vector<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    while (!queue.empty()) {
 
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.erase(queue.begin());
 
        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjacent : adj.at(s)) 
        {
            if (!visited.at(adjacent)) 
            {
                visited.at(adjacent) = true;
                queue.push_back(adjacent);
            }
        }
    }
}
 
// Driver code
int main()
{
     // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0);
 
    return 0;
}

/*

-----------------
 OUTPUT
-----------------
Following is Breadth First Traversal (starting from vertex 0) 
0 1 2 4 3 

 */

/*
----------------------------------------------------
C++ Implementation of Graph and Depth First Search
----------------------------------------------------
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    
           Graph(int n);
    
           void addEdge(int v, int w);
    
           void dfs(int source);
    
    private:
    
            int noOfVertices;
    
            vector<vector<int>> adjList;
};

Graph::Graph(int n)
{
    this->noOfVertices = n;
    adjList.resize(n);
}

void Graph::addEdge(int v, int w)
{
    adjList.at(v).push_back(w);
}

void Graph::dfs(int s)
{
    vector<bool> visited(noOfVertices, false);
    vector<int> stack;
    
    cout <<" DFS of the given graph :" << endl;
    stack.push_back(s);
    visited[s] = true;
    while(!stack.empty())
    {
        int top = stack.back();
        stack.pop_back();
        cout << top << "\t";
        for(auto& adjEl : adjList[top])
        {
            if(!visited[adjEl])
            {
                stack.push_back(adjEl);
                visited[adjEl] = true;
            }
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(3, 2);
    g.addEdge(4, 2);
    g.dfs(0);
    return 0;
}

/*
OUTPUT
---------------
DFS of the given graph :
0	3	2	4	1	

For finding strongly connected components in a graph,
dfs can be used in the following way:

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 3);

    // Core logic to find strongly connected components in a graph in DFS.
    int connectedComponents = 0;
    for(int i = 0; i < 6; i++)
    {
        if(!g.visited[i])
        {
            g.dfs(i);
            connectedComponents++;
        }
    }
    cout << "The number of connected components in the given graph :" << connectedComponents << endl; 
    return 0;
}

OUTPUT - The number of connected components in the given graph : 3
*/

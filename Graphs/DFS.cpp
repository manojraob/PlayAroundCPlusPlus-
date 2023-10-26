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
*/

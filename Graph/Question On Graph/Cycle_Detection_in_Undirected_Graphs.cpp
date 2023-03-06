#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

// Using BFS

// TIME COMPLEXITY : O(V+E)

// function to check if there is a cycle in a graph using BFS
bool isCyclicBFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node)
{
    // create a map to store the parent of each node
    unordered_map<int, int> parent;
    // set the parent of the starting node to -1
    parent[node] = -1;
    // mark the starting node as visited
    visited[node] = 1;
    // create a queue to store nodes to be visited
    queue<int> q;
    // add the starting node to the queue
    q.push(node);
    // loop until all nodes have been visited
    while (!q.empty())
    {
        // get the front node from the queue
        int frontNode = q.front();
        q.pop();
        // loop through all the neighbors of the front node
        for (auto neighbor : adj[frontNode])
        {
            // if the neighbor is already visited and it is not the parent of the front node, then there is a cycle
            if (visited[neighbor] == true && neighbor != parent[frontNode])
            {
                return true;
            }
            // if the neighbor is not visited, mark it as visited, set its parent to the front node, and add it to the queue
            else if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = 1;
                parent[neighbor] = frontNode;
            }
        }
    }
    // if no cycle is found, return false
    return false;
}

// function to detect cycle in an undirected graph
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create an adjacency list to represent the graph
    unordered_map<int, list<int>> adj;
    // loop through all the edges and add them to the adjacency list
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // create a map to keep track of visited nodes
    unordered_map<int, bool> visited;
    // loop through all the nodes
    for (int i = 0; i < n; i++)
    {
        // if the node has not been visited yet, check if there is a cycle starting from this node
        if (!visited[i])
        {
            bool ans = isCyclicBFS(adj, visited, i);
            // if a cycle is found, return "Yes"
            if (ans == true)
            {
                return "Yes";
            }
        }
    }
    // if no cycle is found, return "No"
    return "No";
}
// DFS
bool isCyclicDFS(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
                 int parent, int node)
{
    visited[node] = true;
    for (auto negibhours : adj[node])
    {
        if (visited[negibhours] == true && negibhours != parent)
        {
            return 1;
        }
        else if (!visited[negibhours])
        {
            bool cyclicDetected = isCyclicDFS(adj, visited, node, negibhours);
            if (cyclicDetected)
                return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cout << "Enter the number of node/vertices : " << endl;
    cin >> n;
    int m;
    cout << "Enter the number of Edges : " << endl;
    cin >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    string ans = cycleDetection(edges, n, m);
    cout << ans << endl;
    return 0;
}
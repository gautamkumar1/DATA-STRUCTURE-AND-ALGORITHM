#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdges(int u, int v, int direction)
    {
        // Direction = 0 -> Undirected Graph
        // Direction = 1 -> Directed Graph
        adj[u].push_back(v);
        if (direction == 0) // Undirected Graph
        {
            adj[v].push_back(u);
        }
    }
    void PrintEdges()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

// Using VECTOR

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<int> ans[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main()
{
    int node;
    cout << "Enter the number of nodes : " << endl;
    cin >> node;
    int Edge;
    cout << "Enter the number of edges : " << endl;
    cin >> Edge;
    graph g;
    for (int i = 0; i < Edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v, 0);
    }
    g.PrintEdges();
    return 0;
}

/*
Time Complexity:

The time complexity of the addEdges() method is O(1) because it uses an unordered_map to store the adjacency list, and the time complexity of inserting an element into an unordered_map is O(1) on average.

The time complexity of the PrintEdges() method is O(V+E), where V is the number of vertices and E is the number of edges in the graph. This is because it iterates through all the vertices and their adjacent vertices.

The time complexity of the main function is O(E) because it adds E edges to the graph using the addEdges() method.

Therefore, the overall time complexity of the code is O(V+E).

Space Complexity:

The space complexity of the graph class is O(V+E) because it uses an unordered_map to store the adjacency list.

The space complexity of the main function is O(1) because it only uses a constant amount of memory to store the input values and the graph object.

Therefore, the overall space complexity of the code is O(V+E).
*/
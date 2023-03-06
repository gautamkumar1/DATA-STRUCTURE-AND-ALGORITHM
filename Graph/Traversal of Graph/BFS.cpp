#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <queue>
using namespace std;
void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int, bool> &visited, vector<int> &ans, unordered_map<int, set<int>> &adjList, int &node)
{
    // Make the queue for processing
    queue<int> q;
    // step 1 : Push the node
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front(); // step 2 : extract the front node
        q.pop();                   // step 3 : pop the forntNode
        // storefrontnode to ans
        ans.push_back(frontNode); // step 4  : push frontNode to the answer
        for (auto i : adjList[frontNode])
        { // step 5 : traverse all neighbours of frontnode
            if (!visited[i])
            {
                q.push(i); // step 6 : add all adjancey edges which connected to frontNode
                visited[node] = 1;
            }
        }
    }
}
// BFS : T(N) : O(V+E) and S(N) : O(V^2)
vector<int> BFS_Traversal(int n, vector<pair<int, int>> edges)
{
    // Make the adjancey List
    unordered_map<int, set<int>> adjList;
    // Make the visited array
    unordered_map<int, bool> visited;
    // Decalre the vector for final ans
    vector<int> ans;
    prepareAdjList(adjList, edges);
    // traverse all component
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(visited, ans, adjList, i);
        }
    }
    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    vector<int> ans = BFS_Traversal(n, edges);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

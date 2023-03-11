#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
// Time complexity of this algorithm is O(n^2) but we can optimize the time complexity of the this algo using minHeap
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    
    // Create the adjancey list
    unordered_map<int,list<pair<int,int> > > adj;
    for(int i=0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> key(n+1); 
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    // start algo
    key[1] = 0;
    parent[1] = -1;
    for(int i=1; i<n; i++){
        int mini = INT_MAX;
        int u;
        // finding the minimum value
        for(int v=1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                mini = key[v];
                u = v;
            }
        }
        // marks as the visited
        mst[u] = true;
        // check its adjacent node
        for(auto it : adj[u]){
        int v = it.first;
        int w = it.second;
        if(mst[v] == false && w < key[v]){
            parent[v] = u;
            key[v] = w;
        }
        
        }
    }
    // extracting the result
    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}

/*
To optimize the given code using a min heap, we can use a priority queue to store the nodes in increasing order of their key values. This way, we can avoid the linear search for the minimum key value and instead extract the node with the minimum key value from the priority queue.
*/
// T(N) : O(nLognM)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    for(int i = 0; i <= n; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    key[1] = 0;
    parent[1] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(mst[u] == true) continue;
        mst[u] = true;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main() {
int n, m;
cin >> n >> m;
vector<pair<pair<int, int>, int>> g;
for(int i = 0; i < m; i++) {
int u, v, w;
cin >> u >> v >> w;
g.push_back({{u, v}, w});
}
vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, g);
cout<<"Minimum Spanning Tree "<<endl;
for(int i = 0; i < result.size(); i++) {
cout << result[i].first.first << " --> " << result[i].first.second << " W : " << result[i].second << endl;
}
return 0;
}
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
void dfs(unordered_map<int,list<int> >&adj,unordered_map<int,bool>&visited,vector<int>&componet,int node){
    componet.push_back(node);
    visited[node]=1;
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(adj,visited,componet,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V,int E,vector<vector<int>> edges){
    unordered_map<int,list<int> > adj;
    unordered_map<int,bool> visited;
    vector<vector<int>> ans;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<V; i++){
        vector<int> componet;
        if(!visited[i]){
            dfs(adj,visited,componet,i);
            ans.push_back(componet);
        }
    }
    return ans;
}
// T(N) : O(V+E) and S(N) : O(V)
int main() {
    // Inputs for the graph
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    // Call the depthFirstSearch function
    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    // Print the resulting components
    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i+1 << ": ";
        for (int j = 0; j < components[i].size(); j++) {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

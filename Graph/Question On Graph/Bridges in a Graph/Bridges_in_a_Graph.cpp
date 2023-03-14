
#include <iostream>
#include <unordered_map>
#include<list>
#include<vector>
using namespace std;
void dfs(unordered_map<int,list<int> > &adj,unordered_map<int,bool> &visited,
vector<int> &dis,vector<int> &low,int parent,int node,int &timer,vector<vector<int> > &result){
    visited[node] = true;
    dis[node] = low[node] = timer++;
    for(auto nbr : adj[node]){
        // ingore condition 
        if(nbr == parent){
            continue;
        }
        else if(!visited[nbr]){
            dfs(adj,visited,dis,low,node,nbr,timer,result);
            // update low
            low[node] = min(low[node],low[nbr]);
            // found bridge
            if(low[nbr] > dis[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        // break edges condition 
        else{
            // update low
            low[node] = min(low[node],dis[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(v);
    vector<int> low(v);
    int parent = -1;
    int timer = 0;
    unordered_map<int,bool> visited;
    for(int i=0; i<v; i++){
        dis[i] = -1;
        low[i] = -1;
    }
    vector<vector<int> > result;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(adj,visited,dis,low,parent,i,timer,result);
        }
    }
    return result;
}
// T(N) : O(V+E) and S(n) : O(v+e)
int main() {
    int v = 6, e = 8;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {3, 5}, {1, 4}};

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges in the graph: " << endl;
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
    return 0;
}

#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;
// T(N) : O(N+E) and S(N) : O(N)
void DFS(unordered_map<int,list<int> > &adj,unordered_map<int,bool> &visited,vector<int> &dis,vector<int> &low,vector<int> &ap,int &parent,int &timer,int node){
    visited[node] = true;
    dis[node] = low[node] = timer++;
    int child = 0;
    for(auto nbr : adj[node]){
        if(nbr == parent) continue;
        if(!visited[nbr]){
            DFS(adj,visited,dis,low,ap,node,timer,nbr);
            // update child low
            low[node] = min(low[node],low[nbr]); 
            // Articulation Points or not -> the condition for identifying an articulation point should be
            if(low[nbr] >= dis[node] && parent != -1){
                ap[node] = 1;
            }
            child++;
        }
        else{
             // break edges
             low[node] = min(low[node],dis[nbr]);
        }
    }
    // This checks if the current node is the root node (indicated by parent == -1) and if it has more than one child. If both conditions are true, it marks the current node as an articulation point.
    if(parent == -1 && child > 1){
        ap[node] = 1;
    }
}
int main(){
    int n = 5;
    int e = 5;
    vector<pair<int,int> > edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    // create adj
    unordered_map<int,list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(n);
    vector<int> low(n);
    vector<int> ap(n,0);
    unordered_map<int,bool> visited;
    int parent = -1;
    int timer = 0;
    for(int i=0; i<n; i++){
        dis[i] = -1;
        low[i] = -1;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(adj,visited,dis,low,ap,parent,timer,i);
        }
    }
    cout<<"Articulation Points Are Follows "<<endl;
    for(int i=0; i<n; i++){
        if(ap[i] != 0){
            cout<<i<<" ";
        }
    } cout<<endl;
    return 0;
}
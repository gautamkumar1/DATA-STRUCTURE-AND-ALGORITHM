#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,list<pair<int,int> > > &adj,int node,int parent,int &ans){
        for(auto &i : adj[node]){
            int v = i.first;
            int check = i.second; // 0 nakli edge and 1 for asli edge
            if(v != parent){
                if(check == 1) ans++;
                dfs(adj,v,node,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<pair<int,int> > > adj;
        for(auto &vec : connections){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(make_pair(v,1)); // 1 for original edge
            adj[v].push_back(make_pair(u,0)); // 0 for nakli edge
        }
        int node = 0;
        int parent = -1;
        int ans = 0;
        dfs(adj,node,parent,ans);
        return ans;
    }
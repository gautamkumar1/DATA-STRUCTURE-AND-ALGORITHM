#include<bits/stdc++.h>
using namespace std;
int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,int> > > adj(n+1);
        for(auto edges : roads){
            int u = edges[0];
            int v = edges[1];
            int wt = edges[2];
            adj[u].push_back(make_pair(v,wt));
            adj[v].push_back(make_pair(u,wt));
        }
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int ans = INT_MAX;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto neigh : adj[node]){
                int v = neigh.first;
                int dis = neigh.second;
                ans = min(ans,dis);
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
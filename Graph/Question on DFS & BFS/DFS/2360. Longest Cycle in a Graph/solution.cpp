#include<bits/stdc++.h>
using namespace std;
int ans = -1;
    void dfs(vector<int>& edges,vector<bool> &visited,vector<bool> &dfsVisited,vector<int> &count,int u){
        if(u != -1){
            visited[u] = true;
            dfsVisited[u] = true;
            int v = edges[u];
            if(v != -1 && !visited[v]){
                count[v] = count[u]+1;
                dfs(edges,visited,dfsVisited,count,v);
            }
            else if(v != -1 && visited[v] == true && dfsVisited[v] == true){  // found cycle
                ans = max(ans,count[u]-count[v]+1);
            }
            dfsVisited[u]= false;
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n,0);
        vector<bool> dfsVisited(n,0);
        vector<int> count(n,1); // initialize starting all node count is one
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(edges,visited,dfsVisited,count,i);
            }
        }
        return ans;
    }
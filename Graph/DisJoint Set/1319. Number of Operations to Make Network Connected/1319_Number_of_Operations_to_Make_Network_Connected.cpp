#include<bits/stdc++.h>
using namespace std;
int findParent(vector<int>&parent,int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent,parent[node]);
    }
    void union_DisJointSet(int u,int v,vector<int> &parent,vector<int> &rank){
        u = findParent(parent,u);
        v = findParent(parent,v);
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u; 
        }
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        int components = n;
        for(auto&vec : connections){
            if(findParent(parent,vec[0]) != findParent(parent,vec[1])){
                union_DisJointSet(vec[0],vec[1],parent,rank);
                components--;
            }
        }
        return components-1;
    }
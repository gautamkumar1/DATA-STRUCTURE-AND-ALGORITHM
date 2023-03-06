#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;
void isTopoSort(unordered_map<int,list<int> > &adj,vector<bool> &visited,stack<int> &st,int &node){
    // mark the visited
    visited[node] = 1;
        // iterate the all negibhours of node
	    for(auto i : adj[node]){
	        if(!visited[i]){ // not visited
	           isTopoSort(adj,visited,st,i);  // recursion call
	        }
	    }
        // after backing the recursion call store in the stack
	    st.push(node);
}
// T(N) : O(v+e) -> linear and S(N) : O(v) -> Linear
vector<int> topoSort(vector<vector<int>> &edges, int v, int e) 
	{
        // create the adjlist
	unordered_map<int,list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
        vector<bool> visited(v); // visited 
	    stack<int> st; // stack
	    for(int i=0; i<v; i++){
	        if(!visited[i]){
	            isTopoSort(adj,visited,st,i);
	        }
	    }
	    vector<int> ans;
        // store the all stack recursion call in ans
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}

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
    cout<<"Topological Order \n";
    vector<int> ans = topoSort(edges,V,E);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}
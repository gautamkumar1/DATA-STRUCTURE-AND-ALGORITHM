#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue> 
/*
-------> Using Khan's Alagrithim ------>
What is Khan's Algorith ?
ans : Topological sorting is a technique used in computer science to order the vertices in a directed acyclic graph (DAG) in a linear way. The resulting order satisfies the property that if there is an edge from vertex A to vertex B in the graph, then A appears before B in the order. In other words, topological sorting orders the vertices in a way that respects the direction of the edges in the graph.

-------------> Important Point for this algorith ---->
1 . find the all indgree 
2. push  node in queue if indgree[node] == 0
3. repeat unitil if !q.empty()
4. Graph contain cycle condition : if(ans.size < V/node/n){return true} or if(cnt < V/node/n){return true}
*/

using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // step 1
    unordered_map<int,list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    // step 2
    vector<int> inDegree(v);
    for(auto i : adj){
        for(auto j : i.second){
            inDegree[j]++;
        }
    }
    // step 3
    queue<int> q;
    for(int i=0; i<v; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    // step 4
    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto neighbours : adj[frontNode]){
            

            inDegree[neighbours]--; // If indgree not eqal to zero
            if(inDegree[neighbours] == 0){
                q.push(neighbours);
            }
        }
    }
    // Graph Contain Cycle
    if(ans.size() < v){
        cout<<"Sorry This not DAG Graph";
        return {};
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
    vector<int> ans = topologicalSort(edges,V,E);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}
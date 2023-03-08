#include<iostream>
#include<list>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
bool isCycleFoundDFS(unordered_map<int,list<int> > &adj,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,int node){
    // mark the visited node
    visited[node] = true;
    // mark the dfs visited 
    dfsvisited[node] = true;
    // now check for all negibhours node
    for(auto neighbours : adj[node]){
        // if not visited neighbours then simple dfs call
        if(!visited[neighbours]){
            bool cyclePresent = isCycleFoundDFS(adj,visited,dfsvisited,neighbours);
            // this statement return true if cyclepresent otherwise this will move on next part
            if(cyclePresent){
                return true;
            }
        }
        // This condition for found cycle , if this condition is true then its return true
        else if(visited[neighbours] == true && dfsvisited[neighbours] == true){
            return true;
        }
    }
    // Most important part is here
    dfsvisited[node] = false; // after recursion call back must be marked the dfsVisited false
    return false; // this is the outer loop codition , nothing is true then this will return the false this means cycle is not present
}
// T(n) : O(V+E) -> Linear and S(N) : O(V) -> Linear
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges){
    // create adjList
    unordered_map<int,list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    // create visited and dfs visited map
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool CycleFound = isCycleFoundDFS(adj,visited,dfsvisited,i);
            if(CycleFound == true){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    if(detectCycleInDirectedGraph(n,edges)){
        cout<<"Found Cycle\n";
    }
    else
    {
        cout<<"Not Found Cycle  \n";
    }
    return 0;
}

#include<iostream>
#include<list>
#include<stack>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
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

// T(n) : O(V+E) -> Linear and S(N) : O(V) -> Linear
int detectCycleInDirectedGraph_USING_BFS(int n, vector < pair < int, int >> & edges){
    // create adjList
    unordered_map<int,list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    // Finding the indegree of all nodes -> indgree means us node par kitne edges aa rahe hai uske hum indgree bolte hai
    vector<int> indgree(n);
    for(auto i : adj){
        for(auto j : i.second){
            indgree[j]++;
        }
    }
    // queue
    queue<int> q;
    for(int i=0; i<n; i++){
        // if node indgree is zero(0) then push in queue
        if(indgree[i] == 0){
            q.push(i);
        }
    }
    // Topological order count 
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++; // incrementing the count
        // traverse the all neighbours of frontnode
        for(auto neighbours : adj[front]){
            // decrement the indgree if idgree[neigbhours] != 0 
            indgree[neighbours]--;
            if(indgree[neighbours] == 0){ // push the neighbours if indgree of negibhours is zero (0)
                q.push(neighbours);
            }
        }
    }
    // check the condition if cnt < n means cycle found else cycle not founf
    if(cnt < n){
        return 1;
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
    if(detectCycleInDirectedGraph_USING_BFS(n,edges)){
        cout<<"Found Cycle\n";
    }
    else
    {
        cout<<"Not Found Cycle  \n";
    }
    return 0;
}

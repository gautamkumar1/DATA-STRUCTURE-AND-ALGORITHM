#include<iostream>
#include<vector>
using namespace std;
// T(N) : O(V*E) and S(N) : O(v+E)
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u]+wt;
            }
        }
    }
    // check for negative weight cycle
    bool isNegativeCycle = false;
    for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                isNegativeCycle = true;
            }
    }
    if(isNegativeCycle == false){
        return dist[dest];
    }
    return -1;
}
int main() {
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    vector<vector<int>> edges(m);
    for(int i=0; i<m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }
    int shortestPath = bellmonFord(n, m, src, dest, edges);
    if(shortestPath == -1){
        cout << "Negative weight cycle detected!" << endl;
    } else {
        cout << "Shortest path from " << src << " to " << dest << " is " << shortestPath << endl;
    }
    return 0;
}
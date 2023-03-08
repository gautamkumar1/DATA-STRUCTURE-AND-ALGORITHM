#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create the adjcency list
    unordered_map<int,list<pair<int,int> > > adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w)); // make_pair(u,weight)
        adj[v].push_back(make_pair(u,w));
    }
    // create the distance array with initially initialize with Infinity
    vector<int> dist(vertices);
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    // set with the pair of [NodeDistance,NodeName/TopNode]
    set<pair<int,int> > st; 
    dist[source] = 0; // initialze the source node as a zero
    st.insert(make_pair(0,source)); // pair = {nodeDistance,Nodename}
    while(!st.empty()){
        auto top = *(st.begin()); /* This statement means : The asterisk (*) before (st.begin()) is a dereference operator, which returns the value stored at the memory location pointed to by the iterator. So, *(st.begin()) will return the first element in the container.*/
        // Now we will get the top = {Nodedistance , NodeName/TopNode}
        int NodeDistance = top.first;
        int NodeName = top.second;
        st.erase(st.begin()); // pop just like a bfs / REMOVE THE TOP DATA
        for(auto neighbours : adj[NodeName]){
            if(NodeDistance + neighbours.second < dist[neighbours.first]){
                // fetech record
                auto record = st.find(make_pair(dist[neighbours.first],neighbours.first));
                // if the recoord present in the set with high distance then we remove the distance and node.

                if(record != st.end()){
                    st.erase(record);
                }
                // update the distance
                dist[neighbours.first] = NodeDistance + neighbours.second;
                // Push
                st.insert(make_pair(dist[neighbours.first],neighbours.first));
            }
        }
    }
    return dist;
}
// T(N) : O(ElogV) where E is the number of Edges and V is the number of Vertices. S(N) : O(V)
int main() {
    int vertices = 4;
    int edges = 5;
    int source = 0;

    vector<vector<int>> vec = {{0, 1, 1}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5}, {2, 3, 1}};

    vector<int> result = dijkstra(vec, vertices, edges, source);

    // print out the results
    for(int i = 0; i < vertices; i++){
        cout << "Distance from " << source << " to " << i << " is " << result[i] << endl;
    }

    return 0;
}

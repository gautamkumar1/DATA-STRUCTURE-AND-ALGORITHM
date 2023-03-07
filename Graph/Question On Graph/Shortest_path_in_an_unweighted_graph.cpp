#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int startNode , int terminalNode){
    // create the adj list
    unordered_map<int,list<int> > adjlist;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    // push start node into the queue
    q.push(startNode);
    // mark the startnode parent is to -1
    parent[startNode] = -1;
    // mark the visited node
    visited[startNode] = true;
    // loop until q is not empty
    while(!q.empty()){
        int front = q.front();
        q.pop();
        // traverse the all neighbours of frnotnode
        for(auto i : adjlist[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    // after this we will get the all nodes parent
    vector<int> ans; // store the all shortest path in ans array
    int currNode = startNode; // intialize the currnode as terminalNode
    ans.push_back(currNode); // push the currnode to the ans array
    // loop until currnode not equal to startnode
    while(currNode != startNode){
        currNode = parent[currNode]; // this return the parent
        ans.push_back(currNode);
    }
    // after this while loop we get the shortesh path b/w startnode to terminalnode but in reverse order thats why we reverse the ans array
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    // create the graph
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(1, 3));
    // find the shortest path
    vector<int> path = shortestPath(edges, 4, 4, 1, 4);
    // print the shortest path
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
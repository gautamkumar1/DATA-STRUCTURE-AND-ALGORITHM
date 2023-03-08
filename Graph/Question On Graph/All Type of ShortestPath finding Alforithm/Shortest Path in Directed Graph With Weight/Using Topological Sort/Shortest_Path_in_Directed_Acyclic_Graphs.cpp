#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int> > > adjlist; // why use pair? bcz hume weight bhi store krna hai isliye pair liye hai
    // this code for Add Edges
    void addEdges(int u,int v,int w){
        pair<int,int> p = make_pair(v,w);
        adjlist[u].push_back(p);
    }
    // Print Adjlist
    void printAdj(){
        cout<<"Adjacenc List "<<endl;
        for(auto i : adjlist){
            cout<<i.first<<" -> "; // this print u
            for(auto j : i.second){
                // this code print in this format : [v,w]
                cout<<"[ "<<j.first<<" , "<<j.second<<" ]"; 
            }
            cout<<endl;
        }
    }
    // This function is to find topological sort using DFS
    void topologicalSort(unordered_map<int,bool>&visited,stack<int>&topoOrder,int node){
        visited[node] = true;
        for(auto it : adjlist[node]){
            if(!visited[it.first]){
                topologicalSort(visited,topoOrder,it.first);
            }
        }
        topoOrder.push(node);
    }

    // This function for getTheShortestPath
    void getTheShortestPath(vector<int>&dist,stack<int>&topoOrder,int srcNode){
        // intialize the srcNode as zero distance
        dist[srcNode] = 0;
        // traverse if stack is not empty
        while(!topoOrder.empty()){
            int top = topoOrder.top();
            topoOrder.pop();
            if(dist[top] != INT_MAX){ // this condition for if currNode is not eqal to infinity
                // iterate the all neighbhours of TOP
                for(auto it : adjlist[top]){
                    if(dist[top] + it.second < dist[it.first]){ // its means top ka distance ka weight + uska connected node ka wieght < dist of v ka
                        dist[it.first] = dist[top] + it.second;
                    }
                }
            }
        }
    }
};
// Time Complexity : O(V+E) and Space Complexity : O(V+E) , bcz you use the topological sort using DFS
int main(){
    Graph g;
    g.addEdges(0,1,5);
    g.addEdges(0,2,3);
    g.addEdges(1,2,2);
    g.addEdges(1,3,6);
    g.addEdges(2,3,7);
    g.addEdges(2,4,4);
    g.addEdges(2,5,2);
    g.addEdges(3,4,-1);
    g.addEdges(4,5,-2);
    // Printing the adj list
    g.printAdj();
    // finding the Topological sort
    int n = 6;
    unordered_map<int,bool> visited;
    stack<int> topoOrder;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.topologicalSort(visited,topoOrder,i);
        }
    }
    // set srcNode
    int srcNode = 1;
    // making the distance array with N size
    vector<int> dist(n);
    // initialize the all element in the vector with infinity
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }
    g.getTheShortestPath(dist,topoOrder,srcNode);
    // distance
    cout<<"Answer is \n";
    for(auto val : dist){
        cout<<val<<" ";
    } cout<<endl;
    return 0;
}
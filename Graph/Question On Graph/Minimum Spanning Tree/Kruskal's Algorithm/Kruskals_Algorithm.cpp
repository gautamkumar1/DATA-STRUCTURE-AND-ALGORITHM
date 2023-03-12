#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void makeSet(vector<int>&parent,vector<int>&rank,int n){
  for(int i=0; i<n; i++){
    parent[i] = i; // starting me sab node itself hi parent hoga
    rank[i] = 0; // starting me sabka rank 0 hoga
  }
}
int findParent(vector<int>&parent,int node){
  // Base case : agr us node ka parent bhi equal to node rahega
  if(parent[node] == node){
    return node;
  }
  return parent[node] = findParent(parent, parent[node]); // recursion call
}
void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
  // finding the parent of U and V
  u = findParent(parent,u);
  v = findParent(parent, v);
  if(rank[u] < rank[v]){ // agr U ka rank V se Small h tab hamesha Big rank wale ko parent banana hai
    parent[u] = v;
  }
  else if(rank[v] < rank[u]){  // agr V ka rank U se Small h tab hamesha Big rank wale ko parent banana hai
    parent[v] = u;
  }
  else{ //  yahan pe  U and V ka rank eqal hai : to hum kisiko bhi kisi se attach kr sakte hai , lekin parent ke rank ko yahan pe increment krna hai must hai.
    parent[u] = v;
    rank[v]++;
  }
}
// custom comparison function to sort the edges by their weight
bool cmp(vector<int>&a,vector<int>&b){
  return a[2] < b[2];
}
/*
---------------------> TIME COMPLEXITY --------------------------->
1 . findParent and Unionset Function Time complexity is O(4Alpha) ≈ O(4) ≈ O(1) so overall O(constant)
2. Time Complexity of Kruskal's Algorithm is O(ElogE) bcz you use the sort function And S(N) : O(E + V)
*/
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(),edges.end(),cmp); // sort the edges by their weight in increasing order
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent,rank,n);
    int totalMst = 0;
    for(int i=0; i<edges.size(); i++){
      int u = findParent(parent, edges[i][0]);
      int v = findParent(parent, edges[i][1]);
      int wt = edges[i][2];
      // rules agar U and V ka parent diff hai tb uska UNION / Merge kar do 
      if(u != v){
        totalMst+=wt;
        unionSet(u, v, parent, rank);
      }
    }
    return totalMst;
}

int main(){
    vector<vector<int>> edges = {{0, 1, 4}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {7, 6, 1}, {7, 8, 7}, {2, 8, 2}, {2, 3, 7}, {2, 5, 4}, {6, 8, 6}, {6, 5, 2}, {3, 5, 14}, {3, 4, 9}, {5, 4, 10}};
    int n = 9;
    int totalMst = minimumSpanningTree(edges, n);
    cout << "Minimum spanning tree weight: " << totalMst << endl;
    return 0;
}
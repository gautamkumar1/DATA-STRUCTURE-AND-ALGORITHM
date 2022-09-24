#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isSafe(vector<vector<int>>&m,vector<vector<int>> visited,int n,int x,int y){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y]==0) && (m[x][y]==1)){
        return true;
    }
    else
    {
        return false;
    }
    
}
void solve(vector<vector<int>> &m,vector<string>&ans,vector<vector<int>> visited,int n,int x,int y,string path){
    // Base Case
    if((x==n-1) && (y==n-1)){
        ans.push_back(path);
        return ;
    }
    // Marks true in visited after one direction visited
    visited[x][y] = 1;
    // Down
    int newX = x+1;
    int newY = y;
    if(isSafe(m,visited,n,newX,newY)){
        path.push_back('D');
        solve(m,ans,visited,n,newX,newY,path);
        path.pop_back();
    } 
    // Up
    newX = x-1;
    newY = y;
    if(isSafe(m,visited,n,newX,newY)){
        path.push_back('U');
        solve(m,ans,visited,n,newX,newY,path);
        path.pop_back();
    } 
    // Right
    newX = x;
    newY = y+1;
    if(isSafe(m,visited,n,newX,newY)){
        path.push_back('R');
        solve(m,ans,visited,n,newX,newY,path);
        path.pop_back();
    } 

    // Left
    newX = x;
    newY = y-1;
    if(isSafe(m,visited,n,newX,newY)){
        path.push_back('L');
        solve(m,ans,visited,n,newX,newY,path);
        path.pop_back();
    } 

    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n){
    vector<string> ans;
    if(m[0][0]==0){
        return ans;
    }
    int srcX = 0;
    int srcY = 0;
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
        
    }
    string path = "";
    solve(m,ans,visited,n,srcX,srcY,path);
    sort(ans.begin(),ans.end());
    return ans;
    
}

int main(){
    vector<vector<int>> m = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans = findPath(m,n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}
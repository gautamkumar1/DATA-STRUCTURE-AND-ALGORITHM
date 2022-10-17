#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int> &output,int index,int size){
    if(index>=size){
        ans.push_back(output);
        return ;
    }
    solve(arr,ans,output,index+1,size);
    int element = arr[index];
    output.push_back(element);
    solve(arr,ans,output,index+1,size);
}
vector<vector<int>> subSet(vector<int>&arr,int size){
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    solve(arr,ans,output,index,size);
    return ans;
}

int main(){
    vector<int> arr = {2,3};
    int N = 2;
    vector<vector<int>> ans = subSet(arr,N);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
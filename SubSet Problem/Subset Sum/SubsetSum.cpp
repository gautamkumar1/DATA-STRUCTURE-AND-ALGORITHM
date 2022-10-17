#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&arr,vector<int>&ans,int sum,int index,int size){
    if(index>=size){
        ans.push_back(sum);
        return ;
    }
    solve(arr,ans,sum,index+1,size);
    sum+=arr[index];
    solve(arr,ans,sum,index+1,size);
    // BackTracking;
    sum-=arr[index];
}

vector<int> SubSet_Sum(vector<int>&arr,int size){
    int sum = 0;
    int index = 0;
    vector<int> ans;
    solve(arr,ans,sum,index,size);
    return ans;
}

int main(){
    vector<int> arr = {2,3};
    int N = 2;
    vector<int> ans = SubSet_Sum(arr,N);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}
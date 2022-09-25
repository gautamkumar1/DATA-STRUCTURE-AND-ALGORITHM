#include<iostream>
#include<vector>
using namespace std;
int Getsum(vector<int>&arr){
    int suM = 0;
    for(int i=0; i<arr.size(); i++){
        suM+=arr[i];
    }
    return suM;
}

void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int> output,int index,int targetSum){
    int len = arr.size();
    int sum = -1;
    if(index>=len){
        sum = Getsum(output);
        if (sum==targetSum)
        {
            ans.push_back(output);
        }
        return ;
    }
    solve(arr,ans,output,index+1,targetSum);
    int element = arr[index];
    output.push_back(element);
    solve(arr,ans,output,index+1,targetSum);
}

vector<vector<int>> SubsetSum(vector<int>&arr,int targetSum){
    vector<vector<int>> ans;
    int index = 0;
    vector<int> output;
    solve(arr,ans,output,index,targetSum);
    return ans;
}

int main(){
    vector<int> arr = {10,20,30,40};
    int targetSum = 50;
    vector<vector<int>> ans = SubsetSum(arr,targetSum);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
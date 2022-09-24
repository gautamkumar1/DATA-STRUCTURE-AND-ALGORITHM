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

void solve(vector<int>&arr,vector<int>&ans,vector<int> output,int index){
    int len = arr.size();
    int sum = -1;
    if(index>=len){
        sum = Getsum(output);
        ans.push_back(sum);
        return ;
    }
    solve(arr,ans,output,index+1);
    int element = arr[index];
    output.push_back(element);
    solve(arr,ans,output,index+1);
}

vector<int> SubsetSum(vector<int>&arr){
    vector<int> ans;
    int index = 0;
    vector<int> output;
    solve(arr,ans,output,index);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<int> ans = SubsetSum(arr);
    for(int val: ans){
        cout<<val<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums,vector<vector<int>>&ans,int index){
    int len = nums.size();
    if(index>=len){
        ans.push_back(nums);
        return ;
    }
    for(int i=index; i<len; i++){
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }
}

vector<vector<int>> permutations(vector<int>&nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permutations(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}

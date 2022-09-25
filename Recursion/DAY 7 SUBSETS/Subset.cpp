#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &nums, vector<int> output, vector<vector<int>> &ans, int index)
{
    // Base Case
    int len = nums.size();
    if (index >= len)
    {
        ans.push_back(output);
        return;
    }

    // Include
    solve(nums, output, ans, index + 1);
    // Exclude
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, ans, index + 1);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, ans, index);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> next_smaller_value(vector<int>&arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i =n-1; i>=0; i--){
        int currentValue = arr[i];
        while (st.top()>=currentValue)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(currentValue);
    }
    return ans;
}

int main(){
    vector<int> arr = {2,1,4,3};
    vector<int> ans = next_smaller_value(arr);
    for(auto val: ans){
        cout<<val<<" ";
    }
    return 0;
}
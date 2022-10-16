#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long>&arr,int n){
    vector<long long> ans(n);
    stack<long long> st;
    st.push(-1);
    for (int i = n-1; i >=0 ; i--)
    {
        int currentValue = arr[i];
        while (st.top()!=-1 && st.top()<=currentValue)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(currentValue);
    }
    return ans;
}

int main(){
    vector<long long> arr = {1 ,3 ,2 ,4};
    int n = arr.size();
    vector<long long> ans = nextLargerElement(arr,n);
    for ( auto val : ans)
    {
        cout<<val<<" ";
    }
    return 0;
}
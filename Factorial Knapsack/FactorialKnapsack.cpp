#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int factorial_Knapsack(vector<int>&weight,vector<int>&value,int W,int n){
    vector<int> pi;
    for(int i=0; i<n; i++){
        pi.push_back(value[i]/weight[i]);
    }
    sort(pi.begin(),pi.end(),greater<int>());
    int solution = -1;
    int i = 0;
    cout<<"i : "<<i+1<<endl;
    while (W>0)
    {
        cout<<"i : "<<i+1<<endl;
        int amount = min(W,weight[i]);
        cout<<"Amount : "<<amount<<endl;
        solution = amount;
        W = W-amount;
        cout<<"w : "<<W<<endl;
        i++;
    }
    return solution;
}

int main(){
    vector<int> weight = {2,3,5,7,1,4,1};
    vector<int> value = {10,5,15,7,6,18,3};
    int n = 7;
    int W = 15;
    cout<<"Final Solution is "<<factorial_Knapsack(weight,value,W,n);
    return 0;
}
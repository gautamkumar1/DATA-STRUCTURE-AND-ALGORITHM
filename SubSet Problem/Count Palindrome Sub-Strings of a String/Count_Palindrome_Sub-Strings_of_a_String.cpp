
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str,int i,int j){
    if(i>j){
        return false;
    }
    while(i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int CountPS(char arr[], int n)
{
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(isPalindrome(arr,i,j)){
                count++;
            }
        }
    }
    return count;
}  
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

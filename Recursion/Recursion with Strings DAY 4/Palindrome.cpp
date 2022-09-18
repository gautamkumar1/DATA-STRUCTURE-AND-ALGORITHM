#include<iostream>
using namespace std;
bool isPalindrome(string str,int low,int high){
    // Base Case
    if(low>high){
        return true;
    }
    if(str[low]!=str[high]){
        return false;
    }
    else
    {
        return isPalindrome(str,low+1,high-1);
    }
    
}

int main(){
    string str = "aaaa";
    cout<<isPalindrome(str,0,str.length()-1);
    return 0;
}
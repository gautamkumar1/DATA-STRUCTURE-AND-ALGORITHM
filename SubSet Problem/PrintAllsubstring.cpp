#include<bits/stdc++.h>
using namespace std;

void subString(string str){
    int n = str.length();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout<<str[k];
            }
            cout<<endl;
        }
    }
}

int main(){
    string str = "abcd";
    subString(str);
    return 0;
}
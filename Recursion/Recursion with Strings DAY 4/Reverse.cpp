#include<iostream>
using namespace std;

void reverse(string&ch,int start,int end){
    if(start>end){
        return;
    }
    swap(ch[start],ch[end]);
    start++;
    end--;
    reverse(ch,start,end);

}

int main(){
    string str = "gautam";
    int len = str.length();
    reverse(str,0,len-1);
    cout<<str<<endl;
    return 0;

}
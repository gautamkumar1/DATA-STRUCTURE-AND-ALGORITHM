#include<iostream>
using namespace std;
void sayDigit(int n,string*arr){
    if(n==0){
        return;
    }
    int digit = n%10;
    n/=10;
    sayDigit(n,arr);
    cout<<arr[digit-1]<<" ";
}

int main(){
    string arr[10] = {"one","two","three","four","five","six","seven","eight","nine","ten"};
    int n;
    cin>>n;
    sayDigit(n,arr);
    return 0;

}


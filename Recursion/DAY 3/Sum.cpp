#include<iostream>
using namespace std;

int getSum(int *arr,int size){
    if(size==0){
        return 0;
    }
    if (size==1)
    {
        return arr[0];
    }
    int sum = 0;
    sum = arr[0]+getSum(arr+1,size-1);
    return sum;
    
    
}

int main(){
    int arr[5] = {2,1,1,1,1};
    int size = 5;
    cout<<getSum(arr,size)<<endl;
    return 0;
}
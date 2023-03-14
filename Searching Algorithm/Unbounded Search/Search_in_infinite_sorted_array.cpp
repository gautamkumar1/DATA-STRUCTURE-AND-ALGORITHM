#include <iostream>
using namespace std;


// brute force
int searchInInfinteArrya(int*arr,int target){
    int pos = -1;
    int i=0;
    while(1){
        i++;
        if(arr[i] > target){
            break;
        }
        if(arr[i] == target){
            pos = i;
            break;
        }
    }
    return pos;
}
// Optimize solution
int Binary_Search(int *arr, int low, int high, int k)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int Exp_Search(int*arr,int target){
    if(arr[0] == target){
        return 0;
    }
    int i = 0;
    int j = 1;
    while(arr[j] <= target){
        i=j;
        j*=2;
    }
    return Binary_Search(arr,i,j,target);
}
int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 10;
    cout<<searchInInfinteArrya(arr,target)<<endl;
    cout<<Exp_Search(arr,target)<<endl;
    return 0;
}
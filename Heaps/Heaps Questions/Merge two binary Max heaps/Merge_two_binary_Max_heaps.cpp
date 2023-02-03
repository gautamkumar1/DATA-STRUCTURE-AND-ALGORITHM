/*
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
*/
#include <bits/stdc++.h>
using namespace std;
void heapifiy(vector<int> &arr, int i, int size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapifiy(arr, largest, size);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    for (auto i : a)
        ans.push_back(i);
    for (auto i : b)
        ans.push_back(i);

    int size = ans.size();

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapifiy(ans, i, size);
    }
    return ans;
}
int main(){
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    vector<int> ans = mergeHeaps(a,b);
    cout<<"Merged Heaps Data are "<<endl;
    for (auto val : ans)
    {
        cout<<val<<" ";
    }
    return 0;
    

}
#include<bits/stdc++.h>
/*

1. Array follows 0 - based indexing. 

2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.

3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.
***************************************************************************************************************************************
1. Array follows 1 - based indexing. 

2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i)-th index if it exists.

3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.
*/
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    // Insert Function 
    // T(N) : O(logn)
    void insertHeap(int val){
        // Increment
        size+=1;
        int index=size;
        arr[index]=val;
        while (index>1)
        {
            int parent = (index/2);
            if (arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
            
            
        }
        
    }
    // print function
    void printHeap(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    }
    // Delete Function
    // T(n) : O(logn)
    void deletefromHeap(){
        if(size == 0){
            cout<<"Nothing To delete"<<endl;
            return;
        }
        // Step 1 : put first value to last value
        arr[1]=arr[size];
        // Delete
        size--;
        // Take correct position of node
        int i=1;
        while (i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            // Case 1 : 
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            // case 2
            else if(rightIndex < size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            // case 3
            else
            {
                return;
            }
            
        }
        
    }
};
// Heapifiy
// T(n) : O(logn)
void heapfiy(int*arr,int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapfiy(arr,n,largest);
    }
}
// T(n) : O(N)
void bulidMaxHeap(int*arr,int size){
    for (int i = size/2; i>0; i--)
    {
        heapfiy(arr,size,i);
    }
}

int main(){
    heap h;
    h.insertHeap(10);
    h.insertHeap(9);
    h.insertHeap(89);
    h.insertHeap(12);
    h.printHeap();
    h.deletefromHeap();
    h.printHeap();
    int arr[] = {-1,10,9,89,12};
    int size = 4;
    bulidMaxHeap(arr,size);
    cout<<"Now printing the array "<<endl;
    for (int i = 1; i <=size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
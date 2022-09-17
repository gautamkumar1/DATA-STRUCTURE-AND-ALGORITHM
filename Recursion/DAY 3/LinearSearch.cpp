 #include<iostream>
using namespace std;

bool linearSearch(int*arr,int size,int key){
    if(size == 0){
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        bool remaingPart = linearSearch(arr+1,size-1,key);
        return remaingPart;
    }
    
}

int main(){
    int arr[5] = {4,8,1,2,9};
    int size = 5;
    int key = 2;
    bool ans = linearSearch(arr,size,key);
    if(ans){
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    return 0;
    
}
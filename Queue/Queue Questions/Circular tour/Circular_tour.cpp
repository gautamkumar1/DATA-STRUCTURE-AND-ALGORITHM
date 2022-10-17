/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
index: 0     1    2     3
A = [{4,6},{6,5},{7,3},{4,5}]  How to access? petrol and distance
                               Ans: petrol access: A[i].petrol and Distance acess : A[i].distance
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
*/

#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
        int deficit = 0; // For negative petrol balance strore
        int balance = 0; // petrol remain ke liye
        int start = 0; // starting index
        for(int i = 0; i<n; i++){
            balance+=p[i].petrol-p[i].distance;
            if(balance<0){
                deficit+=balance;
                balance = 0;
                start = i+1;
            }
        }
        if(balance+deficit>=0){
            return start;
        }
        else{
            return -1;
        }
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

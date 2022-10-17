/*
Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
*/

#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
     // Step 1 : store count of all charcater
    unordered_map<char,int> count;
    queue<char> q; // to store character
    string ans = ""; // to strone ans
    for(int i = 0; i<A.length(); i++){
        char ch = A[i];
        count[ch]++; // increment count of one by one all character
        q.push(ch); // push all charcter in queue
        while (!q.empty()) // checking non repeating character
        {
            if(count[q.front()]!=1){ // Non repating character condition
                q.pop();
            } 
            else
            {
                ans.push_back(q.front()); // Push repeating character
                break;
            }
            
        }
        // After outside loop when enter if queue empty ya ans mil gya hoga
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string str = "aabc";
    cout<<"Before : "<<str<<endl;
    string ans = FirstNonRepeating(str);
    cout<<"After : "<<ans<<endl;
    return 0;
}
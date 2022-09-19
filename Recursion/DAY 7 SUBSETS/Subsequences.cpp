#include<iostream>
#include<vector>
using namespace std;

void solve(string str,string output,vector<string>&ans,int index){
    int len = str.length();
    if(index>=len){
        if(output.length()>0){
            ans.push_back(output);
        }
        return ;
    }

    // Exclude
    solve(str,output,ans,index+1);
    // Include
    char element = str[index];
    output.push_back(element);
       solve(str,output,ans,index+1);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str,output,ans,index);
    return ans;
}

int main(){
    string str = "abc";
    vector<string> ans = subsequences(str);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    } cout<<endl;
    return 0;
}
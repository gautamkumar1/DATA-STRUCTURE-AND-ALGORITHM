/*
Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
*/

#include<iostream>
#include<vector>
using namespace std;
void solve(string digits,string output,vector<string>&ans,string*mapping,int index){
    int len = digits.length();
    if(index>=len){
        ans.push_back(output);
        return ;
    }

    int number = digits[index]-'0'; // Converting character number to integer number
    string value = mapping[number]; // Finding string value correspounding given number
    for(int i=0; i<value.length(); i++){
        char element = value[i];
        output.push_back(element);
        solve(digits,output,ans,mapping,index+1); // Recursive call
        output.pop_back(); // BackTracking
    }

}
vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }
    string output = "";
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index = 0;
    solve(digits,output,ans,mapping,index);
    return ans;
}

int main(){
    string digit = "234";
    vector<string> ans = letterCombinations(digit);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    } cout<<endl;

    return 0;
}
#include<iostream>
#include<stack>
using namespace std;
bool isMatching(char a ,char b){
    if(a==')' && b=='('){
        return 1;
    }
    else if(a=='}' && b=='{'){
        return 1;
    }
    else if(a=='[' && b==']'){
        return 1;
    }
    return 0;
}

bool isValidParenthesis(string str){
    stack<char> st;
    for(int i =0; i<str.length(); i++){
        char ch = str[i];
        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else
        {
            if(!st.empty()){
                char top = st.top();
                if(isMatching(ch,top)){
                    st.pop();
                }
                else
                {
                    return 0;
                }
                
            }
            else
            {
                return 0;
            }
            
        }
        
    }
    if(st.empty()){
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main(){
    string str = "({})";
    if(isValidParenthesis(str)){
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}
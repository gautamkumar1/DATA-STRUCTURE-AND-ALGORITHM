#include<iostream>
#include<stack>
using namespace std;

bool isRedundant(string str){
    int len = str.length();
    stack<char> st;
    for(int i =0; i<len; i++){
        char ch = str[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else
        {
            if(ch==')'){
                bool redudant = true;
                while (st.top()!='(')
                {
                    char top = st.top();
                    if(top=='+'||top=='-'||top=='*'||top=='/'){
                        redudant = false;
                    }
                    st.pop();
                }
                if(redudant==true){
                    return true;
                }
                st.pop();
                
            }
        }
        
    }
    return false;
}

int main(){
    string str = "((a+c*b)+(c)))";
    if(isRedundant(str)){
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
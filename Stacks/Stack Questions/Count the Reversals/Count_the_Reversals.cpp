#include<iostream>
#include<stack>
using namespace std;

int countReversals(string str){
    int len = str.length();
    if(len%2==1){
        return -1;
    }
    stack<char> st;
    for(int i =0; i<len; i++){
        char ch = str[i];
        if(ch=='{'){
            st.push(ch);
        }
        else
        {
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
            else
            {
                st.push(ch);
            }
            
        }
        
    }
    int a = 0; 
    int b = 0;
    while (!st.empty())
    {
        char top = st.top();
        if(top=='{'){
            a++;
        }
        if(top=='}'){
            b++;
        }
        st.pop();
    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main(){
    string str = "}{{}}{{{";
    int ans = countReversals(str);
    cout<<"Total count reversals is "<<ans<<endl;
    return 0;
}
#include <iostream>
#include <stack>

using namespace std;
void solve(stack<int> &st, int count, int size)
{
    if (count == size / 2)
    {
        cout << "Middle Element is " << st.top() << endl;
        return;
    }
    int ele = st.top();
    st.pop();
    solve(st, count + 1, size);
    st.push(ele);
}
void findMiddleElement(stack<int> &st)
{
    int size = st.size();
    int count = 0;
    solve(st, count + 1, size);
}
void solve2(stack<int> &st, int count, int size)
{
    if (count == size / 2)
    {
        cout << "Middle Element Delete SucessFull"<<endl;
        st.pop();
        return;
    }
    int ele = st.top();
    st.pop();
    solve2(st, count + 1, size);
    st.push(ele);
}
void DeleteMiddleMiddleElement(stack<int>&st){
    int size = st.size();
    int count = 0;
    solve2(st,count,size);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    findMiddleElement(st);
    DeleteMiddleMiddleElement(st);
    findMiddleElement(st);
    return 0;
}
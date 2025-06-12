#include<iostream>
#include<stack>
using namespace std;
void print(stack<int>& st)
{
    stack<int> temp;
    while(st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    while(temp.size())
    {
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}
void pushAtBottom(stack<int>& st,int val)
{
    stack<int> temp;
    while(st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size())
    {
        st.push(temp.top());
        temp.pop();
    }
}
void pushAtIdx(stack<int>& st,int val,int idx)
{
    stack<int> temp;
    for(int i=0;i<st.size()-idx;i++)
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size())
    {
        st.push(temp.top());
        temp.pop();
    }
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    pushAtBottom(st,70);
    print(st);
    pushAtIdx(st,80,2);
    print(st);
    return 0;
}
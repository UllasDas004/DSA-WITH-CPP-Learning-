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
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    print(st);
    stack<int> gt,rt;
    while(st.size())
    {
        gt.push(st.top());
        st.pop();
    }
    while(gt.size())
    {
        rt.push(gt.top());
        gt.pop();
    }
    while(rt.size())
    {
        st.push(rt.top());
        rt.pop();
    }
    print(st);
    return 0;
}
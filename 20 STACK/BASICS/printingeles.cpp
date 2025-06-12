#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    stack<int> temp;
    while(st.size())
    {
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp.size())
    {
        cout<<temp.top()<<" ";
        st.push(temp.top());
        temp.pop();
    }
    return 0;
}
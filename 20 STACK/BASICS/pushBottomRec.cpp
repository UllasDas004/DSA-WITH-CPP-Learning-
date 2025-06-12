#include<iostream>
#include<stack>
using namespace std;
void displayRec(stack<int>& st)
{
    if(st.size() == 0)
    {
        cout<<endl;
        return;
    }
    int x = st.top();
    st.pop();
    displayRec(st);
    cout<<x<<" ";
    st.push(x);
}
void pushAtBottomRec(stack<int>& st,int val)
{
    if(st.size() == 0)
    {
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottomRec(st,val);
    st.push(x);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    displayRec(st);
    pushAtBottomRec(st,70);
    displayRec(st);
    return 0;
}
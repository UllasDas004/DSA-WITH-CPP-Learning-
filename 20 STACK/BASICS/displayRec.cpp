#include<iostream>
#include<stack>
using namespace std;
void displayRecRev(stack<int>& st)
{
    if(st.size() == 0) return;
    int x = st.top();
    cout<<x<<" ";
    st.pop();
    displayRecRev(st);
    st.push(x);
}
void displayRec(stack<int> st)
{
    if(st.size() == 0) return;
    int x = st.top();
    st.pop();
    displayRec(st);
    cout<<x<<" ";
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
    stack<int> temp;
    displayRecRev(st);
    cout<<endl;
    displayRec(st);
    return 0;
}
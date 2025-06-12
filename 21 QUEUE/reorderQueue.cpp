#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>& q)
{
    int n = q.size();
    for(int i=0;i<n;i++)
    {
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of elements(Even):- ";
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        int x;
        cin>>x;
        q.push(x);
    }
    cout<<"Original queue."<<endl;
    display(q);
    stack<int> st;
    for(int i=0;i<n/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<n/2;i++)
    {
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n/2;i++)
    {
        q.push(q.front());
        q.pop();
    }
    cout<<"Intermidiate queue."<<endl;
    display(q);
    for(int i=0;i<n/2;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<n/2;i++)
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<"Final queue."<<endl;
    display(q);
    return 0;
}
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
    queue<int> q;
    stack<int> st;
    int n;
    cout<<"Enter the number of elements in the queue:- ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"Enter number"<<i+1<<":- ";
        cin>>x;
        q.push(x);
    }
    display(q);
    int k;
    cout<<"Enter the number of elements to reverse:- ";
    cin>>k;
    for(int i=0;i<k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++)
    {
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++)
    {
        q.push(q.front());
        q.pop();
    }
    display(q);
    return 0;
}
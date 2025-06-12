#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements:- ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter stock price of day"<<i+1<<":- ";
        cin>>arr[i];
    }
    cout<<"Stock prices."<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    stack<int> st;
    int ans[n];
    ans[0] = 1;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(st.size() && arr[st.top()]<=arr[i]) st.pop();
        if(st.size() == 0) ans[i] = -1;
        else ans[i] = i-st.top();
        st.push(i);
    }
    
    cout<<"Stock span."<<endl;
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
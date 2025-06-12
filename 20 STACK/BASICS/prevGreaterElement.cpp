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
        cout<<"Enter number"<<i+1<<":- ";
        cin>>arr[i];
    }
    cout<<"Original array."<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    stack<int> st;
    int ans[n];
    ans[0] = -1;
    st.push(arr[0]);
    for(int i=1;i<n;i++)
    {
        while(st.size() && st.top()<arr[i]) st.pop();
        if(st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    
    cout<<"Answer array."<<endl;
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
}
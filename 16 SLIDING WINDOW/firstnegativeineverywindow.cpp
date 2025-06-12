#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int k;
    cout<<"Enter the size of subarrays:- ";
    cin>>k;
    int ans[n-k+1];
    int p = -1;
    for(int i=0;i<k;i++)
    {
        if(a[i]<0)
        {
            p = i;
            ans[0] = a[p];
            break;
        }
    }
    if(p == -1) ans[0] = 1; //IF THERE IS NO NEGATIVE IN FIRST WINDOW
    for(int i=1;i<n-k+1;i++)
    {
        if(p>=i) ans[i] = a[p];
        else
        {
            for(int l=i;l<=i+k;l++)
            {
                if(a[l]<0)
                {
                    p = l;
                    break;
                }
            }
            if(p != -1) ans[i] = a[p];
            else ans[i] = 1; //IF THERE IS NO NEGATIVE IN WINDOW
        }
    }
    cout<<"Answer is."<<endl;
    for(int i=0;i<n-k+1;i++)
    cout<<ans[i]<<" ";
    return 0;
}
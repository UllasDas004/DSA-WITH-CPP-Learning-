#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int target;
    cout<<"Enter the target number:- ";
    cin>>target;
    bool flag = false;
    int idx;
    for(int i=0;i<=n-1;i++)
    {
        if(a[i] == target)
        {
            flag = true;
            idx = i;
            break;
        }
    }
    if(flag == true)
    cout<<target<<" is found at index "<<idx<<".";
    else
    cout<<target<<" is not found.";
    return 0;
}
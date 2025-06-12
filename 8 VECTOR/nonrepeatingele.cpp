#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of array:- ";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int ele = a[0];
    bool flag = false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i] != a[j])
            {
                ele = a[i];
                flag = true;
            }
        }
    }
    if(flag == true)
    cout<<ele;
    else
    cout<<"No such element.";
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n1;
    cout<<"Enter size of first array:- ";
    cin>>n1;
    int a[n1];
    cout<<"Enter first matrix."<<endl;
    for(int i=0;i<n1;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    int n2;
    cout<<"Enter size of second array:- ";
    cin>>n2;
    int b[n2];
    cout<<"Enter second matrix."<<endl;
    for(int i=0;i<n2;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>b[i];
    }
    int c[n1+n2];
    int i=0,j=0,k=0;
    while(k<n1+n2)
    {
        if(a[i]<b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    cout<<"First array."<<endl;
    for(int i=0;i<n1;i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"second array."<<endl;
    for(int i=0;i<n2;i++) cout<<b[i]<<" ";
    cout<<endl;
    cout<<"Merged array."<<endl;
    for(int i=0;i<n1+n2;i++) cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}
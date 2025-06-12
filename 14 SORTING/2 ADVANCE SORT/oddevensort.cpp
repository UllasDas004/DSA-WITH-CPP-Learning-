#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    cout<<"Enter number of elements:- ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>a[i];
    }
    cout<<"Original array."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    int noo=0,noe=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2 == 0)noe++;
        else noo++;
    }
    int i=0,j=noo;
    while(j<n)
    {
        if(a[i]%2 == 0 && a[j]%2 == 1)
        {
            swap(&a[i],&a[j]);
            for(int k=i;k>0 && a[k]<a[k-1];k--)
            {
                swap(&a[k],&a[k-1]);
            }
            for(int k=j;k>noo && a[k]<a[k-1];k--)
            {
                swap(&a[k],&a[k-1]);
            }
            i++;
            j++;
        }
        if(a[i]%2 == 1)
        {
            for(int k=i;k>0 && a[k]<a[k-1];k--)
            {
                swap(&a[k],&a[k-1]);
            }
            i++;
        }
        if(a[j]%2 == 0)
        {
            for(int k=j;k>noo && a[k]<a[k-1];k--)
            {
                swap(&a[k],&a[k-1]);
            }
            j++;
        }
    }
    cout<<"Reshuffled array."<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
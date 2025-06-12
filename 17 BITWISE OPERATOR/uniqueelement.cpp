#include<iostream>
using namespace std;
int main()
{
    int a[] = {4,4,1,3,2,3,10,1,2};
    int n = 9;
    int res = 0;
    for(int i=0;i<n;i++)
    res = res ^ a[i];
    cout<<"Unique element is "<<res;
    return 0;
}
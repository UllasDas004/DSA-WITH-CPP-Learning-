#include<iostream>
using namespace std;
int main()
{
    int a[] = {1,2,1,3,2,5, 5, 9, 8, 8};
    int n = sizeof(a)/sizeof(a[0]);
    int res = 0;
    for(int i=0;i<n;i++)
    res = res ^ a[i];
    int temp = res,k = 0;
    while(true)
    {
        if((temp & 1) == 1) break;
        temp = temp >> 1;
        k++;
    }
    int retval = 0;
    for(int i=0;i<n;i++)
    {
        if(((a[i] >> k) & 1) == 1)
        retval ^= a[i];
    }
    cout<<"Unique elements are "<<retval<<" "<<(retval^res);
    return 0;
}
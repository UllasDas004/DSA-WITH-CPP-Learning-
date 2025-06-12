#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter m and n:- "<<endl;
    cin>>m>>n;
    vector<int> x(m-1),y(n-1);
    cout<<"Enter x costs."<<endl;
    for(int i=0;i<m-1;i++) cin>>x[i];
    cout<<"Enter y costs."<<endl;
    for(int i=0;i<n-1;i++) cin>>y[i];
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int i=m-2,j=n-2,h=1,v=1;
    int total = 0;
    while(i>=0 && j>=0)
    {
        if(x[i]>y[j])
        {
            total += x[i]*v;
            h++;
            i--;
        }
        else if(x[i]<y[j])
        {
            total += y[j]*h;
            v++;
            j--;
        }
        else
        {
            if(h>v)
            {
                total += x[i]*v;
                h++;
                i--;
            }
            else
            {
                total += y[j]*h;
                v++;
                j--;
            }
        }
    }
    while(i>=0)
    {
        total += x[i]*v;
        h++;
        i--;
    }
    while(j>=0)
    {
        total += y[j]*h;
        h++;
        j--;
    }
    cout<<"Minimum cost is "<<total<<endl;
    return 0;
}
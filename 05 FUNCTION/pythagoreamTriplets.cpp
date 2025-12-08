// there is a given n
// we have to find the number of triplets (a,b,c) where a,b,c <= n
// that forms a pythagorean triplet a*a + b*b = c*c

// here we will use Euclid's Formula to find them
// a = u*u -v*v, b = 2*u*v, c = u*u + v*v

// u,v < sqrt(n) and u and v are co prime also of different parity

#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    int mn = min(a,b),mx = max(a,b);
    while(mn > 0)
    {
        int temp = mx%mn;
        mx = mn;
        mn = temp;
    }
    return mx;
}
int countTriples(int n)
{
    int count = 0;
    for(int u=2;u<=sqrt(n);u++)
    {
        for(int v=1;v<u;v++)
        {
            if((u-v)%2 == 0 || gcd(u,v) != 1) continue;
            int c = u*u + v*v;
            if(c > n) break;
            count += 2*(n/c);
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter the n:- ";
    cin>>n;
    int ans = countTriples(n);
    cout<<"Number of triplets are "<<ans<<endl;
    return 0;
}
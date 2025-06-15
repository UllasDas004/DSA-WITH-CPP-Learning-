#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void fillSieve(vector<bool>& sieve)
{
    int n = sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++)
    {
        for(int j=2*i;j<=n;j+=i)
        sieve[j] = 0;
    }
}
int main()
{
    int n;
    cout<<"Enter a number:- ";
    cin>>n;
    if(n<=2)
    {
        cout<<"There is 0 prime numbers less than "<<n<<".";
        return 0;
    }
    int count = 0;
    n = n - 1;
    vector<bool> sieve(n+1,1);
    fillSieve(sieve);
    for(int i=2;i<=n;i++)
    {
        if(sieve[i] == 1) count++;
    }
    if(count == 1) cout<<"There is 1 prime number less than "<<n+1<<".";
    else cout<<"There are "<<count<<" prime numbers less than "<<n+1<<".";
    return 0;
}
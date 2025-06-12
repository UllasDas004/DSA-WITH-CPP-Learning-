#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<long long> fact(26,1);
    int MOD = 1000000000 + 7; //10^9 + 7
    for(int i=1;i<26;i++)
    {
        fact[i] = ((i%MOD) * (fact[i-1]%MOD)) % MOD;
        cout<<i<<"! = "<<fact[i]<<endl;
    }
    return 0;
}
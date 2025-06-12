#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int minSubsetProd(vector<int>& v)
{
    int n = v.size();
    int cz = 0,cn = 0,cp = 0,prod_pos = 1,prod_neg = 1;
    int mxNeg = INT_MIN,mnPos = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(v[i] < 0)
        {
            cn++;
            prod_neg *= v[i];
            mxNeg = max(mxNeg,v[i]);
        }
        else if(v[i] == 0) cz++;
        else
        {
            cp++;
            prod_pos *= v[i];
            mnPos = min(mnPos,v[i]);
        }
    }
    if(cn == 0)
    {
        if(cz > 0) return 0;
        else return mnPos;
    }
    else
    {
        if(cn%2 == 1) //even
        return prod_neg*prod_pos;
        else //even
        return (prod_neg/mxNeg)*prod_pos;
    }
}
int main()
{
    int n;
    cout<<"Enter total number of elements:- ";
    cin>>n;
    vector<int> v(n),weights(n);
    cout<<"Enter elements with spaces."<<endl;
    for(int i=0;i<n;i++) cin>>v[i];
    int ans = minSubsetProd(v);
    cout<<"Minimum product of a subset is "<<ans<<endl;
    return 0;
}
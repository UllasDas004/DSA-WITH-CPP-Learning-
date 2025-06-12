#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool check(int mid,vector<int>& weights, int days)
{
    int m = mid;
    int count = 1;
    for(int i=0;i<weights.size();i++)
    {
        if(m>=weights[i]) m -= weights[i];
        else
        {
            m = mid;
            m -= weights[i];
            count++;            
        }
    }
    if(count<=days) return true;
    else return false;
}
int main()
{
    int n;
    cout<<"Enter number of packages:- ";
    cin>>n;
    vector<int> weights(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter weight of package"<<i+1<<":- ";
        cin>>weights[i];
    }
    int days;
    cout<<"Enter the limit of days:- ";
    cin>>days;
    int max = INT_MIN;
    int sum = 0;
    for(int i=0;i<weights.size();i++)
    {
        if(weights[i]>max) max = weights[i];
        sum += weights[i];
    }
    int lo = max;
    int hi = sum;
    int ans = sum;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(mid,weights,days))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout<<"The minimum capacity is "<<ans;
    return 0;
}
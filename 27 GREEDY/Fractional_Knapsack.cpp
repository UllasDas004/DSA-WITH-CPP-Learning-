#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int>& p1,pair<int,int>& p2)
{
    double r1 = (p1.first*1.0)/(p1.second*1.0);
    double r2 = (p2.first*1.0)/(p2.second*1.0);
    return r1 > r2;
}
double fractionalKnapsack(vector<int>& value,vector<int>& weights,int n,double w)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back({value[i],weights[i]});
    sort(v.begin(),v.end(),cmp);
    double profit = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second <= w)
        {
            profit += v[i].first;
            w -= v[i].second;
        }
        else
        {
            profit += (v[i].first*1.0)/(v[i].second*1.0)*w;
            w = 0;
            break;
        }
    }
    return profit;
}
int main()
{
    int n;
    double w;
    cout<<"Enter total number of items:- ";
    cin>>n;
    vector<int> value(n),weights(n);
    cout<<"Enter values of each items with spaces."<<endl;
    for(int i=0;i<n;i++) cin>>value[i];
    cout<<"Enter weights of each items with spaces."<<endl;
    for(int i=0;i<n;i++) cin>>weights[i];
    cout<<"Enter the total capacity:- ";
    cin>>w;
    double profit = fractionalKnapsack(value,weights,n,w);
    cout<<"The maximum value can be get is "<<profit<<endl;
    return 0;
}
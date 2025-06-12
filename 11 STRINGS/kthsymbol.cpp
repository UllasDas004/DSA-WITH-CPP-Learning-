#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter the row number:- ";
    cin>>n;
    cout<<"Enter the element number:- ";
    cin>>k;
    vector<string> v;
    v.push_back("0");
    int m=1;
    for(int i=2;i<=n;i++,m*=2)
    {
        string s;
        for(int j=0;j<m;j++)
        {
            if(v[i-2][j] == '0') s += "01";
            else s += "10";
        }
        v.push_back(s);
    }
    for(int i=0;i<n;i++)
    cout<<v[i]<<endl;
    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    cout<<"Enter first string:- ";
    string s;
    cin>>s;
    cout<<"Enter second string:- ";
    string t;
    cin>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s == t) cout<<"YES";
    else cout<<"NO";
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s,t;
    cout<<"Enter first string:- ";
    cin>>s;
    cout<<"Enter second string:- ";
    cin>>t;
    if(s.length()!=t.length()) 
    {
        cout<<s<<" and "<<t<<" are not isomorphic";
        return 0;
    }
    // Checking isomorphic from the perspective of s
    vector<int> v(150,1000);
    bool flag = false;
    for(int i=0;i<s.length();i++)
    {
        int ascii = (int)s[i];
        if(v[ascii] == 1000)
        {
            v[ascii] = s[i] - t[i];
            flag = true;
        }
        else if(v[ascii] != s[i] - t[i])
        {
            flag = false;
            break;
        }
    }
    // Emptying the vector again
    for(int i=0;i<150;i++) v[i] = 1000;
    // Checking isomorphic from the perspective of t
    for(int i=0;i<t.length();i++)
    {
        int ascii = (int)t[i];
        if(v[ascii] == 1000)
        {
            v[ascii] = t[i] - s[i];
            flag = true;
        }
        else if(v[ascii] != t[i] - s[i])
        {
            flag = false;
            break;
        }
    }
    if(flag == true) cout<<s<<" and "<<t<<" are isomorphic";
    else cout<<s<<" and "<<t<<" are not isomorphic";
    return 0;
}
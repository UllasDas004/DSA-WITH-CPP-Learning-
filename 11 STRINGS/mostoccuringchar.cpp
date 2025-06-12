#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    cout<<"Enter first string:- ";
    string s;
    cin>>s;
    int max = 0;
    for(int i=0;i<s.size();i++)
    {
        int count = 1;
        for(int j=i+1;j<s.size();j++)
        {
            if(s[i] == s[j]) count++;
        }
        if(count>max) max = count;
    }

    for(int i=0;i<s.size();i++)
    {
        int count = 1;
        for(int j=i+1;j<s.size();j++)
        {
            if(s[i] == s[j]) count++;
        }
        if(count == max)
        cout<<s[i]<<" "<<max<<endl;
    }
    return 0;
}
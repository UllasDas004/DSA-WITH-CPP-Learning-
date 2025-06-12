#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a line:- ";
    getline(cin,s);
    vector <string> v;
    string temp;
    stringstream ss(s);
    while(ss>>temp)
    v.push_back(temp);
    sort(v.begin(),v.end());
    int maxcount = 1;
    int count = 1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i] == v[i-1]) count++;
        else count = 1;
        if(maxcount<count) maxcount = count;
    }
    count = 1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i] == v[i-1]) count++;
        else count = 1;
        if(maxcount==count) 
        cout<<v[i]<<" "<<maxcount<<endl;
    }
    return 0;
}
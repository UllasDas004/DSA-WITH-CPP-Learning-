#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void subset(string ans,string original,vector<string>& v,int idx,bool flag)
{
    if(idx == original.length())
    {
        v.push_back(ans);
        return;
    }
    if(idx == original.length()-1)   // Checking the string length is 1 or not...if 1 that means there is no next character so return
    {
        if(flag == true) subset(ans+original[idx],original,v,idx+1,true);
        subset(ans,original,v,idx+1,true);
    }
    else if(original[idx] == original[idx+1])    // Checking duplicate characters if yes then sending false in the not adding call   
    {
        if(flag == true) subset(ans+original[idx],original,v,idx+1,true);
        subset(ans,original,v,idx+1,false);
    }
    else                                        // Else regular calling
    {
        if(flag == true) subset(ans+original[idx],original,v,idx+1,true);
        subset(ans,original,v,idx+1,true);
    }
    return ;
}
int main()
{
    string str;
    // Duplicate character string
    cout<<"Enter a string:- ";
    cin>>str;
    vector<string> v;
    sort(str.begin(),str.end());
    subset("",str,v,0,true);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
    return 0;
}
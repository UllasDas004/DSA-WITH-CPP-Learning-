#include<iostream>
#include<string>
using namespace std;
void subset(string ans,string original,int idx)
{
    if(idx == original.length())
    {
        cout<<ans<<" ";
        return;
    }
    subset(ans,original,idx+1);
    subset(ans+original[idx],original,idx+1);
}
int main()
{
    string str;
    // Not duplicate character string
    cout<<"Enter a string:- ";
    cin>>str;
    subset("",str,0);
    return 0;
}
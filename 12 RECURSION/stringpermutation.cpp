#include<iostream>
#include<string>
using namespace std;
void permutation(string ans,string original)
{
    if(original.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<original.length();i++)
    permutation(ans+original[i],original.substr(0,i)+original.substr(i+1));
    return;
}
int main()
{
    string str;
    cout<<"Enter a string:- ";
    cin>>str;
    permutation("",str);
    return 0;
}
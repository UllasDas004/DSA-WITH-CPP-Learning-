#include<iostream>
using namespace std;
void removeachar(string ans,string original,char ch,int idx)
{
    if(idx == original.length())
    {
        cout<<ans;
        return;
    }
    if(original[idx] == ch) removeachar(ans,original,ch,idx+1);
    else removeachar(ans+original[idx],original,ch,idx+1);
}
int main()
{
    cout<<"Enter a string:- ";
    string str;
    getline(cin,str);
    cout<<"Enter the character:- ";
    char ch;
    fflush(stdin);
    cin>>ch;
    removeachar("",str,ch,0);
    return 0;
}
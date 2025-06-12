#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "abcdef";
    cout<<s<<endl;
    cout<<s.substr(2)<<endl; //s[2] -> s[end]
    cout<<s.substr(2,3)<<endl; // s[first index] -> s[first index + last index]
}
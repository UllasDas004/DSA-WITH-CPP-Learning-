#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
void permutations(string& s,int i)
{
    if(i == s.length()-1)
    {
        cout<<s<<" ";
        return;
    }
    unordered_set<char> st;
    for(int j=i;j<s.length();j++)
    {
        if(st.count(s[j])) continue; //PRUNING STEP
        st.insert(s[j]);
        swap(s[i],s[j]);
        permutations(s,i+1);
        swap(s[i],s[j]); // BACKTRACKING
    }
}
int main()
{
    string s;
    cin>>s;
    permutations(s,0);
    return 0;
}
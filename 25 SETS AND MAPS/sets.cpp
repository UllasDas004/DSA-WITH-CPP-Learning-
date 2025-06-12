#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(2);
    s.insert(1);
    s.insert(5);
    for(int ele : s)
    cout<<ele<<" ";
    cout<<endl;
    int target = 40;
    if(s.find(target) != s.end()) cout<<"Exists!"<<endl;
    else cout<<"Does not exists!"<<endl;
    return 0;
}
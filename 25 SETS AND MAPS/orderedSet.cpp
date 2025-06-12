#include<iostream>
#include<set>
using namespace std;
int  main()
{
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(2);
    for(int ele : s)
    cout<<ele<<" ";
    cout<<endl;
    return 0;
}
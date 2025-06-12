#include<iostream>
#include<unordered_map>
using namespace std;
int  main()
{
    unordered_map<string,int> mp;
    pair<string,int> p1;
    p1.first = "Ullas";
    p1.second = 33;
    mp.insert(p1);
    mp["Debrup"] = 56;
    mp["Souvik"] = 48;
    for(auto ele : mp)
    cout<<ele.first<<" "<<ele.second<<endl;
    mp.erase("Debrup");
    for(auto ele : mp)
    cout<<ele.first<<" "<<ele.second<<endl;
    return 0;
}
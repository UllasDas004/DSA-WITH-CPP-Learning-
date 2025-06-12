#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> mp;
    mp.insert({"Ullas",33});
    mp.insert({"Debrup",56});
    mp.insert({"Souvik",48});
    for(auto ele : mp)
    cout<<ele.first<<" "<<ele.second<<endl;
    return 0;
}

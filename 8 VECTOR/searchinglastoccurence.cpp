#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int n;
    cout<<"Enter the size of vector:- ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cout<<"Enter number"<<i+1<<":- ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter the target number:-";
    int target;
    cin>>target;
    int idx;
    bool flag = false;
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i] == target)
        {
            idx = i;
            flag = true;
            break;
        }
    }
    if(flag == true) cout<<target<<" is found at index "<<idx<<".";
    else cout<<target<<" not found.";
    return 0;
}
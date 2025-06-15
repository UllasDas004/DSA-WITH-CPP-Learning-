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
    cout<<"Enter the target sum:- ";
    int target;
    cin>>target;
    int idx1=-1,idx2=-1;
    for(int i=0;i<v.size()-1;i++)
    {
        bool flag = false;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]+v[j] == target)
            {
                idx1 = i;
                idx2 = j;
                flag = true;
                break;
            }
        }
        if(flag == true) cout<<v[idx1]<<" + "<<v[idx2]<<" = "<<target<<endl;
    }
    if(idx1 == -1 || idx2 == -1) cout<<"Not happening.";
    return 0;
}
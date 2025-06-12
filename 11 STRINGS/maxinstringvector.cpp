#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number the numbers:- ";
    cin>>n;
    vector <string> nums;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        string s;
        cin>>s;
        nums.push_back(s);
    }
    int max = stoi(nums[0]);
    string maxs = nums[0];
    for(int i=0;i<n;i++)
    {
        int x = stoi(nums[i]);
        if(x>max) 
        {
            max = x;
            maxs = nums[i];
        }
    }
    cout<<maxs;
    return 0;
}
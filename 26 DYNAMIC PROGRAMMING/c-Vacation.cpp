#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> hp(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        cin>>hp[i][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            int mx = INT_MIN;
            for(int k=0;k<3;k++)
            {
                if(k == j) continue;
                mx = max(mx,hp[i-1][k]);
            }
            hp[i][j] += mx;
        }
    }
    int ans = max(hp[n-1][0],max(hp[n-1][1],hp[n-1][2]));
    cout<<ans<<endl;
    return 0;
}
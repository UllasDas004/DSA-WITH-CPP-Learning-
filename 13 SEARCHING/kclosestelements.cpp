#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int diffcomp(int a,int b,int x)
    {
        int diff1 = a-x,diff2 = b-x;
        if(a<x) diff1 = x-a;
        if(b<x) diff2 = x-b;
        if(diff1>diff2) return b;
        else return a;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans(k);
        if(x<arr[0])
        {
            for(int i=0;i<k;i++)
            ans[i] = arr[i];
            return ans;
        }
        if(x>arr[n-1])
        {
            for(int i=n-k,j=0;i<=n-1;i++,j++)
            ans[j] = arr[i];
            return ans;
        }
        int lo=0,hi=n-1;
        int idx=-1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(arr[mid] == x)
            {
                idx = mid;
                break;
            }
            else if(arr[mid]<x) lo = mid+1;
            else hi = mid-1;
        }
        if(idx == -1)
        {
            int lb = hi;
            int ub = lo;
            for(int i=0;i<k;i++)
            {
                if(lb == -1)
                {
                    ans[i] = arr[ub];
                    ub++;
                }
                else if(ub == n)
                {
                    ans[i] = arr[lb];
                    lb--;
                }
                else
                {
                    int c = diffcomp(arr[lb],arr[ub],x);
                    ans[i] = c;
                    if(c == arr[lb]) lb--;
                    else ub++;
                }
            }
        }
        else
        {
            int lb = idx - 1;
            int ub = idx + 1;
            ans[0] = arr[idx];
            for(int i=1;i<k;i++)
            {
                if(lb == -1)
                {
                    ans[i] = arr[ub];
                    ub++;
                }
                else if(ub == n)
                {
                    ans[i] = arr[lb];
                    lb--;
                }
                else
                {
                    int c = diffcomp(arr[lb],arr[ub],x);
                    ans[i] = c;
                    if(c == arr[lb]) lb--;
                    else ub++;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
int main()
{
    int n;
    cout<<"Enter size of array:- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter in ascending number."<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter number"<<i+1<<":- ";
        cin>>arr[i];
    }
    int x;
    cout<<"Enter target element:- ";
    cin>>x;
    int k;
    cout<<"Enter how many elements you want:- ";
    cin>>k;
    vector<int> ans = findClosestElements(arr,k,x);
    cout<<"closest elements to "<<x<<"."<<endl;
    for(int i=0;i<k;i++)
    cout<<ans[i]<<" ";
    return 0;
}
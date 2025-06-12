#include<iostream>
#include<vector>   
#include<queue>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of ropes:- ";
    cin >> n;
    vector<int> ropes(n);
    cout<<"Enter the lengths of the ropes\n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter rope length"<<i+1<<":- ";
        cin>>ropes[i];
    }
    int cost = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++) pq.push(ropes[i]);
    while(pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cost += (a + b);
        pq.push(a+b);
    }
    cout<<"The minimum cost to connect all the ropes is "<<cost<<endl;
    return 0;
}
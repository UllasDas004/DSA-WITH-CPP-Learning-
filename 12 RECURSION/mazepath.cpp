#include<iostream>
using namespace std;
int maze(int sr,int sc,int er,int ec,string s)
{
    if(sr>er || sc>ec) return 0;
    if(sr == er && sc == ec) 
    {
        cout<<s<<endl;
        return 1;
    }
    int rightWays = maze(sr,sc+1,er,ec,s+'R');
    int downWays = maze(sr+1,sc,er,ec,s+'D');
    int totalWays = rightWays + downWays;
    return totalWays;
}
int main()
{
    int m,n;
    cout<<"Enter the number of rows:- ";
    cin>>m;
    cout<<"Enter the number of columns:- ";
    cin>>n;
    cout<<"Total number of ways possible "<<maze(1,1,m,n,"");
    return 0;
}
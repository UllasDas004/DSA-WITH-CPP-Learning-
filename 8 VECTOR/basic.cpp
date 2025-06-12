#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;  // You need not to mention size.....Size of this vector is ZERO initially
    cout<<"SIZE "<<v.size()<<" CAPACITY "<<v.capacity()<<endl;
    v.push_back(6); // Creates an array of size 1   capacity of this vector is now 1 and it is full now
    cout<<"SIZE "<<v.size()<<" CAPACITY "<<v.capacity()<<endl;
    v.push_back(0); // Doubles the capacity from 1 to 2(DOUBLE OF PREVIOS SIZE)     capacity is full now
    cout<<"SIZE "<<v.size()<<" CAPACITY "<<v.capacity()<<endl;
    v.push_back(7); // Doubles the capacity from 2 to 4(DOUBLE OF PREVIOS SIZE)     capacity is not full(3/4)
    cout<<"SIZE "<<v.size()<<" CAPACITY "<<v.capacity()<<endl;
    v.push_back(4); // Does not increase the capacity as it is not ful previosly    capacity is now full(4/4)
    cout<<"SIZE "<<v.size()<<" CAPACITY "<<v.capacity()<<endl;
    //Displaying is just like arrays
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    v.pop_back(); // Deletes element from back and updates the size from 4 to 3 but the capacity remains SAME
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> pq; // max heap by default
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(30);
    pq.push(-2);
    pq.push(0);
    cout<<pq.top()<<endl;   // prints the maximum element (top of the heap) (30)
    pq.pop();   // removes the maximum element
    cout<<pq.top()<<endl;   // prints the new maximum element   (20)
    
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(30);
    cout<<minHeap.top()<<endl;   // prints the maximum element (top of the heap) (30)
    minHeap.pop();   // removes the maximum element
    cout<<minHeap.top()<<endl;
}
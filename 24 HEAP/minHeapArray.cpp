#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class minHeap
{
    public:
    int arr[100];
    int idx;
    minHeap()
    {
        idx = 1;
    }
    int size()
    {
        return idx-1;
    }
    int top()
    {
        return arr[1];
    }
    void push(int val)
    {
        arr[idx] = val;
        int i = idx;
        idx++;
        while(i>1 && arr[i/2] > arr[i])
        {
            swap(arr[i/2],arr[i]);
            i /= 2;
        }
    }
    void pop()
    {
        idx--;
        arr[1] = arr[idx];
        int i = 1;
        while(true)
        {
            int left = 2*i,right = 2*i+1;
            if(left>=idx) break;
            if(right>=idx)
            {
                if(arr[i] > arr[left]) swap(arr[i],arr[left]);
                break;
            }
            if(arr[left]<arr[right])
            {
                if(arr[i] > arr[left])
                {
                    swap(arr[i],arr[left]);
                    i = left;
                }
                else break;
            }
            else
            {
                if(arr[i] > arr[right])
                {
                    swap(arr[i],arr[right]);
                    i = right;
                }
                else break;
            }
        }
    }
    void display()
    {
        for(int i=1;i<idx;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    minHeap pq;
    pq.push(10);
    pq.push(20);
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    pq.push(5);
    pq.display();
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    pq.push(15);
    pq.display();
    cout<<pq.top()<<endl;
    pq.pop();
    pq.display();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    return 0;
}
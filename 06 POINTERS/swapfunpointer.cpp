#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a,b;
    cout<<"Enter first number:- ";
    cin>>a;
    cout<<"Enter second number:- ";
    cin>>b;
    cout<<"Before swapping"<<endl<<"a = "<<a<<" , b = "<<b<<endl;;
    swap(&a,&b);
    cout<<"After swapping"<<endl<<"a = "<<a<<" , b = "<<b<<endl;
    return 0;
}
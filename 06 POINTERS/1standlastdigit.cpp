#include<iostream>
using namespace std;
void find(int* num,int* fd,int* ld)
{
    *ld = *num%10;
    for(int a=*num;a>0;a/=10)
    *fd = a;
}
int main()
{
    int num;
    cout<<"Enter a number:- ";
    cin>>num;
    int fd,ld;
    find(&num,&fd,&ld);
    cout<<"First digit of "<<num<<" is "<<fd<<endl;
    cout<<"Last digit of "<<num<<" is "<<ld;
    return 0;
}
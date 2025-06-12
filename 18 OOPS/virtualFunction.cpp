#include<iostream>
using namespace std;
class A
{
    public:
    virtual void show() // RUNTIME BINDING
    {
        cout<<"Show of A!\n";
    }
};
class B : public A
{
    public:
    void show() // COMPILE TIME BINDING
    {
        cout<<"Show of B!\n";
    }
};
int main()
{
    A *a;
    a = new B;
    a->show();
    a = new A;
    a->show();
    return 0;
}
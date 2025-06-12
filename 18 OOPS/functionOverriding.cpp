#include<iostream>
using namespace std;
class A
{
    public:
    void show()
    {
        cout<<"Show of A!\n";
    }
};
class B : public A
{
    public:
    void show()
    {
        cout<<"Show of B!\n";
    }
};
int main()
{
    A a;
    B b;
    a.show();
    b.show();
    b.A::show();
    A *x;
    B y;
    x = &y;
    x->show();
    y.show();
    return 0;
}
#include<iostream>
using namespace std;
class A
{
    public:
    virtual void show() = 0; //PURE VIRTUAL FUNCTION
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
    B b;
    b.show();
    return 0;
}
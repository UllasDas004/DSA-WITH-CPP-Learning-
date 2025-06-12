#include<iostream>
using namespace std;
class A
{
    private:
    int a_private;
    protected:
    int a_protected = 10;
    public:
    int a_public;
};
class B : public A
{
    public:
    void show()
    {
        cout<<a_protected<<endl;
    }
    int b_public;
};
int main()
{
    A a;
    a.a_public = 10;
    B b;
    b.b_public = 5;
    b.show();
    return 0;
}
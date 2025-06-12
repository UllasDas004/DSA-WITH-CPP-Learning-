#include<iostream>
using namespace std;
class Bike
{
    public:
    int tyreSize,engine;
    Bike (int tyreSize,int engine) // Constructor
    {
        this->tyreSize = tyreSize;
        this->engine = engine;
        cout<<"Constructor has been called"<<endl;
    }
    ~Bike () // Destructor
    {
        cout<<"Destructor has been called"<<endl;
    }
    Bike (Bike &b)
    {
        this->tyreSize = b.tyreSize;
        this->engine = b.engine;
        cout<<"Copy Constructor has been called"<<endl;
    }
};
int main()
{
    if(true)
    {
        Bike bmw(20,1000);
        cout<<bmw.tyreSize<<" "<<bmw.engine<<endl;
    }
    Bike tvs(12,100);
    Bike honda(13,150);
    Bike royalEnfield(15,350);
    cout<<tvs.tyreSize<<" "<<tvs.engine<<endl;
    cout<<honda.tyreSize<<" "<<honda.engine<<endl;
    cout<<royalEnfield.tyreSize<<" "<<royalEnfield.engine<<endl;
    Bike bajaj(tvs);
    cout<<bajaj.tyreSize<<" "<<bajaj.engine<<endl;
    return 0;
}
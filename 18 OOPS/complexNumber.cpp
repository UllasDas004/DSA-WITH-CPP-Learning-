#include<iostream>
using namespace std;
class ComplexNumber
{
    private:
    float real,imaginary;
    public:
    // SETTER
    float setComplex(float real,float imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    // GETTER
    float getReal()
    {
        return real;
    }
    float getImaginary()
    {
        return imaginary;
    }
    // OPERATOR OVERLOADING
    ComplexNumber operator +(ComplexNumber &c1)
    {
        ComplexNumber c2;
        c2.real = c1.real + this->real;
        c2.imaginary = c1.imaginary + this->imaginary;
        return c2;
    }
    ComplexNumber operator -(ComplexNumber &c1)
    {
        ComplexNumber c2;
        c2.real = c1.real - this->real;
        c2.imaginary = c1.imaginary - this->imaginary;
        return c2;
    }
    ComplexNumber operator *(ComplexNumber &c1)
    {
        ComplexNumber c2;
        c2.real = c1.real*this->real - c1.imaginary*this->imaginary;
        c2.imaginary = c1.real*this->imaginary + c1.imaginary*this->real;
        return c2;
    }
    ComplexNumber operator /(ComplexNumber &c1)
    {
        ComplexNumber c2;
        c2.real = c1.real*this->real + c1.imaginary*this->imaginary;
        c2.imaginary = c1.real*this->imaginary - c1.imaginary*this->real;
        float denom = this->real*this->real + this->imaginary*this->imaginary;
        c2.real /= denom;
        c2.imaginary /= denom;
        return c2;
    }
    void show()
    {
        cout<<this->real<<" + i"<<this->imaginary; 
    }

};
int main()
{
    float real1,imaginary1,real2,imaginary2;
    char op,plus,i;
    cout<<"Enter expression(ex:-a+ib+c+id)."<<endl;
    cin>>real1>>plus>>i>>imaginary1>>op>>real2>>plus>>i>>imaginary2;
    ComplexNumber c1,c2;
    c1.setComplex(real1,imaginary1);
    c2.setComplex(real2,imaginary2);
    ComplexNumber ans;
    if(op == '+') ans = c1 + c2;
    else if(op == '-') ans = c1 - c2;
    else if(op == '*') ans = c1 * c2;
    else if(op == '/') ans = c1 / c2;
    c1.show();
    cout<<" + ";
    c2.show();
    cout<<" = ";
    ans.show();
    return 0;
}
/*【问题描述】

请定义一个复数类，将+/-运算符重载为友元函数，实现复数与复数的加减及复数与浮点数的加减。

请根据给定的main函数，设计Complex类。

【样例输出】

a+b=(4)+(3i)

a-b=(2)+(5i)

a+100=(103)+(4i)

a-2.5=(0.5)+(4i)

100+a=(103)+(4i)

2.5-a=(-0.5)+(-4i)
*/

#include <iostream>
using namespace std;
class Complex
{
public:
friend Complex operator +(Complex &a,Complex &b);
friend Complex operator +(Complex &a,double b);
friend Complex operator +(Complex &a,int b);
friend Complex operator +(double b,Complex &a);
friend Complex operator +(int b,Complex &a);

friend Complex operator -(Complex &a,Complex &b);
friend Complex operator -(Complex &a,double b);
friend Complex operator -(Complex &a,int b);
friend Complex operator -(double b,Complex &a);
friend Complex operator -(int b,Complex &a);

Complex(float a=0,float b=0);
void print();
private:
float real,imag;
};
Complex::Complex(float a,float b)
{
real=a;
imag=b;
}
Complex operator +(Complex &a,Complex &b)
{
Complex c;
c.real=a.real+b.real;
c.imag=a.imag+b.imag;
return c;
}

Complex operator +(Complex &a,double b)
{
Complex c;
c.real=a.real+b;
c.imag=a.imag;
return c;

}

Complex operator +(Complex &a,int b)
{
Complex c;
c.real=a.real+b;
c.imag=a.imag;
return c;

}
Complex operator +(double b,Complex &a)
{
Complex c;
c.real=a.real+b;
c.imag=a.imag;
return c;

}
Complex operator +(int b,Complex &a)
{
Complex c;
c.real=a.real+b;
c.imag=a.imag;
return c;

}

Complex operator -(Complex &a,Complex &b)
{
Complex c;
c.real=a.real-b.real;
c.imag=a.imag-b.imag;
return c;
}

Complex operator -(Complex &a,double b)
{
Complex c;
c.real=a.real-b;
c.imag=a.imag;
return c;

}

Complex operator -(Complex &a,int b)
{
Complex c;
c.real=a.real-b;
c.imag=a.imag;
return c;

}
Complex operator -(double b,Complex &a)
{
Complex c;
c.real=b-a.real;
c.imag=(-a.imag);
return c;

}
Complex operator -(int b,Complex &a)
{
Complex c;
c.real=b-a.real;
c.imag=(-a.imag);
return c;

}

void Complex::print()
{
cout <<'('<<real<<')'<<'+'<<'('<<imag<<'i'<<')'<<endl;
}

int main()
{
    Complex a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;
    c=100+a;
    cout<<"100+a=";
    c.print();
    cout<<endl;
    c=2.5-a;
    cout<<"2.5-a=";
    c.print();
    cout<<endl;
    return 0;
}



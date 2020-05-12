/*【问题描述】

请定义一个复数类，将+/-运算符重载为成员函数，实现复数与复数的加减及复数与浮点数的加减。

请根据给定的main函数，设计Complex类。

【样例输出】

a+b=4+3i

a-b=2+5i

a+100=103+4i

a-2.5=0.5+4i

*/
#include <iostream>
using namespace std;

class Complex
{
public:
Complex operator +(Complex &b);
Complex operator +(double b);
Complex operator +(int b);
Complex operator -(Complex &b);
Complex operator -(double b);
Complex operator -(int b);
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
Complex Complex::operator +(Complex &b)
{
Complex c;
c.real=real+b.real;
c.imag=imag+b.imag;
return c;
}

Complex Complex::operator +(double b)
{
Complex c;
c.real=real+b;
c.imag=imag;
return c;

}

Complex Complex::operator +(int b)
{
Complex c;
c.real=real+b;
c.imag=imag;
return c;

}
Complex Complex::operator -(Complex &b)
{
Complex c;
c.real=real-b.real;
c.imag=imag-b.imag;
return c;
}
Complex Complex::operator -(double b)
{Complex c;
c.real=real-b;
c.imag=imag;
return c;
}
Complex Complex::operator -(int b)
{Complex c;
c.real=real-b;
c.imag=imag;
return c;
}

void Complex::print()
{
cout <<real<<'+'<<imag<<'i'<<endl;
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

    return 0;
}



#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

const double PI=3.1415926;
//请在此处完善类的设计
class cylinder
{
    public:
    void init (double rh,double rr);
    double getvolumn ();
    double getarea();
    private:
    double r,h;    
};
void cylinder:: init(double rh,double rr)
{
    h=rh;
    r=rr;
}
double cylinder:: getvolumn()
{
    return (r*r*PI*h);
}
double cylinder:: getarea()
{
    return (r*r*PI*2+2*r*PI*h);
}


int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can;

    can.init(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}




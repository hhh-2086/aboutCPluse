/*【问题描述】

定义Boat和Car两个类，两者都有私有成员weight属性，定义两者的一个友员函数totalweight(),计算两个类的对象的重量和。

请根据给定的main函数和totalweight()函数的定义，完善Boat和Car两个类。

【样例输出】

300
*/
#include <iostream>
using namespace std;
//请在这里补充类Boat和Car的定义
class Car;
class Boat
{
    friend int totalweight(Boat& b,Car& c);
    public:
        Boat (int w);
    private:
        int weight;
};
class Car
{
    friend int totalweight(Boat& b,Car& c);
    public:
        Car (int w);
    private:
        int weight;
};
Boat::Boat(int w)
{weight=w;}
Car::Car(int w)
{weight=w;}

int totalweight(Boat& b,Car& c)
{
    return b.weight+c.weight;
}
int main()
{
    Boat b(100);
    Car c(200);
    cout<<totalweight( b, c)<<endl;
    return 0;
}



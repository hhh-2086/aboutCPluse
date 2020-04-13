/*【问题描述】

某工厂使用一种圆柱形的铁桶来运输色拉油，但是关于该油桶的容量已经模糊，现在工人们测得了油桶直径和高（由键盘输入），请帮工人们计算一下油桶容量和制造该油桶需要的铁皮面积。

注意这个油桶是有盖的。铁皮的厚度忽略不计。

请设计一个类cylinder，该类具有私有成员 r和h，r表示半径，h表示高。

该类还有4个公有成员，分别为

1、求解体积函数getvolumn()

2、求解表面积函数 getarea()

3、构造函数，作用为给私有成员 r和h传递初始化值，并输出“构造函数被调用”。

4、析构函数，该函数暂时不做额外处理工作，但需要输出“析构函数被调用”



PI的值为3.1415926;



main 函数定义如下：

int main()

{

    double d,h;

    cin>>d>>h;

    cylinder can(h,d/2);

    cout<<fixed<<setprecision(6);

    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;

    cout<<"铁皮的面积是"<<can.getarea()<<endl;

}



【输入形式】

输入包括一行，有两个浮点数，分别表示油桶的直径和高，中间用空格空开
【输出形式】

输入包括两行，有两个浮点数，分别为油桶的容量和铁皮面积，保留6位小数

【样例输入】

2.5 3

【样例输出】

油桶的容积是14.726215

铁皮的面积是33.379421
*/
#include<iostream>
#include<iomanip>
using namespace std;
const double PI=3.1415926;
class cylinder
{
public:
	cylinder(double fh,double fr);
	double getvolumn();
	double getarea();
	~cylinder();
private:
	double r,h;
};

cylinder::cylinder(double fh,double fr)
{
	r=fr;
	h=fh;
	cout<<"构造函数被调用"<<endl;
}
double cylinder::getvolumn()
{
	return PI*r*r*h;
}
double cylinder::getarea()
{
	return 2*PI*r*(r+h);
}
cylinder::~cylinder()
{
	cout<<"析构函数被调用"<<endl;
}



int main()

{

    double d,h;

    cin>>d>>h;

    cylinder can(h,d/2);

    cout<<fixed<<setprecision(6);

    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;

    cout<<"铁皮的面积是"<<can.getarea()<<endl;

}



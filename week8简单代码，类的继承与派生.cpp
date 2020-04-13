/*【问题描述】

编写一个Shape类并派生出Circle类和Rectangle类，观察运行机制。

shape类有以下成员

1）私有成员m_ID

2）公有getter和setter

3）计算面积函数getArea()，返回0;

4）构造与析构函数

Circle类从shape类继承，并派生以下成员

1）私有成员r

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数

Rectangle类从shape类继承，并派生以下成员

1）私有成员h,w

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数


【样例输出】

Shape constructor called:1

Shape constructor called:2

Circle constructor called:2

Shape constructor called:3

Rectangle constructor called:3

Shape的面积0

Circle的面积48

Rectangle的面积20

Rectangle destructor called:3

Shape destructor called:3

Circle destructor called:2

Shape destructor called:2

Shape destructor called:1
*/
#include <iostream>
using namespace std;
const int pi=3.14159;
class Shape
{
	private:
		int m_ID;
	public:
		int getID(){return m_ID;}
		void setID(int n){m_ID=n;}
		int getArea(){return 0;}
		Shape(int n)
		{
			m_ID=n;
			cout<<"Shape constructor called:"<<m_ID<<endl; 
		}
		~Shape(){cout<<"Shape destructor called:"<<m_ID<<endl;}	
};
class Circle:public Shape
{
	private:
		int r;
	public:
		int getr(){return r;}
		void setr(int n){r=n;	}
		float getArea(){return pi*r*r;}
		Circle(int r,int ID):Shape(ID)
		{
			this->r=r;
			cout<<"Circle constructor called:"<<getID()<<endl;
		}
		~Circle(){cout<<"Circle destructor called:"<<getID()<<endl;}
};
class Rectangle:public Shape
{
	private:
		int h,w;
	public:
		int geth(){return h;}
		void seth(int n){n=h;}
		int getw(){return w;}
		void setw(int n){n=w;}	
	int getArea(){return h*w;}
	Rectangle(int h,int w,int ID):Shape(ID)
	{
		this->h=h;
		this->w=w;
		cout<<"Rectangle constructor called:"<<getID()<<endl;	
	}
	~Rectangle(){cout<<"Rectangle destructor called:"<<getID()<<endl;}		
};

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}


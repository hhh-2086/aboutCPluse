/*【问题描述】

请定义一个Point类，将前置++和后置++运算符重载为成员函数，实现成员变量m_x和m_y的加一操作。

同时重载流插入运算符，实现对Point类对象的格式化输出。例如

Point p；

cout<<p;

输出结果为：

（0,0）



请根据给定的main函数，设计Point类。

【样例输出】

(1,3)

(1,3)

(3,5)
*/
#include <iostream>
using namespace std;
class Point
{
private:
int m_x,m_y;
public:
Point(int a,int b){m_x=a;m_y=b;}
Point& operator ++();
Point operator ++(int); 
int getx(){return m_x;}
int gety(){return m_y;}

};
Point& Point::operator ++()
{m_x++;
m_y++;
return *this;}
Point Point::operator ++(int)
{Point c(0,0);
c.m_x=m_x;
c.m_y=m_y;
m_x++;
m_y++;
return c;
}
//ostream& operator <<(ostream& output,Point z)
//{
//<<'('<<z.getx()<<','<<z.gety()<<')'<<endl;
// output;
//}
ostream &operator<<(ostream& s,Point z)
{
return s<<'('<<z.getx()<<','<<z.gety()<<')'<<endl;
}

int main()
{
    Point a(1,3);
    cout<<a;
    cout<<a++;
    cout<<++a;
    return 0;
}


/*
1. 模板数组类（支持分数和浮点数的求和计算）
【问题描述】

封装一个模板数组类Array，支持以下操作：

1. 构造函数Array(int n)，将数组初始化为n个存储空间，建议使用vector；

2. 函数input(int n)，使用插入运算符<<读取数据，最多读取n个元素，但不能超过数组存储空间的上限；

3. 重载下标运算符，返回数组的元素。

 

封装一个分数类Fract，用来处理分数功能和运算，能支持你的Array类使用。

1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。

提示：分数化简有专门的算法，可自行调研

2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。

3. 在分数类上重载+=运算符，进行分数的加法运算。


【输入形式】

输入为两部分，分别是一组实数测试样例和一组分数测试样例。

这两组测试样例都以正整数n，且n小于1000，n表示需要输入n个实数（或分数）。

测试样例的第二行开始为n个实数（或分数）。其中每个分数输入为两个整数n、m，表示分数n/m。


【输出形式】

第一部分输出一个实数，是第一组测试样例之和；第二部分输出一个分数，是第二组测试样例之和。

分数输出时为最简形式，负号只会出现在最前面，若分母为1或分子为0，则只输出一个整数，即分子部分，而没有“/”和分母部分。


【样例输入】

4

6 8 7 5 

9 

1 3 20 -15 80 150 -9 1 6 6 12 16 -33 -48 6 11 0 -10



【样例输出】

26 

-17117/2640

*/
#include <iostream>
#include <vector>
using namespace std;

int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;}

template <typename T>class Array
{
public:
	Array(int n);

	T operator [](int a){return data[a];}
	void input (int n);
private:
	
	vector<T>data;

};
template <typename T>Array<T>::Array(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		T a;
		data.push_back(a);
	}
}
template <typename T>void Array<T>::input(int n)
{
	int i=0;
	for(i;i<n;i++)cin>>data[i];
}

class Fract
{
	friend int gcd(int x,int y);
	friend istream&operator >>(istream &s,Fract &z);
public:
	Fract(int a=0,int b=1);
	void show();
	Fract operator +=(Fract a);
private:
	int num1,num2;
};
Fract::Fract(int a,int b)
{
	if(a)
	{
	int flag1=0,flag2=0;
	int t;
	if(a<0){flag1=1;a=-a;}
	if(b<0){flag2=1;b=-b;}
	t=gcd(a,b);
	a=a/t;
	b=b/t;
	if(flag1&&flag2||flag1==0&&flag2==0){num1=a;num2=b;}
	else {num1=-a;num2=b;}
	}
	else
	{num1=a;
	num2=b;}
}
void Fract::show()
{
  if(num1==0||num2==1)cout<<num1<<endl;
else
  cout<<num1<<'/'<<num2<<endl;
}
Fract Fract::operator+=(Fract a)
{
	Fract k;
	if(num1&&a.num1)
	{
	Fract k1(0,1),k2(0,1);
	k1.num1 = num1*a.num2;
	k2.num1 = num2*a.num1;
	k.num1 = k1.num1+k2.num1;
	k.num2 = num2*a.num2;

	Fract kk(k.num1,k.num2);
	k = kk;

	}
	else if(num1)
	 k= *this;
	else
	k=a;
*this = k;
return k;

}

istream &operator >>(istream &s,Fract &z)
{
	int a,b;
	s>>a>>b;
	Fract k(a,b);
	z = k;
	
	return s;
}

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
















/*
【问题描述】请编写一个程序，实现如下功能

1、定义结构体student, 包括stu_id,score 2个变量。其中stu_id是一个short型变量，score为short型变量。

2、从键盘输入学生个数n及n个学生的数据，存储在new创建的数组a中

3、使用write函数，以二进制形式，将a数组中存放的n个学生一次写入out.txt文件中（不要使用循环）

4、使用read函数，以二进制形式，使用循环方式，从out.txt中每次读出一个学生信息，存储于new创建的数组b中

5、使用write函数，以文本形式，将b数组中存放的n个学生一次写入out.txt文件中，要求添加到文件末尾（不要使用循环）

【输入形式】

输入第一行是整数，表示有n个学生

输入第2到n+1行是学生信息，每行表示一个学生的stu_id,score

【输出形式】

输出文件名：out.txt，其中包括2次输出信息

【输入范例】

2

1011 90

1012 68

【输出范例】

无
*/
#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short stu_id,stu_score;
};
int main()
{
	int n,i;
	cin>>n;
	student *a=new student[n];
	for(i=0;i<n;i++)
		cin>>a[i].stu_id>>a[i].stu_score;
	ofstream out("out.txt",ios::binary|ios::out);
	out.write(reinterpret_cast<char*>(a),n*4);
	out.close();
	delete[] a;
	ifstream in("out.txt",ios::binary|ios::in);
	student *b=new student[n];
	for(i=0;i<n;i++)
	{
		in.read(reinterpret_cast<char*>(&b[i].stu_id),2);
		in.read(reinterpret_cast<char*>(&b[i].stu_score),2);
	}
	in.close();
	ofstream out2("out.txt",ios::app|ios::out);
	out2.write(reinterpret_cast<char*>(b),n*4);
	out2.close();
	delete[] b;
	return 0;
}

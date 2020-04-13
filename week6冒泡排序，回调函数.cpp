/*【问题描述】

回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。

本题希望通过回调函数，定义一个冒泡排序函数，可以根据函数指针指向不同的比较函数，分别实现从大到小和从小到大的排序。

希望通过这道题目，可以帮助大家理解函数指针与回调函数。本题较为简单，仅能处理整数的不同排序。有能力的同学，可以进一步尝试对不同类型的数据（包括字符串、浮点型）利用一个bubble函数进行排序。



【输入形式】

无
【输出形式】

输出包括两行，分别为从小到大的输出和从大到小的输出。



【样例输出】

0 1 2 3 4 5 6 7 8 9

9 8 7 6 5 4 3 2 1 0

*/
//实现功能：既能排序整型数，也可以排序字符串

#include <iostream>
#include <cstring>
using namespace std;

int cmpGT(const int *p1, const int *p2)
{
//实现两数比较，如果大于，则返回1，等于则返回0，小于则返回-1
if(*p1>*p2)return 1;
else if(*p1<*p2)return (-1);
else return 0;

}
int cmpLT(const int *p1, const int *p2)
{
//实现两数比较，如果大于，则返回-1，等于则返回0，小于则返回1
if(*p1>*p2)return (-1);
else if(*p1<*p2)return (1);
else return 0;


}

void swap(int *p1, int *p2)
{
//实现两个整形变量的值交换
int t;
t=*p1;
*p1=*p2;
*p2=t;

}

void bubble(int *base,  int(*cmp)(const int *, const int *))
{
//请在这里补充冒泡排序，请根据main函数中对bubble函数的调用，分析形参的作用
int i,j;
for(i=0;i<9;i++)
    for(j=0;j<9;j++)
        if((*cmp)((base+j),(base+j+1))==1)
            swap(base+j,base+j+1);


}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	bubble(arr,  cmpGT);
	for (i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	bubble(arr,  cmpLT);
	for (i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
	return 0;
}


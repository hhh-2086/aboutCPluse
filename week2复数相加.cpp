/*【问题描述】请编写一个函数，实现两个复数相减。并编写main函数调用该函数。
【输入形式】输入包括4个浮点数，分别是第一个数的实部和虚部，以及第二个数的部和虚部，每个数字之间有一个空格

【输出形式】两个数，分别是差的实部和虚部，保留2位小数，中间用1个空格空开

【样例输入】

3 2 6 5
【样例输出】
-3.00 -3.00

【样例输入】

90.5 -1 30 -0.8 
【样例输出】
60.50 -0.20



25.00
*/
#include<iostream>
#include<iomanip>
using namespace std;
void complex(float data[],float result[]);
int main()
{
    float data[4],result[2];
    int i;
    for(i=0;i<4;i++)cin>>data[i];
    complex(data,result);
    return 0;
}
void complex(float data[],float result[])
{
    result[0]=data[0]-data[2];
    result[1]=data[1]-data[3];
	cout << setprecision(2) << setiosflags(ios::fixed);
    cout<<result[0]<<' '<<result[1]<<endl;
}

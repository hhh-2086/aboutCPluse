/*【问题描述】从键盘输入两组英文字符（包括大写和小写英文字符），每组英文字母中都没有重复字母，分别转化为小写字符并存入两个数组a和b中，以英文字母表为依据，请输出a数组和b数组中在英文字母表中最接近的两个英文字母的距离。
【输入形式】输入包括两行英文字母，有大写和小写字母，每行不超过10个元素
【输出形式】输出一个整数，表示两个数组中最接近的两个英文字母的距离，如果两个字母相同，则输出为0
【样例输入】

abxy

cAzzp

【样例输出】
0

【样例输入】

aBc

deF

【样例输出】
1

【样例输入】

xYzy

deFac

【样例输出】
18
*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{	char a[10]={0},b[10]={0};
 	int i,j,min;
 	cin.getline(a,10);
 	cin.getline(b,10);
 	for(i=0;a[i];i++)
        if(a[i]<='Z')a[i]=a[i]+'a'-'A';
 	for(i=0;b[i];i++)
        if(b[i]<='Z')b[i]=b[i]+'a'-'A';
 	min=abs(a[0]-b[0]);
 	for(i=0;a[i];i++)
        for(j=0;b[j];j++)
            min=min<abs(a[i]-b[j])?min:abs(a[i]-b[j]);
 	cout<<min<<endl;
 	return 0;            
}

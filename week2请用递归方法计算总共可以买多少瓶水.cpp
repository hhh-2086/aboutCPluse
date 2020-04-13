/*【问题描述】1瓶水需要1元，用2个空瓶可以换1瓶水，3瓶盖也可以换1瓶水。小明现在有20元，请问最终可以买到多少瓶水？请使用递归实现。

【输入形式】输入为一个整数，表示小明现在有多少元钱。
【输出形式】输出为一个整数，表示小明最终买到的水的瓶数。
【样例输入】

20
【样例输出】

113
*/
#include<iostream>
using namespace std;
int water(int all,int head,int body);
int main()
{	int all,result;
 	cin>>all;
 	result=water(all,all,all);
 	cout<<result<<endl;
 	return 0;
}
int water(int all,int head,int body)
{
	int next;
	if((head>=3)||(body>=2))
	{
		next=head/3+body/2;
		head=head%3+next;
		body=body%2+next;
		all=all+water(next,head,body);
	}
	return all;
}

/*【问题描述】请编写一个程序，实现如下功能

a.txt文件中已经预先存储了一组数据，以空格分隔，数据的个数不确定。

从a.txt文件中读取数据，并将从小到大排序后的数据输出到b.txt文件

b.txt文件中数据以空格分隔
【输入形式】

输入文件名：a.txt
【输出形式】

输出文件名：b.txt
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
void bubble(double *data)
{
	int i,j;
	double t;
	for(i=0;data[i+1];i++)
		for(j=0;data[j+1];j++)
			if(data[j+1]<data[j])
			{
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
}
int main()
{
	ifstream filea("a.txt");
	ofstream fileb("b.txt");
	double data[100]={0.0};
	int n=0;
	if(filea)
	{
	while(!filea.eof())
	{
		//data.push_back(0);
		filea>>data[n++];
	}
	}
	else 
		cout<<"error"<<endl;

	bubble(data);
	n=0;
	while(data[n])
		fileb<<data[n++]<<' ';
	filea.close();
	fileb.close();
	return 0;
}


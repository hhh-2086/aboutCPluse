/*【问题描述】声明一个表示时间的类CTime，可以精确表示年、月、日、小时、分、秒，请计算两个日期对象之间相隔的天数。



要求：

1、包括私有成员年、月、日、小时、分、秒。

2、请使用构造函数实现的类的初始化工作，并判断日期和时间的有效性。年月日时分秒应该在正确的范围内。考虑闰年时候二月份的情况。时间的格式是xx:xx:xx,小时不是超过23，分钟和秒不能超过59。

      1）如果日期无效，则输出 “date error! ”  并将年、月、日、小时、分、秒置为0。

      2）如果时间无效，则输出 “time error! ”  并将年、月、日、小时、分、秒置为0。

      3）如果日期和时间都有效，则根据传递的参数初始化年、月、日、小时、分、秒。

      4）构造函数的三个参数：小时、分、秒 设计为默认形成，其默认值为0。

      5)  输出"构造函数被调用"

3、请设计一个拷贝构造函数，实现将参数的值全部传递给当前对象，同时输出“拷贝构造函数被调用”

4、请设计一个析构函数，同时输出“析构函数被调用”

5、设计一个成员函数  int dayDiff(CTime t) ，用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。

6、设计一个成员函数 showTime()，用于显示日期，显示格式为：2020/3/12 11:50:20



提示：除了上传要求的成员函数外，你可以自由添加需要的成员函数。

main函数已经给定，请补全其他代码。



【样例输入1】

2020 3 12 11 50 20

【样例输出1】

构造函数被调用

2020/3/12 11:50:20

构造函数被调用

拷贝构造函数被调用

析构函数被调用

这两天之间相隔了7376天

拷贝构造函数被调用

析构函数被调用

这两天之间相隔了7376天

析构函数被调用

析构函数被调用



【样例输入2】

2100 2 29 10 29 59
【样例输出2】

date error!

构造函数被调用

0/0/0 0:0:0

构造函数被调用

析构函数被调用

析构函数被调用



【样例输入3】

2000 2 29 15 79 40
【样例输出3】

time error!

构造函数被调用

0/0/0 0:0:0

构造函数被调用

析构函数被调用

析构函数被调用



【样例输入4】

2007 9 31 12 89 89
【样例输出4】

date and time error!

构造函数被调用

0/0/0 0:0:0

构造函数被调用

析构函数被调用

析构函数被调用
*/
#include <iostream>
#include<iostream>
using namespace std;
class CTime
{
public:
	CTime(int fyear,int fmonth,int fday,int fhour=0,int fminute=0,int fsecond=0);
	void showTime();
	CTime(CTime& p);
	int fullday(int month,int year);
	int isvalid();
	int dayDiff(CTime t);
	~CTime();

private:
	int year,month,day,hour,minute,second;
};



CTime::CTime(int fyear,int fmonth,int fday,int fhour,int fminute,int fsecond)
{

		year=fyear;
		month=fmonth;
		day=fday;
		hour=fhour;
		minute=fminute;
		second=fsecond;
	
		isvalid();

		cout<<"构造函数被调用"<<endl;
}				//构造函数部分



CTime::CTime(CTime& p)
{
	year=p.year;
	month=p.month;
	day=p.day;
	hour=p.hour;
	minute=p.minute;
	second=p.second;
	cout<<"拷贝构造函数被调用"<<endl;
}
			//拷贝构造函数部分


int CTime::fullday(int fmonth,int fyear)
{
	switch(fmonth)
	{
	case 1:
	case 3:									//返回该月的天数
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:return 31;
	case 4:
	case 6:
	case 9:
	case 11:return 30;
	}
	if(fyear%4==0&&fyear%100!=0||fyear%400==0)
	{
		if(fmonth==2)return 29;
	}
	else if(fmonth==2)return 28;
}			



int CTime::isvalid()
{
	int flag1=1,flag2=1;		//用flag1记录日期是否正确，正确为0，错误为1，flag2记录时间

	if(year==0&&month==0&&day==0)
		return 0;

	if(year<=2020&&month<=12&&day<=fullday(month,year)&&year>=0&&month>=0&&day>=0)
		flag1=0;

	if(hour<=23&&minute<=59&&second<=59&&hour>=0&&minute>=0&&second>=0)
		flag2=0;

	if(flag1==1&&flag2==1)
		{cout<<"data and time error!"<<endl;
		year=month=day=minute=hour=second=0;
		return 0;
		}
	else if(flag1)
	{
		cout<<"date error!"<<endl;
		year=month=day=minute=hour=second=0;
		return 0;
	}
	else if(flag2)
	{
		cout<<"time error!"<<endl;
		year=month=day=minute=hour=second=0;
		return 0;
	}
	else return 1;
}





int CTime::dayDiff(CTime t)		//计算相隔天数
{
	int days=0,cmonth1=0,cmonth2=0;		//days记录相隔天数，cmonth记录该月改日距离年初的天数

	int fy,by,i;				//fy是靠前的年，by是大的年

	fy=year<t.year?year:t.year;
	by=year>t.year?year:t.year;

	for(fy;fy<by;fy++)
		if(fy%4==0&&fy%100!=0||fy%400==0)
			days+=366;
		else 
			days+=365;


	for(i=1;i<month;i++)
		cmonth1+=fullday(i,year);
	cmonth1+=day;

	if(year<t.year)
		days-=cmonth1;
	else if(year>t.year)
		days+=cmonth1;



	for(i=1;i<t.month;i++)
		cmonth2+=fullday(i,t.year);
	cmonth2+=t.day;

	if(year<t.year)
		days+=cmonth2;
	else if(year>t.year)
		days-=cmonth2;

	if(year==t.year)
		days=(cmonth1-cmonth2>0)?(cmonth1-cmonth2):(cmonth2-cmonth1);

	return days;

}





CTime::~CTime()
{
	cout<<"析构函数被调用"<<endl;
}


void CTime::showTime()
{
	cout<<year<<'/'<<month<<'/'<<day<<' '<<hour<<':'<<minute<<':'<<second<<endl;
}


int main()
{
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime t2(2000, 1, 1); //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())     //如果日期和时间合法，则计算天数
    {
        int days=0;
        days=t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days=t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}


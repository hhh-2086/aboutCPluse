#include <iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

unsigned int toNumber(string &figure)//字符串转化为数字
{
    if(figure.size()==0)
    {
        return 1;
    }//如果没有储存，即为一倍
    else
    {
        unsigned int i = 0,num = 0;
		for(i;i<figure.size();i++)
            num = num*10+(figure[i]-'0');
        return num;
    }
}
//第三个参数为起始位置，第四个参数为终止位置
void buildMap(map<string,unsigned int>&Map,string &str,unsigned int i,unsigned int j,unsigned int last=1)
{
	unsigned int numLeft;
	string figure = "";
    for(i;str[i]>='0'&&str[i]<='9';i++)
	figure+=str[i];
    numLeft = toNumber(figure)*last;//首先计算系数，当括号嵌套时会再次加倍

    for(i;i<j;)
    {

       if(str[i]=='+')
	   {
		i++;
		string figure = "";
        for(i;str[i]>='0'&&str[i]<='9';i++)
        figure+=str[i];
        numLeft = toNumber(figure);//每次加号后都要计算系数计算系数，加号中不会包含在（）内，不存在翻倍
	    }

       if(str[i]=='(')
       {
            i++;
           unsigned int i1,j1;//作为嵌套函数中的始末位置
           i1=i;//初始位置
           unsigned int floor = i;
		   unsigned int count = 1;
           for(floor;;floor++)
		   {
                if(str[floor]=='(')
					count++;
				if(str[floor]==')')
				{
						count--;
						if(count==0)break;
				}
		   }
		   j1 = floor;//循环的末位置，及）的位置
            string mark="";
            floor++;
            for(floor;floor<j&&str[floor]>='0'&&str[floor]<='9';floor++)
                mark+=str[floor];//统计括号后面的下标

                buildMap(Map,str,i1,j1,numLeft*toNumber(mark));//按照角标次数循环

            i = floor;//关于括号或嵌套括号之后，在最后一个括号及下标，后面开始继续进行循环建立map
			continue;
       }

       //统计元素
        string member ="";
		member+=str[i];
        i++;
        if(i<j&&str[i]>='a'&&str[i]<='z')
            member+=str[i++];//元素作为map成员

		unsigned int numRight;
        figure = "";
        for(i;i<j&&str[i]>='0'&&str[i]<='9';i++)
            figure+=str[i];
        numRight = toNumber(figure);//计算后缀

        Map[member]+=numLeft*numRight;//统计该元素的数量
    }

}
int main()
{
    unsigned int n;
    cin>>n;
    vector<char>result(n);//储存最终的结果
    vector<string>strLeft(n);//等号左边的方程式
    vector<string>strRight(n);//等号右边的方程式
    map<string,unsigned int>MapLeft,MapRight;

    //输入方程式
    for(unsigned int i = 0;i<n;i++)
    {
		//先吸收调上一个enter键
        getline(cin,strLeft[i],'=');//等号左边的字符串
        getline(cin,strRight[i]);
    }

    //判断
    for(unsigned int i=0;i<n;i++)
    {
        MapLeft.erase(MapLeft.begin(),MapLeft.end());
		if(i>0)
        buildMap(MapLeft,strLeft[i],0,strLeft[i].size());
		else
		buildMap(MapLeft,strLeft[i],1,strLeft[i].size());

        MapRight.erase(MapRight.begin(),MapRight.end());
        buildMap(MapRight,strRight[i],0,strRight[i].size());

        if(MapLeft==MapRight)
            result[i]='Y';
        else result[i]='N';
    }

	for(unsigned int i = 0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}

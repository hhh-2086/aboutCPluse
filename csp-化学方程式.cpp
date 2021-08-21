#include <iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

unsigned int toNumber(string &figure)//�ַ���ת��Ϊ����
{
    if(figure.size()==0)
    {
        return 1;
    }//���û�д��棬��Ϊһ��
    else
    {
        unsigned int i = 0,num = 0;
		for(i;i<figure.size();i++)
            num = num*10+(figure[i]-'0');
        return num;
    }
}
//����������Ϊ��ʼλ�ã����ĸ�����Ϊ��ֹλ��
void buildMap(map<string,unsigned int>&Map,string &str,unsigned int i,unsigned int j,unsigned int last=1)
{
	unsigned int numLeft;
	string figure = "";
    for(i;str[i]>='0'&&str[i]<='9';i++)
	figure+=str[i];
    numLeft = toNumber(figure)*last;//���ȼ���ϵ����������Ƕ��ʱ���ٴμӱ�

    for(i;i<j;)
    {

       if(str[i]=='+')
	   {
		i++;
		string figure = "";
        for(i;str[i]>='0'&&str[i]<='9';i++)
        figure+=str[i];
        numLeft = toNumber(figure);//ÿ�μӺź�Ҫ����ϵ������ϵ�����Ӻ��в�������ڣ����ڣ������ڷ���
	    }

       if(str[i]=='(')
       {
            i++;
           unsigned int i1,j1;//��ΪǶ�׺����е�ʼĩλ��
           i1=i;//��ʼλ��
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
		   j1 = floor;//ѭ����ĩλ�ã�������λ��
            string mark="";
            floor++;
            for(floor;floor<j&&str[floor]>='0'&&str[floor]<='9';floor++)
                mark+=str[floor];//ͳ�����ź�����±�

                buildMap(Map,str,i1,j1,numLeft*toNumber(mark));//���սǱ����ѭ��

            i = floor;//�������Ż�Ƕ������֮�������һ�����ż��±꣬���濪ʼ��������ѭ������map
			continue;
       }

       //ͳ��Ԫ��
        string member ="";
		member+=str[i];
        i++;
        if(i<j&&str[i]>='a'&&str[i]<='z')
            member+=str[i++];//Ԫ����Ϊmap��Ա

		unsigned int numRight;
        figure = "";
        for(i;i<j&&str[i]>='0'&&str[i]<='9';i++)
            figure+=str[i];
        numRight = toNumber(figure);//�����׺

        Map[member]+=numLeft*numRight;//ͳ�Ƹ�Ԫ�ص�����
    }

}
int main()
{
    unsigned int n;
    cin>>n;
    vector<char>result(n);//�������յĽ��
    vector<string>strLeft(n);//�Ⱥ���ߵķ���ʽ
    vector<string>strRight(n);//�Ⱥ��ұߵķ���ʽ
    map<string,unsigned int>MapLeft,MapRight;

    //���뷽��ʽ
    for(unsigned int i = 0;i<n;i++)
    {
		//�����յ���һ��enter��
        getline(cin,strLeft[i],'=');//�Ⱥ���ߵ��ַ���
        getline(cin,strRight[i]);
    }

    //�ж�
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

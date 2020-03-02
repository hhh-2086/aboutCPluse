#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int i,hi,hj,sum=36,flag=1;

	int h[8];

	char a;

	for(i=0;i<8;i++)
	{cin>>a;
	if(a>='0'&&a<='8')h[i]=a-'0';
	else h[i]=9;
	}

for(i=0;i<8;i++)

		if(h[i]<=8)sum-=h[i];

		else hi=i;

	hj=sum;
	h[hi]=hj;
	
	for(i=0;i<8;i++)

	{if(abs(h[hi]-h[i])==abs(hi-i)&&abs(h[hi]-h[i])!=0)flag=0;}
	
	if(flag) cout<<hj<<endl;
	
	else cout<<"No Answer"<<endl;
}



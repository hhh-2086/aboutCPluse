#include <iostream>
#include <cmath>
using namespace std;

int isPrime(unsigned short a)
{
	unsigned short i;
	int flag=1;
	if(a==1)flag=0;
	else if(a==2)flag=1;
	else 
	for(i=2;i<=a/2;i++)
		{if(a%i==0)flag=0;break;}
	return flag;
}

int main()
{
    unsigned short a;
    cin>>a;
    if (isPrime(a))
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
}


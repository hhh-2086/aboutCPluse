#include<iostream>
using namespace std;
int main()
{
	int i,j,n;

	int a[3][3],b[3][3],c[3][3]={0};

	for(i=0;i<3;i++)

		for(j=0;j<3;j++)

			cin>>a[i][j];

	for(i=0;i<3;i++)

		for(j=0;j<3;j++)

			cin>>b[i][j];

	for(n=0;n<3;n++)

		for(j=0;j<3;j++)

			for(i=0;i<3;i++)

			c[n][j]+=(a[n][i]*b[i][j]);
	n=0;

	for(i=0;i<3;i++)

		for(j=0;j<3;j++)

		{	n++;

			if((n-1)%3==0)cout<<'\n';

			cout<<c[i][j]<<' ';
		}

	return 0;
}



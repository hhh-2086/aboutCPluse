/*【问题描述】

声名一个基类vehicle,有私有成员maxspeed和weight，公有成员run()和stop(),以及构造和析构函数。

从vehicle派生bicycle和motorcar, bicycle有私有成员height， motorcar有私有成员seatnum,以及各自的构造函数和析构函数。

从bicycle和motorcar派生出motorcycle，观察虚基类对继承的影响。

定义一个motorcycle的对象，分别调用run()和stop(),观察构造/析构函数的调用情况。

注意：构造函数和析构函数中均为cout语句，说明哪个构造/析构函数被调用。

该题重点和难点在于构造函数的设计，需考虑怎么给基类及最远基类传递参数。


【样例输出】

vehicle constructor called. maxspeed:3; weight4

bicycle constructor called. height:1

motorcar constructor called. setnum:2

motorcycle constructor called

vehicle run

vehicle stop

motorcycle destructor called

motorcar destructor called. setnum:2

bicycle destructor called. height:1

vehicle destructor called. maxspeed:3; weight4

*/
#include "iostream"
using namespace std;

class vehicle
{
	private:
		int maxspeed,weight;
	public:
		void run(){cout<<"vehicle run"<<endl;}
		void stop(){cout<<"vehicle stop"<<endl;}
		vehicle(int a,int b)
                {maxspeed=a;  weight=b;
                 cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;}
		~vehicle(){cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;}	
};
class bicycle:virtual public vehicle
{
	private:
		int height;
	public:
		bicycle(int height,int a,int b):vehicle(a,b)
		{
			this->height=height;
			cout<<"bicycle constructor called. height:"<<height<<endl;
		}
		
		~bicycle(){cout<<"bicycle destructor called. height:"<<height<<endl;}
};
class motorcar:virtual public vehicle
{
	private:
		int seatnum;
	public:
		motorcar(int seatnum,int a,int b):vehicle(a,b)
		{
			this->seatnum=seatnum;
			cout<<"motorcar constructor called. setnum:"<<seatnum<<endl;
		}
		
		~motorcar(){cout<<"motorcar destructor called. setnum:"<<seatnum<<endl;}
};
class motorcycle:public bicycle,public motorcar
{
	public:
		motorcycle(int a,int b,int c,int d):bicycle(a,c,d),motorcar(b,c,d),vehicle(c,d)
			{
				cout<<"motorcycle constructor called"<<endl;	
			}
		~motorcycle(){cout<<"motorcycle destructor called"<<endl;
		}
};


int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return 0;
}


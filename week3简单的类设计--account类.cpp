/*【问题描述】

有个银行需要开发一个用户管理程序，功能要求如下：

1、记录用户的账号、姓名、性别、年龄、现有存款

2、可以动态管理用户的存款

（1）当用户存钱时将金额添加到现有存款内

  (2）当用户取钱时，从现有账户中扣除

  (3)  如果取钱金额超过现有存款，则拒绝取钱操作。

  (4) 如果录入为100.897元，即为无效输入，应该拒绝操作。原因：录入的数据是以“元”为单位，金额的最小单位是分。请同学们考虑一下，如果能有效应对这类问题。



请根据给定的main函数设计一个Account类实现上述功能。



【样例输出】

Tom Black的存款为2000.89

您输入的金额不合法

Tom Black的存款为2000.89

Tom Black的存款为12000.89

Tom Black的存款为1999.89

您输入的金额不合法

Tom Black的存款为1999.89

您的存款金额不足

Tom Black的存款为1999.89

您输入的金额不合法

Jerry Black的存款为0.00
*/
#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account
{
    public:
    void init(char *rnumber,char *rname,char *rsex,int rage,double rremain);
    void printmoney();
    void deposit(double dmoney);
    void withdraw(double wmoney);
    private:
    char *number,*name,*sex;
    int age;
    double remain;
};
void Account::init (char *rnumber,char *rname,char *rsex,int rage,double rremain)
{	
    number=rnumber;
    name=rname;
    sex=rsex;
    age=rage;
	if(rremain*100-(int)(rremain*100)>=0.01)
		{cout<<"您输入的金额不合法"<<endl;
		remain=0;}
	else
	remain=rremain;
}
void Account::printmoney()
{
    cout<<name<<"的存款为"<<fixed<<setprecision(2)<<remain<<endl;
}
void Account::deposit(double dmoney)
{
    if(dmoney*100-(int)(dmoney*100)>=0.01)
        cout<<"您输入的金额不合法"<<endl;
    else
        remain+=dmoney;
}
void Account::withdraw(double wmoney)
{
    if(wmoney*100-(int)(wmoney*100)>=0.01)
        cout<<"您输入的金额不合法"<<endl;
	else if(remain-wmoney<0)
		cout<<"您的存款金额不足"<<endl;
    else
        remain-=wmoney;
}


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}


/*【问题描述】

请设计一个程序实现图书库存的管理。请根据给定的main函数及程序输出，完成设计。具体要求如下。

一、请设计一个Book类（与动态数组类的要求一致）：

1、包括私有成员：

    unsigned int m_ID;//编号

    string m_Name;//书名

    string m_Introductio//简介

    string m_Author;//作者

    string m_Date;//日期

    unsigned int m_Page;//页数

2、设计所有成员变量的getter和setter函数，关于getter和setter，我们在多文件视频课程中已经进行了介绍，同学们也可以百度了解。

3、设计构造与析构函数，不要求输出信息，但各位同学可以自己输出并分析各个对象的创建与删除的情况：

Book();//将m_ID初始化为0，表示这个一个未赋值对象

    virtual ~Book();//无具体的工作

    Book(const Book& other);//实现所有成员变量的拷贝


二、请设计一个Store类,这是一个基于vector实现的类，用于实现图书的管理：

1、包括私有成员：

    m_Books;//利用vector动态创建的Book数组

2、设计 unsigned int GetCount()函数，返回m_Books中存储的Book对象的个数。

3、设计构造与析构函数，因为vector能够实现存储空间的动态管理，因此此处的设计明显比动态数组类简单。

   1） Store();

   输出"Store default constructor called!"

   2）Store(int n);

   将m_Books的大小置为n;并输出"Store constructor with (int n) called!";

   3）virtual ~Store();

   输出"Store destructor called!";

   4）Store(const Store& other);

   实现对象数组的拷贝，并输出"Store copy constructor called!";vector已经解决了深拷贝的问题，这里无需做深拷贝设计。

4、设计入库操作

   入库操作的主要功能是在数组中添加一本新书。

   函数声明为：void in(Book &b)

   提示：利用vector的成员函数可以直接实现添加元素功能

5、设计出库操作

   出库操作的主要功能是根据指定的书名，在数组中删除这本书。

   函数声明为：void out(string name)

   提示：利用vector的成员函数可以直接实现删除元素功能

6、根据ID查找图书

   要求根据给定的ID查找图书，如果找到，则返回一个Book对象，Book对象中存储了对应书本的信息；如果找不到，则返回一个Book对象，Book对象的m_ID为0，表示未被初始化。

   函数声明为：Book findbyID(int ID)

   提示：vector中的元素遍历可以使用迭代器

7、根据name查找图书

   要求根据给定的书名查找图书，如果找到，则返回一个Book对象，Book对象中存储了对应书本的信息；如果找不到，则返回一个Book对象，Book对象的m_ID为0，表示未被初始化。

   函数声明为：Book findbyName(string name)

   提示：vector中的元素遍历可以使用迭代器



8、设计一个函数打印所有的图书的信息

   函数声明为：void printList()


【输入形式】

无

【输出形式】

见样例输出



【样例输出】

Store default constructor called!

第一本书入库

第二本书入库

第三本书入库

现有库存书籍数量：3

查找并出库图书：离散数学

离散数学 已成功出库

现有库存书籍数量：2

查找图书 ID：3

找到ID为3的书，书名：c程序设计

查找图书 name：离散数学

没有找到name为离散数学的书

输出所有库存图书的信息

There are totally 2 Books:

ID=1;  Name:C++ 语言程序设计(第4版);  Author:郑莉;  Date:201007;

ID=3;  Name:c程序设计;  Author:谭浩强;  Date:201006;

程序运行结束

Store destructor called!

*/
#include <iostream>
#include <vector>
using namespace std;
class Book
{
//请在此处补充Book类的定义

    public:
        Book();
        virtual ~Book();
        Book(const Book&other);
        unsigned int GetID() { return m_ID; }
        void SetID(unsigned int val) { m_ID = val; }
        unsigned int GetPage() { return m_Page; }
        void SetPage(unsigned int val) { m_Page = val; }
        string GetName() { return m_Name; }
        void SetName(string val) { m_Name = val; }
        string GetIntroduction() { return m_Introduction; }
        void SetIntroduction(string val) { m_Introduction = val; }
        string GetAuthor() { return m_Author; }
        void SetAuthor(string val) { m_Author = val; }
        string GetDate() { return m_Date; }
        void SetDate(string val) { m_Date = val; }

    private:
        unsigned int m_ID;
        unsigned int m_Page;
        string m_Name;
        string m_Introduction;
        string m_Author;
        string m_Date;

};
//请在此处补充Book类的成员函数实现
Book::Book()
{
    m_ID=0;
}
Book::Book(const Book&other)
{
    m_ID=other.m_ID;
    m_Name=other.m_Name;
    m_Introduction=other.m_Introduction;
    m_Author=other.m_Author;
    m_Date=other.m_Date;
    m_Page=other.m_Page;
}
Book::~Book()
{
    //dtor
}

class Store
{
//请在此处补充Store类的定义
    public:
        Store();
        virtual ~Store();
        Store(int n);
        Store(const Store& other);
        unsigned int GetCount() { return m_Books.size(); }
        void in(Book&b);
        void out(string name);
        Book findbyID(int ID);
        Book findbyName(string name);
        void printList();
    private:
        vector<Book>m_Books;

};
//请在此处补充Store类的成员函数实现
Store::Store()
{
    cout<<"Store default constructor called!"<<endl;
}		

Store::~Store()
{
	cout<<"Store destructor called!"<<endl;
}
Store::Store(int n)
{
	m_Books.resize(n);		//重置数组大小
     cout<<"Store constructor with (int n) called!"<<endl;
}

Store::Store(const Store& other)
{
	 m_Books=other.m_Books;
	 cout<<"Store copy constructor called!"<<endl;
}
void Store::in(Book& b)
{
	m_Books.push_back(b);
}

void Store::out(string name)
{
	int i;
	for(i=0;i<m_Books.size();i++)
		if(name==m_Books[i].GetName())
		{
			m_Books.erase(m_Books.begin()+i);
			break;
		}
}

Book Store::findbyID(int ID)
{
    unsigned int i=0;
    Book here;
    for(i;i<m_Books.size();i++)
    {
        if(ID==m_Books[i].GetID())
            {
                here=m_Books[i];
                break;
            }
    }
    return here;
}

Book Store::findbyName(string name)
{
    int i=0;
    Book here;
    for(i;i<m_Books.size();i++)
    {
        if(name==m_Books[i].GetName())
        {
            here=m_Books[i];
            break;
        }
    }
    return here;
}

void Store::printList()
{
    int i;
    cout<<"There are totally "<<m_Books.size()<<" Books:"<<endl;
    for(i=0;i<m_Books.size();i++)
    {
        cout<<"ID="<<m_Books[i].GetID()<<";  ";
        cout<<"Name:"<<m_Books[i].GetName()<<";  ";
        cout<<"Author:"<<m_Books[i].GetAuthor()<<";  ";
        cout<<"Date:"<<m_Books[i].GetDate()<<";\n";
    }
}

int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}



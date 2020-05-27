/*【问题描述】

请设计一个链表类模板，实现链表的初始化、插入、删除和打印操作。
【输入形式】

输入包括3行。

第一行是链表元素个数n。第二行为n个元素的值。第三行为拟删除的数据位置。



【输出形式】

输出格式不固定。具体参见样例。



【样例输入1】

4

1 2 3 4

2



【样例输出1】

Origin Length：4

data：1   2   3   4

Delete the data at position(2):2

New Length：3

data：1   3   4



【样例输入2】

2

100 -1

3



【样例输出2】

Origin Length：2

data：100 -1

pos > len, failed



【样例输入3】

8

8 7 6 5 4 3 2 1

0



【样例输出3】

Origin Length：8

data：8   7   6   5   4   3   2   1

pos <= 0, failed
*/

#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class linkedList
{
private :
	linkedList<T>*next;
	T data;
	int len;
public:

	linkedList();
	virtual ~linkedList();
	void insert(int value);
	bool initiate();
	bool isEmpty();
	bool remove(int pos,int &value);
	void print();
	int Length();
};
template<class T>linkedList<T>::linkedList()
{
	linkedList<T>*next = 0;
	len = 0;
}
template<class T>linkedList<T>::~linkedList()//析构函数
{
    if(next)
    {
        linkedList<T>*p=next;
        linkedList<T>*q=next;
        for(int i=0;i<len;i++)
        {
        q = p;
        p = p->next;
        delete q;

        }
    }

}

template<class T>bool linkedList<T>::initiate()
{
    next = 0;
	if(this)return true;
	return false;
}

template<class T>bool linkedList<T>::isEmpty()
{
	if(next)return false;
	return true;
}
template<class T>void linkedList<T>::insert(int value)
{
	linkedList<T>*p = this;
    int i=0;
	for(i;i<len;i++)p = p->next;
    p->next = new linkedList;
    p = p->next;
    p->data = value;
    p->next = 0;
    len = len+1;

}
template<class T> bool linkedList<T>::remove(int pos,int &value)
{
    if(pos>len){cout<<"pos > len, failed"<<endl;return false;}
    else if(pos<=0){cout<<"pos <= 0, failed"<<endl;return false;}

    else
    {
        int i=0;
        linkedList<T>*p = next;
        linkedList<T>*q = this;//q要相对p小一个位置
        for(i;i<pos-1;i++){q = p;p = p->next;}
        value = p->data;
        q->next = p->next;
        delete p;
        len--;
        return true;
    }
}
template<class T>int linkedList<T>::Length()
{
    return len;
}

template<class T>void linkedList<T>::print()
{
    if(isEmpty())cout<<"Empty"<<endl;

    else
    {
        linkedList<T>*tmp = next;
        while(tmp)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<endl;
    }

}




int main(int argc, char* argv[])
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}




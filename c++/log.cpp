#include <iostream>  
using namespace std;  
  
class Log  
{  
public:  
    virtual void log() = 0;//纯虚函数  
};  
  
class Log1 : public Log//继承接口  
{  
public:  
    void log()  
    {  
        cout << "1 logging..." << endl;  
    }  
};  
  
class Log2 : public Log//继承接口  
{  
public:  
    void log()  
    {  
        cout << "2 logging..." << endl;  
    }  
};  
  
class Business  
{ 
	Log *l;
public:  
    void business(Log * f)//函数参数只要Log指针，具体传入的是Log1还是Log2的实例，由多态进行实现  
    {  
    	l = f;
        while(1)  
        {  
            sleep(1);  
            cout << "Deal Business..." << endl;  
            f->log();  
        }  
    }  
    ...
    l->log();

};  
  
int main()  
{  
    Business b;  
    b.business(new Log2);//会调用Log2类中的log日志函数！  
    return 0;  
}  

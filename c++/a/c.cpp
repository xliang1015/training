#include <iostream>

using namespace std;

class Person
{
public:
    Person(int nAge):m_nAge(nAge){ cout << "创造了一个年龄为" << m_nAge << "的人" << endl; }
    Person(Person& Somebody):m_nAge(Somebody.m_nAge + 10) { cout << "复制创造了一个年龄为" << m_nAge << "的人" << endl; }
    ~Person() { cout << "析构了一个年龄为" << m_nAge << "的人" << endl; }

public:
    int m_nAge;

};

Person Test()
{
    Person Jack(30);
    return Jack;
}

main()
{
    Test();
    cout << "-----------------------" << endl;
    return 1;
}

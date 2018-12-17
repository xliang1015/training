#include <iostream>
#include "student.h"

using namespace std;

void show_student(student &s)
{
	cout << "friends" << s.age << endl;
}

int student:: getage() const
{
	return age;
}

int student:: getsex() const
{
	return sex;
}

const char *student:: getname() const
{
	return name;
}

bool kindergarten_student:: getcanpiepie() const
{
	return can_piepie;
}

bool kindergarten_student:: getcanpoopoo() const
{
	return can_poopoo;
}

student:: student()
{
	cout << "Student constructor called - " << sizeof(*this) << endl;
}

student:: ~student()
{
	cout << "Student de-constructor called" << endl;
}


kindergarten_student:: kindergarten_student()
{
	cout << "kindergarten_student constructor called - " << sizeof(*this) << endl;
}

kindergarten_student:: ~kindergarten_student()
{
	cout << "kindergarten_student de-constructor called" << endl;
}


student:: student(const student &s)
{
	age = s.age + 10;
	cout << "Student copy-constructor called" << endl;
}

kindergarten_student:: kindergarten_student(const kindergarten_student &ks)
{
	cout << "kindergarten_student copy-constructor called" << endl;
}

student func1()
{
	student a, b;
	cout << "func1 -" << &a << "-" << &b << endl;
	return b;
}

void func2(student s)
{
	cout << "func2 -" << &s << "-" << &s << endl;
}

student a2;

int student::num = 0;
main()
{
	cout << student::num <<endl;
	cout << "------------------" <<endl;
	{
	student a, a1(a);
	}
	cout << "------------------" <<endl;
	{
	kindergarten_student b, b1=b;
	}
	cout << "------------------" <<endl;
	func1();
	cout << "------------------" <<endl;
	{
	a2 = func1();
	cout << "a2 - " << &a2 << endl;
	}
	cout << "------------------" <<endl;
	{
	student a3(func1());
	cout << &a3 << endl;
	}
	cout << "------------------" <<endl;
	func2(a2);
	show_student(a2);
	cout << "------------------" <<endl;
}

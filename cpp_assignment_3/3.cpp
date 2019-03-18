// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//base class
class shape
{
public:
	virtual void display_area()
	{
		cout << "display area function of shape class";
	}
};
class Rectangle :public shape
{
public:
	virtual void display_area()
	{
		cout << "display area function of rectangle class";
	}
};
class Triangle :public shape
{
public:
	virtual void display_area()
	{
		cout << "display area function og triangle class";
	}
};
class Square :public shape
{
public:
	virtual void display_area()
	{
		cout << "display area function of square class";
	}
};

int main()
{
	shape *obj1;
	Rectangle R;
	obj1 = &R;//runtime binding
	obj1->display_area();
	Square S;
	obj1 = &S;
	obj1->display_area();
	Triangle T;
	obj1 = &T;
	obj1->display_area();
	system("pause");
	return 0;
}


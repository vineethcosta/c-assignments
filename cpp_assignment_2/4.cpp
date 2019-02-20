// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


class complex {
	int real;
public:
	complex()
	{
		real = 0;
	}
	complex(int x)
	{
		real = x;
	}
	complex(const complex &c)
	{
		real = c.real;
	}
	complex operator+(complex c1)
	{
		complex c3;
		c3.real = real + c1.real;
		return c3;
	}
	complex operator-(complex c1)
	{
		complex c3;
		c3.real = real - c1.real;
		return c3;
	}
	complex operator++()//pre
	{
		real++;
		return *this;
	}
	complex operator++(int)//post
	{
		const complex old(*this);
		++(*this);
		return old;
	}
	void operator-()
	{
		real = -real;
	}
	complex operator=(complex c)
	{
		real = c.real;
		return *this;
	}
	complex operator,(complex c)
	{
		return c;
	}
	int getreal()
	{
		return real;
	}
};
int main()
{	
	complex c1(10);
	complex c2(c1);
	complex c3;
	c3 = c1 + c2;
	//cout << c3.getreal() << " ";
	//c3 = c1 - c2;
	cout << c3.getreal() << " ";
	-c3;
	cout << c3.getreal() << " ";
	cout << (c3++).getreal() << " ";
	cout << (++c3).getreal() << " ";
	complex c4;
	c4 = c2;
	cout << c4.getreal() << " ";
	cout << (c1,c2,c3).getreal() << " ";
	system("pause");

    return 0;
}


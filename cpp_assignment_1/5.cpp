// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Distance2;
class Distance1 {
	int m;
	int c;
public:
	Distance1(int mm, int cm)
	{
		m=mm;
		c=cm;
	}
	friend void add(Distance1 d1, Distance2 d2);

};

class Distance2{
	int f;
	int i;
public:
	Distance2(int mm, int cm)
	{
		f = mm;
		i = cm;
	}
	friend void add(Distance1 d1, Distance2 d2);
	


};
void add(Distance1 d1, Distance2 d2)
{
	cout << "Metres=" << d1.m + d2.f / 3.28;
	cout << "Centimetres=" << d1.c + d2.i / 0.393;
}

int main()
{
	Distance1 d1(10, 10);
	Distance2 d2(10, 10);
	add(d1, d2);
	system("pause");
    return 0;
}


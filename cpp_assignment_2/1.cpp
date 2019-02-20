// cppassignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class polar {
	int angle;
	int radius;
public:
	static int c;
	polar()
	{
		c++;
		angle = 0;
		radius = 0;
	}
	polar(int a, int r)
	{
		c++;
		angle = a;
		radius = r;
		
	}


};
int polar::c;
int main()
{
	polar p(10,10);
	polar p1;
	polar p2;
	cout << p.c;
	system("pause");
    return 0;
}


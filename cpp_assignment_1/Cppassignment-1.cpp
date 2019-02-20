// Cppassignment-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Time {
	int hrs, min, secs;
public:
	Time() {
		hrs = 0;
		min = 0;
		secs = 0;
	}
	Time(int h, int m, int s)
	{
		hrs = h;
		min = m;
		secs = s;

	}
	void display()
	{
		cout << hrs << ":" << min << ":"<<secs;
	}
	void add(Time t1, Time t2)
	{
		
		hrs = (t1.hrs + t2.hrs)%12;
		min = (t1.min + t2.min)%60;
		hrs += (t1.min + t2.min) / 60;
		secs = (t1.secs + t2.secs) % 60;
		min+= (t1.secs + t2.secs) / 60;
		return ;
	}
};

int main()
{
	Time t1(10, 20, 30);
	Time t2(5, 25, 35);
	Time t3;

	t3.add(t1, t2);
	t3.display();
	system("pause");

    return 0;
}


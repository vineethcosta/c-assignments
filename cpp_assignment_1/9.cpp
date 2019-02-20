// 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void switch1(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "After switch 1  :" << a <<" "<< b;
}
void switch2(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	cout << "After switch 2  :" << *a <<" "<< *b;
}
int main()
{
	int n;
	cout << "1.call by value   2.Call by reference\n";
	cin >> n;
	
	switch (n)
	{
	case 1:
		int a, b;
		cin >> a >> b;
		switch1(a, b);
		cout << "\n" << a << "-" << b;
		break;
	case 2:
		int x,y;
		cin >> x >> y;
		switch2(&x, &y);
		cout << "\n" << x << "-" << y;
		break;
	default:
		break;
	}
	system("pause");
    return 0;
}


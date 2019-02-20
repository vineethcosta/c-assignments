// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class small {
public:
	inline int add(int a, int b)
	{
		return a + b;
	}
	inline int sub(int a, int b)
	{
		return a - b;
	}
	inline int mul(int a, int b)
	{
		return a * b;
	}
	inline int div(int a, int b)
	{
		return a / b;
	}
};
int main()
{
	small c1;
	cout << c1.add(5, 5) << c1.mul(5, 5) << c1.sub(5, 5) << c1.div(5,5);
	system("pause");
    return 0;
}


// 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class employee {
	int id;
public:
	employee()
	{
		id = 0;
		
	}
	employee(int a)
	{
		id = a;
	}
	employee( employee &x)
	{
		cout << "this is copy constructor:";
		 id=x.id;
		cout << x.id;
	}
	~employee()
	{
		cout << "destructor called";
	}
};
int main()
{
	employee x1(60);
	employee x2(x1);
	system("pause");
   return 0;
}


// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class Employee {
	int empno, sal;
	char name[10];
public:
	Employee()
	{
		empno = 0;
		sal = 0;
		name[0] = '\0';
	}
	Employee(int em, int sa, char na[10])
	{
		empno = em;
		sal = sa;
		strcpy(name, na);
	 }
	~Employee()
	{
		free(name);
	}
	friend istream& operator >> (istream& in, Employee &e) {
		in >> e.empno >> e.sal >> e.name;
		return in;
	}
};

int main()
{
	Employee e1, e2, e3, e4, e5;
	Employee ea[5];
	ea[0] = e1;
	ea[1] = e2;
	ea[2] = e3;
	ea[3] = e4;
	ea[4] = e5;

	for (int i = 0; i<5; i++)
	{
		cin >> ea[i];
	}
	system("pause");

    return 0;
}


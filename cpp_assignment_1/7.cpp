// 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class mul {
	int m;
	int n;
	public:
		mul(int a, int b)
		{
			m = a;
			n = b;

		}
		friend void multi(mul a, mul b);

};
void multi(mul a, mul b)
{
	int **x;
	x = new int*[a.m];
	for (int i = 0; i < a.m; i++)
	{
		x[i] = new int[a.n];
	}
	int **y;
	y = new int*[b.m];
	for (int i = 0; i < b.m; i++)
	{
		y[i] = new int[b.n];
	}
	int **z;
	z = new int*[a.n];
	for (int i = 0; i < a.n; i++)
	{
		z[i] = new int[b.m];
	}
	cout << "Enter first matrix";
	for (int i = 0; i < a.m; i++)
	{
		for (int j = 0; j < a.n; j++)
		{
			cin >> x[i][j];
		}
	}

		cout << "Enter second matrix";
		for (int i = 0; i < a.m; i++)
		{
			for (int j = 0; j < a.n; j++)
			{
				cin >> y[i][j];
			}
		}

		for (int i = 0; i < a.m; i++)
		{
			for (int j = 0; j < b.n; j++)
			{
				z[i][j] = 0;
				for (int k = 0; k < a.n; k++)
				{
					z[i][j] += x[i][k] * y[k][j];
				}
			}
		}
		cout << "The third matrix is";
		for (int i = 0; i < a.n; i++)
		{
			for (int j = 0; j < b.m; j++)
			{
				cout << z[i][j]<<" ";
			}
			cout << "\n";
		}
}


int main()
{
	mul m1(3,3);
	mul m2(3,3);
	multi(m1, m2);
	system("pause");

    return 0;
}


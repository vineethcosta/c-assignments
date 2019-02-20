// 3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class Complex {
	int real, img;
	public:
		Complex()
		{
			real = 0;
			img = 0;
		}
		Complex(int i)
		{
			real = img = i;

		}
		Complex(int i, int j)
		{
			real = i;
			img = j;
		}
		friend void addit(const Complex &, const Complex &,Complex );
		friend void mulit(const Complex &, const Complex &, Complex);

};
void addit(const Complex &c1, const Complex &c2,Complex c3)
{
	
	c3.real = c1.real + c2.real;
	c3.img = c1.img + c2.img;
	cout << c3.real << "+i" << c3.img<<"\n";
}
void mulit(const Complex &c1, const Complex &c2, Complex c3)
{

	c3.real = c1.real * c2.real;
	c3.img = c1.img * c2.img;

	cout << c3.real << "+i" << c3.img<<"\n";
}

int main()
{
	Complex c1(10);
	Complex c2(20,20);
	Complex c3;
	addit(c1, c2,c3);
	mulit(c1, c2, c3);
	system("pause");
    return 0;
}


// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	char * s[] = {
	"we will teach you how to" ,
	"Move a mountain ",
	"Level a building ",
	"Erase the past ",
	"Make a million " };
	int c = 0;
	int size=sizeof(s) / sizeof(char*);
	int size2;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < strlen(s[i]);j++)
			if(*(*(s+i)+j)=='e')
				c++;
	}
	cout<<c;
	system("pause");

    return 0;
}


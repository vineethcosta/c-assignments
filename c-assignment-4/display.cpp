// display.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n,m;
	char **ch;
	cout << "enter no of strings";
	cin >> n;
	string s;
	ch = (char**)malloc(sizeof(char*)*n);
	cout << "enter size of strings";
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		
		ch[i] = (char*)malloc(sizeof(char));
		cin >> ch[i];


	}
	for (int i = 0; i < n; i++)
	{
		cout<< ch[i]<<"\n";
	}
    return 0;
}


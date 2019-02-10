// strrev.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void rev(char*,int,int);
int main()
{
	char ch[10];
	cin >> ch;
	int i, j;
	i = 0;
	j = strlen(ch)-1;
	rev(ch,i,j);
	cout << ch;
	system("pause");
    return 0;
}
void rev(char* ch,int i,int j)
{
	if (i >= j)
		return;
	char temp;
	temp = ch[i];
	ch[i] = ch[j];
	ch[j] = temp;
	i++; j--;
	rev(ch, i, j);

}

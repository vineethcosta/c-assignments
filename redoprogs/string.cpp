#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
void reverse() {
	printf("enter string to be reversed\n");
	char *s = (char*)malloc(sizeof(char) * 10);
	cin >> s;
	int l;
	l = strlen(s);
	if (l != 0) //check whether input is valid
	{
		char *x1, *x2 = NULL;
		for (x1 = s, x2 = s + (l - 1); x1 < x2; x1++, x2--)
		{
			if (*x1 == ' ' || *x2 == ' ')
				break;
			char temp = *x1;
			*x1 = *x2;
			*x2 = temp;
		}
	}
	else
	{
		cout << "enter a valid string" << endl;
	}
	printf("The reversed string is %s", s);
	printf("\n");
	return;
}
int compare() {
	char *s1 = (char*)malloc(sizeof(char) * 10);
	char *s2 = (char*)malloc(sizeof(char) * 10);
	cout << "Enter strings to be compared";
	cin >> s1;
	cin >> s2;
	if (strlen(s1) != 0 && strlen(s2) != 0)
		while (*s1 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
	else {
		cout << "Please enter valid string to compare\n";
		return -1;
	}
	return *(char*)s1 - *(char*)s2;


}
void concat() {
	char *x1 = (char*)malloc(sizeof(char) * 10);
	char *x2 = (char*)malloc(sizeof(char) * 10);
	cout << "Enter string to be concatenated";
	cin >> x1;
	cin >> x2;
	int i = 0;
	while (x1[i] != '\0') {
		i++;
	}
	int j = 0;
	while (x2[j] != '\0') {
		x1[i] = x2[j];
		i++;
		j++;
	}
	x1[i] = '\0';
	cout << x1;
	return;
}
void copy() {
	char *x1 = (char*)malloc(sizeof(char) * 10);
	char *x2 = (char*)malloc(sizeof(char) * 10);
	cout << "Enter string to be copied";
	cin >> x2;
	cout << "Enter where to copy";
	cin >> x1;
	int i = 0;
	if (strlen(x1) != 0 && strlen(x2) != 0)
	{
		while (x2[i] != '\0') {
			x1[i] = x2[i];
			i++;
		}
		x1[i] = '\0';
		cout << "Copied string is :" << x1 << endl;
	}
	else
	{
		cout << "Enter valid string please!!";
	}

	return;
}
int main() {
	int inp;
	int a = 0;
	while (1) {
		printf("enter 1.reverse 2.compare 3.concat 4.strcpy others: exit\n");
		cin >> inp;
		switch (inp) {
		case 1:
			reverse();
			break;

		case 2:
			a = compare();
			if (a == 0) {
				printf("same strings\n");
			}
			else if (a > 1) {
				printf("string 1 is greater");
			}
			else if (a == -1)
			{
				printf("INVALID\n");
			}
			else {
				printf("string 2 is greater");
			}
			break;
		case 3:
			concat();
			break;
		case 4:
			copy();
			break;
		default:
			a = 1;
			goto outside;
			break;

		}
	}

outside:
	return 0;
}
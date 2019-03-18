// 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;

class String {
	int length;
	char *str;
public:
	String() //default constructor
	{
		str = NULL;
		length = 0;
	}
	String(int x)//parameterized constructor 
	{
		length = x;
		str = (char*)malloc(sizeof(char)*x);
	}
	String(const String &st) //shallow copy
	{
		str = st.str;
		length = st.length;
	}
	String(char *st) //deep copy 
	{
		length = strlen(st);
		str = (char*)malloc(sizeof(char)*length);
		strcpy(str, st);
	}
	~String() //calling the destructor
	{

	}
	//function declarations
	friend ostream& operator<<(ostream &cout, String str);
	friend istream& operator>>(istream &cin, String &str);
	String operator=(String equals);
	String operator+(String append);
	char operator[](int at);
		
};
//function definitions
ostream& operator<<(ostream& cout, String str_object)
{
	cout << str_object.str<<endl;
	return cout;
}
istream& operator>>(istream& cin, String &str_obj)
{
	char input[20];
	cin >> input;
	str_obj.str = (char*)malloc(sizeof(char)*strlen(input)+1);
	strcpy(str_obj.str, input);
	return cin;
}
String String::operator=(String equals) //deep copy
{
	str = (char*)malloc(sizeof(char)*strlen(equals.str) + 1);
	strcpy(str, equals.str);
	return *this;

}
String String::operator+(String append)
{
	String result;
	result.length = length + strlen(append.str) + 1;
	str = (char*)malloc(sizeof(char)*result.length);
	int i = 0;
	for (i = 0; i < length; i++)
		result.str[i] = str[i];
	for (int j = 0; j < append.length; j++)
		result.str[i++] = append.str[j];
	str[i] = '\0';
	return result;
}

char String::operator[](int at)
{
	return (*this).str[at]; 
}
int main()
{
	String obj1;//default constructor
	cin >> obj1;//input operator
	String obj2(obj1); //copy constructor
	cout << obj2<<endl;//output operator
	cout << obj1[3]<<endl;//at[] oparator
	String obj3 = obj1 + obj2;
	cout << obj3<<endl;
	system("pause");
    return 0;
}


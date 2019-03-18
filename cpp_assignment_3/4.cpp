// 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class access {
	int pri=10;
protected:
	int pro=20;
public:
	int pub=30;
	void display()
	{
		cout <<"base class:"<< "public" << pub << "private" << pri << "protected" << pro<<endl;
	}

};
class one : public access
{//pub is public,pri is private and pro is protected
public:
	void display()
	{
		cout << "one:"<<"public" << pub  << "protected" << pro <<endl;
	}
};
class two : protected access
{//pub and pro are protected ,pri is private
public:
	void display()
	{
		cout << "two:" << "public" << pub  << "protected" << pro << endl;
	}
};
class three : private access
{//all are private
public:
	void display()
	{
		cout << "three:" << "public" << pub  << "protected" << pro<<endl;
	}
};
int main()
{
	access a;
	a.display();
	one obj1;
	obj1.display();
	two obj2;
	obj2.display();
	three obj3;
	obj3.display();
	//obj1.pri cant be accessed
	//obj2.pri cant be accessed
	//obj3.pub,pri,pro cant be accessed since private
	system("pause");
    return 0;
}


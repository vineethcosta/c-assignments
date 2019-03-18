#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
//hybrid inheritance
class person
{
public:
	int age;
	string name;
	
	person()
	{
		name = "VINEETH";
		age = 21;
	}
	void displayone()
	{
		cout <<"Age of" << name << ":" << age << endl;
	}
};
///virtually deriving class
class physique : virtual public person
{
public:
	int height;
	int weight;
	physique()
	{
		height = 183;
		weight = 60;
	}
	void displaytwo()
	{
		
		cout << "HEIGHT:" << height << "WEIGHT: " << weight << endl;
	}
};
class family : virtual public person
{
public:
	int numChildren;
	string religion;
	family()
	{

		religion = "Christian";
		numChildren = 1;
	}
	void displaythree()
	{

		cout << "the no. of children are " << numChildren << " and religion is " << religion << endl;
	}
};
class employee : public physique, public family
{
public:
	int emno;
	float salary;
	employee()
	{
		emno = 31;
		salary = 70000.0f;
	}
	void displayfour()
	{
		displayone();
		displaytwo();
		displaythree();
		cout << "the employee number is " << emno << " salary is " << salary << endl;
	}
};
int main()
{
	employee obj1;
	// calling display function for employee class 
	obj1.displayfour();
	system("pause");
	return 0;
}
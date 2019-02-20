// 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class student {
	string studentName;
	string grade;
	int m1,m2,m3;
public:
	void set_Data(string studentN, int marks1, int marks2, int marks3)
	{
		studentName = studentN;
		m1 = marks1;
		m2 = marks2;
		m3 = marks3;

	}
	float avg()
	{
		float avg;
		avg= (float)(m1 + m2 + m3) / 3;
		return avg;
	}
	string ComputeGrade()
	{
		int a = avg();
		if (a > 60)
			return "First class";
		else if (a > 50 && a < 60)
			return "Second class";
		else if (a > 40 && a < 50)
			return "third class";
		else
			return "Fail";

	}
	void display()
	{
		grade = ComputeGrade();
		cout <<"student name "<<studentName<<"average "<<avg()<<"grade "<< grade << "marks1 " << m1 << "marks2" << m2 << "marks3" << m3;
	}

};

int main()
{
	student s;
	s.set_Data("Vineeth", 70, 50, 30);
	s.display();
	system("pause");
    return 0;
}


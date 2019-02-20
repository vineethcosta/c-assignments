// 2two.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class student {
	int roll, m1, m2, tm;
	float g;
	char name[10];
public:
	student() {
		roll = m1 = m2 = tm=0;
		g = 0.0f;
		name[0] = '\0';
		}
	friend ostream& operator<<(ostream& output, const student sout) {
		output << "roll" << sout.roll << " m1" << sout.m1<<" m2"<<sout.m2<<"Total marks"<<sout.tm<<"Grade"<<sout.g;
		output<<" name" << sout.name<<"\n";

		return output;

	}
	friend istream& operator >> (istream& input, student &sin)
	{	
		cout << "Enter roll no,m1,m2,name\n";
		input >> sin.roll >> sin.m1 >> sin.m2;
		input >> sin.name;
		return input;
	}
	friend void generateresults(student sa[], int n)
	{
		
		for (int i = 0; i < n; i++)
		{
			sa[i].tm = sa[i].m1 + sa[i].m2;
			sa[i].g = (float)(sa[i].tm / 2);
		}
	}
};
int main()
{
	student s1,s2, s3;
	cin >> s1>>s2>>s3;
	student sa[3];
	sa[0] = s1;
	sa[1] = s2;
	sa[2] = s3;
	generateresults(sa, 3);
	cout << sa[0] << sa[1] << sa[2];
	system("pause");
    return 0;
}


// 6.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
class point {
	int x;
	int y;
public:
	point(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
	friend float dist(point p, point q);
};
float dist(point p,point q)
{
	 float d;
	 d = sqrt((p.x - p.y)*(p.x - p.y) + (q.x - q.y)*(q.x - q.y));
	 return d;

}
int main()
{
	point p(3, 4);
	point q(4, 5);
	cout << "distance is\n" << dist(p, q);
	system("pause");
    return 0;
}


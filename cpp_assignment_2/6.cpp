#include<iostream>
using namespace std;
class anexample
{
	int a, b;
public:
	anexample()//default constructor
	{
		a = b = 0;
	}
	anexample(int ele1, int ele2)//parameterized constructor
	{
		a = ele1;
		b = ele2;
	}
	anexample(const anexample &x)//copy constructor
	{
		cout << "copy constructor is invoked,check the difference in the calling part";
		a = x.a;
		b = x.b;
	}

	void display();
	~anexample()//destructor
	{}
};
void anexample::display()
{
	cout << "obj1= " << a << "obj2= " << b << endl;
}
int main(int argc, char const *argv[])
{
	
	anexample obj1(11, 27);
	anexample obj2 = obj1, obj3(obj1);  //two ways of calling copy constructor
	obj1.display();
	obj2.display();
	obj3.display();
	
	system("pause");
	return 0;
}
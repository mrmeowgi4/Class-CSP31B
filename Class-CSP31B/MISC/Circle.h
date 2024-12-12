#pragma once
using namespace std;

#include <iostream>

#define PI 3.14159
class Circle
{
protected:

	double radius;

public:

	Circle(double radius)
	{
		this->radius = radius;
	}

	virtual int area()
	{
		return PI * (radius * radius);
	}

	void print()
	{
		cout << "Radius: " << radius << endl;
	}

};
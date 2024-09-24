
#include <iostream>
#include "GeometricObject.h"
#include "Triangle.h"

using namespace std;

int main()
{
	double side1, side2, side3;
	cout << "Enter three sides:";
	cin >> side1;
	cin >> side2;
	cin >> side3;
	
	int filled;
	cout << "Is this filled? (1/0)";
	cin >> filled;

	string color;
	cout << "Color? ";
	cin.ignore();//CIN breaks the entire string for some reason so we had to do this
	cin >> color;


	bool isfilled = filled == 0 ? false : true;

	Triangle tri(side1,side2,side3);
	tri.setFilled(isfilled);
	tri.setColor(color);
	
	double area, perimeter;

	area = tri.getArea();
	perimeter = tri.getPerimeter();

	printf("Area: %f\nPerimeter:%f\nFilled:%d\n", area, perimeter, filled);
	cout << "Color: " << tri.getColor();
	cout << endl;
	
	return 0;
}

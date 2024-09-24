#include "Triangle.h"
#include <math.h>

Triangle::Triangle()
{
	side1 = 1.0;
	side2 = 1.0;
	side3 = 1.0;
}

Triangle::Triangle(double given1, double given2, double given3)
{
	side1 = given1;
	side2 = given2;
	side3 = given3;
}

double Triangle::getSide1() const
{
	return side1;
}

double Triangle::getSide2() const
{
	return side2;
}

double Triangle::getSide3() const
{
	return side3;
}

double Triangle::getArea() const
{
	// Herons formula requires a semi-perimeter, which is computed
	// using the method below:
	double semiPerim = side1 + side2 + side3;
	double s = semiPerim / 2.0;


	double a = side1;
	double b = side2;
	double c = side3;

	double compPt1 = (s - a);
	double compPt2 = (s - b);
	double compPt3 = (s - c);

	double area = sqrt(s * (compPt1 * compPt2 * compPt3));

	return area;
}

double Triangle::getPerimeter() const
{
	double P;

	P = side1 + side2 + side3;

	return P;
}
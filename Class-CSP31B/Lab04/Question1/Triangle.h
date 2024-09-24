#pragma once
#include "GeometricObject.h"

class Triangle : public GeometricObject
{
private:

	double side1;
	double side2;
	double side3;

public:

	Triangle(); // No arg constructor
	Triangle(double given1, double given2, double given3); // Arg consuming


	////Constant Accessor functions///
	double getSide1() const;
	double getSide2() const;
	double getSide3() const;
	/////////////////////////////////

	double getArea() const;

	double getPerimeter() const;


};
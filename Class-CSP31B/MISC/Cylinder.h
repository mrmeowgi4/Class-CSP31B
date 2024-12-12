#include "Circle.h"

class Cylinder : public Circle
{
private:
	int h;

public:

	Cylinder(double radius, double h) : Circle(radius) {
		this->h = h;
	};

	int area() override
	{
		return 2 * PI * h + PI * (radius * radius);
	}
};
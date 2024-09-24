#pragma once
#include <iostream>
using namespace std;

class GeometricObject
{
protected:
	string color;
	bool filled;
public:

	GeometricObject();
	GeometricObject(const string& color, bool filled);

	string getColor() const;
	void setColor(const string& color);
	bool isFilled() const;
	void setFilled(bool filled);
	string toString() const;
};
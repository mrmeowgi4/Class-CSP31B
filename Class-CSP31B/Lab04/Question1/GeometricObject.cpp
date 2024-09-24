#include "GeometricObject.h"

GeometricObject::GeometricObject()
{
	color = "white";
	filled = false;
}

// stolen from the powerpoint
GeometricObject::GeometricObject(const string& color, bool filled)
{
	this->color = color;
	this->filled = filled;
}

string GeometricObject::getColor() const
{
	return color;
}

void GeometricObject::setColor(const string& col)
{
	this->color = col;
}

bool GeometricObject::isFilled() const
{
	return filled;
}

void GeometricObject::setFilled(bool filled)
{
	this->filled = filled;
}

string GeometricObject::toString() const
{
	return "Geometric Object";
}
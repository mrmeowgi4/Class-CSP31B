#pragma once
#include "Person.h"
#include <iostream>

class Staff : public Person
{
private:
	string title;
public:
	Staff(string title)
	{
		this->title = title;
	}

	string getTitle();
	void setTitle(string title);

	string toString() override;
};
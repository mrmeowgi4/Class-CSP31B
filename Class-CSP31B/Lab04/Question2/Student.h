#pragma once

#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person
{
private:
	string status;
public:
	Student(string rank)
	{
		this->status = rank;
	}

	string getStatus();
	void setStatus(string status);

	virtual string toString() override;
};
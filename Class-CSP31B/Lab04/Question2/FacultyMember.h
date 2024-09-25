#pragma once
#include "Person.h"
#include "Employee.h"

using namespace std;


class FacultyMember : public Person
{
private:
	int officeHours;
	string rank;
public:

	FacultyMember(string rank, int officeHours)
	{
		this->rank = rank;
		this->officeHours = officeHours;
	}

	int getOfficeHours();
	string getRank();

	void setOfficeHours(int of);
	void setRank(string rank);

	virtual string toString() override;
};
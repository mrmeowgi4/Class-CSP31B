#pragma once

#include <iostream>
#include "Person.h"
#include "MyDate.h"

using namespace std;

class Employee : public Person
{
private:
	string office;
	int salary;
	MyDate dateHired;
public:

	Employee(
		string office,
		int salary,
		MyDate dateHired)
	{
		this->office = office;
		this->salary = salary;
		this->dateHired = dateHired;
	}

	string getOffice();
	int getSalary();
	MyDate getDateHired();

	void setOffice(string off);
	void setSalary(int sal);
	void setDateHired(MyDate myDate);

	virtual string toString() override;

};
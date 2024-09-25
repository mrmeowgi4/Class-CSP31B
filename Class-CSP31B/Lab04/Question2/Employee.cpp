#include "Employee.h"
#include <sstream>

string Employee::getOffice()
{
	return this->office;
}

int Employee::getSalary()
{
	return this->salary;
}

MyDate Employee::getDateHired()
{
	return this->dateHired;
}

void Employee::setOffice(string off)
{
	this->office = off;

}

void Employee::setSalary(int sal)
{
	this->salary = sal;
}

void Employee::setDateHired(MyDate myDate)
{
	this->dateHired = myDate;
}

string Employee::toString()
{
	ostringstream os; // Got lazy lol
	string Address = this->getAddress();
	string EmailAddress = this->getEmailAddress();
	string Name = this->getName();
	string Number = this->getPhoneNumber();
	string mmDdyy="";


	os << "Employee, who's address=" << Address << "\n"
		<< "Email address=" << EmailAddress << "\n"
		<< "Name=" << Name << "\n"
		<< "Number=" << Number << "\n"
		<< "Date hired=" << this->dateHired.toString() <<"\n"
		<< "Salary=" << this->salary<<"\n"
		<< "Office=" << this->office<<"\n";

	return os.str();
}

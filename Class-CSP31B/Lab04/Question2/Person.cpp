#include "Person.h"
#include <sstream>

string Person::toString()
{
	ostringstream os; // Got lazy lol
	string Address = this->address;
	string EmailAddress = this->emailAddress;
	string Name = this->name;
	string Number = this->phonenumber;

	os << "Generic person, who's address="<<Address<<"\n"
		<<"Email address="<<EmailAddress<<"\n"
		<<"Name="<<			Name<<"\n"
		<<"Number="<<		Number<<"\n";

	return os.str();
}

string Person::getName()
{
	return this->name;
}

string Person::getAddress()
{
	return this->address;
}

string Person::getPhoneNumber()
{
	return this->phonenumber;
}

string Person::getEmailAddress()
{
	return this->address;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setAddress(string address)
{
	this->address = address;
}

void Person::setPhoneNumber(string number)
{
	this->phonenumber = number;
}

void Person::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

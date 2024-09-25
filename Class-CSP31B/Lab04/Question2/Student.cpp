#include "Student.h"
#include <sstream>

string Student::getStatus()
{
	return string();
}

void Student::setStatus(string status)
{
	this->status = status;
}

string Student::toString()
{
	ostringstream os; // Got lazy lol
	string Address = this->getAddress();
	string EmailAddress = this->getEmailAddress();
	string Name = this->getName();
	string Number = this->getPhoneNumber();

	os << "Student, who's address=" << Address << "\n"
		<< "Email address=" << EmailAddress << "\n"
		<< "Name=" << Name << "\n"
		<< "Number=" << Number << "\n"
		<< "Status="<<this->getStatus()<<"\n";

	return os.str();
}

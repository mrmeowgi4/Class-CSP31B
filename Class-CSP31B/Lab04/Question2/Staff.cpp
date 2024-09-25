#include "Staff.h"
#include <sstream>

string Staff::getTitle()
{
	return this->title;
}

void Staff::setTitle(string title)
{
	this->title = title;
}

string Staff::toString()
{
	ostringstream os; // Got lazy lol
	string Address = this->getAddress();
	string EmailAddress = this->getEmailAddress();
	string Name = this->getName();
	string Number = this->getPhoneNumber();

	os << "Staff, who's address=" << Address << "\n"
		<< "Email address=" << EmailAddress << "\n"
		<< "Name=" << Name << "\n"
		<< "Number=" << Number << "\n"
		<< "Title=" << getTitle()<<"\n";

	return os.str();
}

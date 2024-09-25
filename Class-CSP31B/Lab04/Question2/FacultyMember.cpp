#include "FacultyMember.h"
#include <sstream>

int FacultyMember::getOfficeHours()
{
	return this->officeHours;
}

string FacultyMember::getRank()
{
	return this->rank;
}

void FacultyMember::setOfficeHours(int of)
{
	this->officeHours = of;
}

void FacultyMember::setRank(string rank)
{
	this->rank = rank;
}

string FacultyMember::toString()
{
	ostringstream os; // Got lazy lol
	string Address = this->getAddress();
	string EmailAddress = this->getEmailAddress();
	string Name = this->getName();
	string Number = this->getPhoneNumber();

	os << "Faculty member, who's address=" << Address << "\n"
		<< "Email address=" << EmailAddress << "\n"
		<< "Name=" << Name << "\n"
		<< "Number=" << Number << "\n"
		<< "Rank=" << this->getRank()<<"\n"
		<< "Office hours="<<this->getOfficeHours()<<"\n";

	return os.str();
}

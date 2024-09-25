#include <iostream>
#pragma once
using namespace std;

class Person
{
private:
	string name;
	string address;
	string phonenumber;
	string emailAddress;
public:

	Person( string name,
			string address,
			string phonenumber,
			string emailAddress
	)
	{
		this->name = name;
		this->address = address;
		this->phonenumber = phonenumber;
		this->emailAddress = emailAddress;
	}

	Person()
	{
		// Professor didnt give default functionality
		// I made this so I can test the other classes directly.

		this->name = "Defualt name";
		this->address = "Default address";
		this->phonenumber = "Default phone number";
		this->emailAddress = "Generic Email Address";

	}

	string getName();
	string getAddress();
	string getPhoneNumber();
	string getEmailAddress();

	void setName(string name);
	void setAddress(string address);
	void setPhoneNumber(string number);
	void setEmailAddress(string emailAddress);

	virtual string toString();
};
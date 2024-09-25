#pragma once

#include "Person.h"
#include <sstream>

class MyDate : public Person // While it does not make sense, we still were instructed to override the toString method wherever we needed it.
{
private:
	int MM;
	int DD;
	int YY;
public:

	MyDate(int mm, int dd, int yy)
	{
		MM = mm;
		DD = dd;
		YY = yy;
	}

	MyDate()
	{
		// Needed this for testing the classes directly.
	}
	void setMM(int newMM)
	{
		this->MM = newMM;
	}

	void setDD(int newDD)
	{
		this->DD = newDD;
	}

	void setYY(int newYY)
	{
		this->YY = newYY;
	}

	int getMM()
	{
		return MM;
	}

	int getYY()
	{
		return YY;
	}

	int getDD()
	{
		return DD;
	}

	string toString() override
	{
		ostringstream oss;
		oss << MM << "/" << DD << "/" << YY;
		return oss.str();
	}
};
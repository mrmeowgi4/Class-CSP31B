#pragma once
#include <iostream>

using namespace std;

class MyDate
{
private:
	int MM;
	int DD;
	int YY;
public:

	MyDate(int MM, int DD, int YY)
	{
		
		this->MM = MM;
		this->DD = DD;
		this->YY = YY;

	}

	int getMM()
	{
		return MM;
	}

	int getDD()
	{
		return DD;
	}

	int getYY()
	{
		return YY;
	}

	// no setter functions are necessary
};
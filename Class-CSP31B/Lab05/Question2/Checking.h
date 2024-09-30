#include "Account.h"
#pragma once
using namespace std;


class Checkings : public Account
{
protected:
    int overdraftLimit;

public:
    Checkings()
    {
        overdraftLimit = 5000;
    }

    string toString() const
    {
        stringstream ss;
        ss << "Checking's account id: " << id << " balance: " << balance;
        return ss.str();
    }


};

#include "Account.h"
using namespace std;
#pragma once
class Saving : public Account
{
private:
    int overdraftLimit = NULL;
public:

    Saving() {

    }

    void setOverdraftLimit(int overdraftLimit)
    {
        overdraftLimit = NULL;
        printf("Savings account CANNOT be overdrafted.\n\n");
    }

    string toString() const override
    {
        stringstream ss;
        ss << "Savings Account id: " << id << " balance: " << balance;
        return ss.str();
    }
};
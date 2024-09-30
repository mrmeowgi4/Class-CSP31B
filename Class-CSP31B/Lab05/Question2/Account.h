#include <iostream>
#include <string>
#include <sstream>
#include "MyDate.h"
using namespace std;
#pragma once
class Account
{
protected:
    int id;
    double balance;
    double annualInterestRate;
    MyDate dateCreated = MyDate(NULL, NULL, NULL);
public:
    Account()
    {
        id = 0;
        balance = 0;
        annualInterestRate = 0;
    }

    Account(int id, double balance, double annualInterestRate, MyDate dateCreated)
    {
        this->id = id;
        this->balance = balance;
        this->annualInterestRate = annualInterestRate;
        this->dateCreated = dateCreated;
    }

    int getId() const
    {
        return this->id;
    }

    double getBalance() const
    {
        return balance;
    }

    double getAnnualInterestRate() const
    {
        return annualInterestRate;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    void setAnnualInterestRate(double annualInterestRate)
    {
        this->annualInterestRate = annualInterestRate;
    }

    double getMonthlyInterest() const
    {
        return balance * (annualInterestRate / 1200);
    }

    void withdraw(double amount)
    {
        balance -= amount;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    virtual string toString() const
    {
        stringstream ss;
        ss << "Account id: " << id << " balance: " << balance;
        return ss.str();
    }
};


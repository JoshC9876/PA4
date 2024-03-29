#include "Manager.h"

// Manager constructor that gets all the information on the manger partiallly using the Employee class ocnstrictor 
Manager::Manager(string theName, double theWage, double theHours, double theBonus)
    : Employee(theName, theWage, theHours) 
    {
        bonus = theBonus;
    }

// The overridden version of calcPay
double Manager::calcPay() const 
{
    return Employee::calcPay() + bonus;
}
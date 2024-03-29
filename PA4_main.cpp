/* 
# Author:           Josh Corbett
# BannerID:         001397674
# Course:           CS 181
# Assignment:       PA4
# Date Assigned:    Monday, March 18, 2024     
# Date/Time Due:    Saturday, March 30, 2024 -- 11:55 pm 
# Description:      This program will exercise Object Oriented concepts with C++. 
# Certification of Authenticity: 
    I certify that this assignment is entirely my own work. 
*/



#include <iostream>
#include <string> 
#include <iomanip>
#include "Manager.h"

using namespace std;

int main()
{
    // Gettign the number of managers
    int numManagers;
    cout << "Enter number of managers: ";
    cin >> numManagers;
     
    // Greating the pointer array for the managers  
    Manager *managers[numManagers];


    //Intilizes the managers 
    for (int i = 0; i < numManagers; ++i) {
        string name;
        double wage, hours, bonus;

        cout << "Enter manager " << i << " name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;
        cout << "Enter manager " << i << " hours worked: ";
        cin >> hours;
        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;

        managers[i] = new Manager(name, wage, hours, bonus);
    }
    
    //Creates the highest pay and total pay varibles  
    double highestPay = 0.0, totalPay = 0.0;

    Manager *highestPaidManager = nullptr;

    // For loop that caluclates the pay of the managers 
    for (int i = 0; i < numManagers; ++i) 
    {
        double pay = managers[i]->calcPay();
        totalPay += pay;
        if (pay > highestPay) 
        {
            highestPay = pay;
            highestPaidManager = managers[i];
        }
    }


    // Out puts the highest paid manager and the average pay
    cout << fixed << setprecision(2);
    cout << "Highest paid manager is " << highestPaidManager->getName() << " who is paid $" << highestPay << endl;
    cout << "Average pay is $" << totalPay / numManagers << endl;

    // Deleting dynamically allocated memory
    for (int i = 0; i < numManagers; ++i) 
    {
        delete managers[i];
    }

    return 0;
}

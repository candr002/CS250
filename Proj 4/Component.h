///***********************************************************
/// Author: Chris Andrzejewski
/// Date: TBD
/// Program: Class Assignment 4 (Vehicle Depot)
/// This program will simulate a vehicle repair depot.
///***********************************************************

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;


class component
{
public:

///==========================================================
    component(){next = NULL;}
///==========================================================

///==========================================================

///==========================================================

///==========================================================
    ~component()
    ///Destructor for the linked list

    {
        while (next != NULL)
            {
            while (next->next != NULL)
                {
                component *temp = next;
                temp->setNext(NULL);
                 next = next->next;
                 delete temp;
                }
            delete next;
            }
    }
///==========================================================

///==========================================================
    void setPartStatus(bool s)
        {componentStatus = s;}
///==========================================================


///==========================================================
    bool getPartStatus()
        {return componentStatus;}
///==========================================================


///==========================================================
    void makeNext()
        {next = new component;}
///==========================================================


///==========================================================
    void setNext(component *n)
        {next = n;}
///==========================================================


///==========================================================
    component *getNext()
        {return next;}
///==========================================================


///==========================================================
    int getRepairTime()
        {return compRepTime[componentNumber];}
///==========================================================


///==========================================================
    void setComponentNumber(int n)
        {
        componentNumber = n;
        }
///==========================================================


///==========================================================
    int getComponentNumber()
        {
        return componentNumber;
        }
///==========================================================


private:

    component *next;

    int componentNumber;

    bool componentStatus;

    const int compRepTime[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; ///Hard codes repair time value for each component type


};

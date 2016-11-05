///***********************************************************
/// Author: Chris Andrzejewski
/// Date: TBD
/// Program: Class Assignment 4 (Vehicle Depot)
/// This program will simulate a vehicle repair depot.
///***********************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <iomanip>
#include <random>
#include <ctime>
#include <stdio.h>


class component
{
public:

///==========================================================
    component(){next = NULL;}
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
        {component = s;}
///==========================================================


///==========================================================
    bool getPartStatus()
        {return component;}
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

    bool component;

    int compRepTime[9]; ///Hard codes repair time value for each component type
        const compRepTime[0] = 1;
        const compRepTime[1] = 2;
        const compRepTime[2] = 3;
        const compRepTime[3] = 4;
        const compRepTime[4] = 5;
        const compRepTime[5] = 6;
        const compRepTime[6] = 7;
        const compRepTime[7] = 8;
        const compRepTime[8] = 9;
};

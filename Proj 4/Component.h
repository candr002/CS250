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


class vehicle
{
public:

///==========================================================
    void setVehicleType(int n)
        {vehicleType = n;}
///==========================================================


///==========================================================
    int retVehicleType()
        {return vehicleType;}
///==========================================================


///==========================================================
    void setHardBrokeStatus(bool s)
        {hardBroke = s;}
///===========================================================


///===========================================================
    bool retHardBrokeStatus()
        {return hardBroke;}
///===========================================================


///===========================================================
    void hardBrokeChecker()
    {
        int temp = 0;

        for (int loop = 0; loop <5; loop++)
        {
            if (vehicleParts[loop].getPartStatus() != 1)
                {temp++}
        }
        if (temp > 2)
            {hardBroke = 1;}
        else
            {hardBroke = 0;}
    }
///===========================================================


///===========================================================
    void setTotalBrokenParts()
        {
            int temp = 0;

            for (int loop = 0; loop < 5; loop++)
            {
                if (vehicleParts[loop].getPartStatus(loop+(vehicleType-1)) == 0)
                    {temp++}
            }

            totalBrokenParts = temp;
        }
///===========================================================


///===========================================================
    int retTotalBrokenParts()
        {return totalBrokenParts;}
///===========================================================


///===========================================================
    void setTotalRepairTime()
        {
            int temp = 0;

            for (int loop = 0; loop < 5; loop++)
                {
                if (vehicleParts[loop].getPartStatus(loop+(vehicleType-1)) == 0)
                    {temp = vehicleParts[loop].getRepairTime());}
                }
            totalRepTime = temp;
        }
///===========================================================


///===========================================================
    void buildComponentSet()
    {
        default_random_engine partsFate;
        uniform_int_distribution<int> range(0,1);

        for (int loop = 0; loop < 5; loop++)
        {
            vehicleParts[loop].setComponentNumber(loop + (vehicleType -1));
            vehicleParts[loop].setPartStatus(partsFate(range));
        }
    }
///===========================================================
private:

    int vehicleType; ///Type of vehicle (assigned by number to help with loops) USING NUMBERS 1-5 NOT 0-4

    bool hardBroke; ///if the vehicle is not worth fixing/cant be fixed == 1

    int totalBrokenParts; ///number of parts broken on vehicle

    int totalRepTime; ///Total amount of time to repair vehicle

    component vehicleParts[5]; ///an array containing all component info

    vehicle *next;
};

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
#include "component.h"
#include <stdio.h>



class vehicle
{
public:

    vehicle(){next = NULL;}

    ~vehicle()

        {
        while (next != NULL)
        {
            while (next->next != NULL)
                {
                vehicle *temp = next;
                temp->setNext(NULL);
                next = next->next;
                 delete temp;
                }
            delete next;
        }
        }

///==========================================================
    void setVehicleType(int n)
        {vehicleType = n;}
///==========================================================


///==========================================================
    int retVehicleType()
        {return vehicleType;}
///==========================================================


///==========================================================
    void setStartTime(int n)
        {repairStartTime = n;}
///==========================================================


///==========================================================
    void setEndTime()
        {
        repairStopTime = repairStartTime + totalRepTime;
        if (repairStopTime > 23)
            {repairStopTime = repairStopTime - 23;}
        }
///==========================================================


///==========================================================
    int retEndTime()
        {return repairStopTime;}
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


///==========================================================
    void makeNext()
        {next = new vehicle;}
///==========================================================


///==========================================================
    void setNext(vehicle *n)
        {next = n;}
///==========================================================


///==========================================================
    vehicle *getNext()
        {return next;}
///==========================================================


///==========================================================
    int getRepairTime()
        {return compRepTime[componentNumber];}
///==========================================================

///===========================================================
    void buildComponentSet()
    {
        default_random_engine partsFate(time(NULL));
        uniform_int_distribution<int> range(0,1);

        for (int loop = 0; loop < 5; loop++)
        {
            vehicleParts[loop].setComponentNumber(loop + (vehicleType -1));
            vehicleParts[loop].setPartStatus(partsFate(range));
        }
    }
///===========================================================
private:

    int vehicleType, ///Type of vehicle (assigned by number to help with loops) USING NUMBERS 1-5 NOT 0-4
        repairStartTime,
        repairStopTime,
        totalBrokenParts,
        totalRepTime;

    bool hardBroke; ///if the vehicle is not worth fixing/cant be fixed == 1

    component vehicleParts[5]; ///an array containing all component info

    vehicle *next;
};

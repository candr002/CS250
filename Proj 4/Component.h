///***********************************************************
/// Author: Chris Andrzejewski
/// Date: 1 Oct 16
/// Program: Class Assignment 4 (Vehicle Depot)
/// This program will simulate a vehicle repair depot.
///***********************************************************

class component
{
public:


///==========================================================
    void setPartStatus(int n, bool s)
        {component[n] = s;}
///==========================================================


///==========================================================
    bool getPartStatus(int n)
        {return component[n];}
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
    int getRepairTime(int n)
        {return compRepTime[n];}
///==========================================================


private:

    component *next;

    bool component[9];

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
                    {temp = vehicleParts[loop].getRepairTime(loop + (vehicle-1));}
                }
            totalRepTime = temp;
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

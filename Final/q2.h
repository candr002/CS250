#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>

using namespace std;




class NEO
{
public:

NEO(){next = NULL;}
~NEO()
        {
        while (next != NULL)
        {
        while (next->next != NULL)
            {
            NEO *temp = next;
             next = next->next;
             delete temp;
            }
        delete next;
        }
};
///====================================================
void setID(double n)
    {ID = n;}
///====================================================

///====================================================
double retID()
    {return ID;}
///====================================================

///====================================================
void setTime(double n)
    {time = n;}
///====================================================

///====================================================
double retTime()
    {return time;}
///====================================================

///====================================================
void setDist(double n)
    {distance = n;}
///====================================================

///====================================================
double retDist()
    {return distance;}
///====================================================

///====================================================
void setAzimuth(double n)
    {azAngle = n;}
///====================================================

///====================================================
double retAzimuth()
    {return azAngle;}
///====================================================

///====================================================
void setElevation(double n)
    {elvAngle = n;}
///====================================================

///====================================================
double retElevation()
    {return elvAngle;}
///====================================================

///====================================================
void setXvector(double n)
    {xiVal = n;}
///====================================================

///====================================================
double retXvector()
    {return xiVal;}
///====================================================

///====================================================
void setYvector(double n)
    {yjVal = n;}
///====================================================

///====================================================
double retYvector()
    {return yjVal;}
///====================================================\
///====================================================
void setZvector(double n)
    {zkVal = n;}
///====================================================

///====================================================
double retZvector()
    {return zkVal;}
///====================================================

///====================================================
void makeNext()
    {next = new NEO;
    next->setID(ID + 1);}
///====================================================
///====================================================
void setNext(NEO *n)
    {next = n;}
///====================================================

///====================================================
NEO *retNext()
    {return next;}
///====================================================

private:

double ID,
    time,
    distance, ///initial pos distance from earth
    azAngle, ///initial pos val 2
    elvAngle, ///initial pos val 3
    xiVal,
    yjVal,
    zkVal;

    NEO *next;
};
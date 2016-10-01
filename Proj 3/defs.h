
///***********************************************************
/// Author: Chris Andrzejewski
/// Date: 1 Oct 16
/// Program: Class Assignment 3 (Draw a Mountain)
///***********************************************************
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>



using namespace std;

///======================================================================
class pointSet
 {

public:


///----------------------------------------------------------------------
    double retXpoint() {return xValue;}

///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retYpoint() {return yValue;}

///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retZpoint() {return zValue;}

///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setXpoint(double n) {xValue = n;}

///---------------------------------------------------------------------

///----------------------------------------------------------------------
    void setYpoint(double n) {yValue = n;}

///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setZpoint(double n) {zValue = n;}

///----------------------------------------------------------------------

///----------------------------------------------------------------------
    private:
        double xValue, yValue, zValue;

///----------------------------------------------------------------------
 };
///======================================================================


///======================================================================
class surface
{
///----------------------------------------------------------------------
    ~surface()
    ///Destructor for the linked list
        {
        while (next != NULL)
        {
        while (next->next != NULL)
            {
             surface *temp = next;
             next = next->next;
             delete temp;
            }
        delete next;
        }
        };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    surface(){next = NULL;}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setPoints(pointSet *x, pointSet *y, pointSet *z )
        {
            xPoint.setXpoint(x->retXpoint());
            xPoint.setYpoint(x->retYpoint());
            xPoint.setZpoint(x->retZpoint());

            yPoint.setXpoint(y->retXpoint());
            yPoint.setYpoint(y->retYpoint());
            yPoint.setZpoint(y->retZpoint());

            zPoint.setXpoint(z->retXpoint());
            zPoint.setYpoint(z->retYpoint());
            zPoint.setZpoint(z->retZpoint());
        }
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet *getXPoints()
    {
        pointSet *temp;

        temp->setXpoint(xPoint.retXpoint());
        temp->setYpoint(xPoint.retYpoint());
        temp->setZpoint(xPoint.retZpoint());

       return temp;
}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet *getYPoints()
    {
        pointSet *temp;

        temp->setXpoint(yPoint.retXpoint());
        temp->setYpoint(yPoint.retYpoint());
        temp->setZpoint(yPoint.retZpoint());

       return temp;
}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet *getZPoints()
    {
        pointSet *temp;

        temp->setXpoint(zPoint.retXpoint());
        temp->setYpoint(zPoint.retYpoint());
        temp->setZpoint(zPoint.retZpoint());

       return temp;
}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setCenterPoints()
    {
        double tempX, tempY, tempZ, temp;

        tempX = xPoint.retXpoint();
        tempY = yPoint.retXpoint();
        tempZ = zPoint.retXpoint();

        temp = ((tempX+tempY+tempZ)/3);
        centerPoint.setXpoint(temp);

        tempX = xPoint.retYpoint();
        tempY = yPoint.retYpoint();
        tempZ = zPoint.retYpoint();

        temp = ((tempX+tempY+tempZ)/3);
        centerPoint.setYpoint(temp);


        tempX = xPoint.retZpoint();
        tempY = yPoint.retZpoint();
        tempZ = zPoint.retZpoint();

        temp = ((tempX+tempY+tempZ)/3);
        centerPoint.setZpoint(temp);



    }
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setNextSurface ()
        {next = new surface;}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    surface *getNextSurface(surface *n)
        {

            return next;
        }
///----------------------------------------------------------------------

private:

    pointSet xPoint, yPoint, zPoint, centerPoint;
    surface *next;
};









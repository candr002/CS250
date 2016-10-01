
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
    ~pointSet()
    ///Destructor for the linked list
        {
        while (next->next != NULL)
            {
             pointSet *temp = next;
             next = next->next;
             delete temp;
            }
        delete next;
        };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet(){next = NULL;}
    void setnext(pointSet *n){next = n;}
    ///assigns an object to the end of the chain
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet *getnext(pointSet *n){return next;}
    ///proceeds down the linked list chain
///----------------------------------------------------------------------

///----------------------------------------------------------------------
     void makenew(){next = new pointSet;}
    ///makes a new object of complex type
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retXpoint() {return xValue;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retYpoint() {return yValue;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retZpoint() {return zValue;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retCenterPoint() {return centerValue;}
    ///returns the "real value" stored
///----------------------------------------------------------------------
///----------------------------------------------------------------------
    void setXpoint(double n) {xValue = n;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setYpoint(double n) {yValue = n;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setZpoint(double n) {zValue = n;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setCenterPoint(double n) {centerValue = n;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    private:
        double xValue, yValue, zValue, centerValue;

        pointSet *next;
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
        while (next->next != NULL)
            {
             surface *temp = next;
             next = next->next;
             delete temp;
            }
        delete next;
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
    pointSet *getCenterPoints()
    {
        pointSet *temp;

        temp->setXpoint(centerPoint.retXpoint());
        temp->setYpoint(centerPoint.retYpoint());
        temp->setZpoint(centerPoint.retZpoint());

       return temp;
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



int main ()

{
    return 0;
}

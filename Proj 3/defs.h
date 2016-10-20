
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
    void setXpoint(int n) {xValue = n;}

///---------------------------------------------------------------------

///----------------------------------------------------------------------
    void setYpoint(int n) {yValue = n;}

///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setZpoint(int n) {zValue = n;}

///----------------------------------------------------------------------
    void display()
    {
        cout<<xValue<<endl;
    }
///----------------------------------------------------------------------
    private:
        double xValue, yValue, zValue;

///----------------------------------------------------------------------
 };
///======================================================================


///======================================================================
class surface
{
    public:
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
    void setXPoints(pointSet *x)
        {
            xPoint.setXpoint(x->retXpoint());
            xPoint.setYpoint(x->retYpoint());
            xPoint.setZpoint(x->retZpoint());

        }
///----------------------------------------------------------------------



///----------------------------------------------------------------------
    void setYPoints(pointSet *y)
        {

            yPoint.setXpoint(y->retXpoint());
            yPoint.setYpoint(y->retYpoint());
            yPoint.setZpoint(y->retZpoint());

        }
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setZPoints(pointSet *z)
        {

            zPoint.setXpoint(z->retXpoint());    newChain->setXPoints(centroid);
    newChain->setYPoints(pointY);
    newChain->setZPoints(pointZ);
    newChain->setNextSurface();
    newChain = newChain->getNextSurface();
            zPoint.setYpoint(z->retYpoint());
            zPoint.setZpoint(z->retZpoint());

        }
///----------------------------------------------------------------------


///----------------------------------------------------------------------
    pointSet *getXPoints()
    {   pointSet * temp;
        temp = new pointSet;
        temp->setXpoint(xPoint.retXpoint());
        temp->setYpoint(xPoint.retYpoint());
        temp->setZpoint(xPoint.retZpoint());
        return temp;

        /*


       return temp;*/
}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet *getYPoints()
    {
        pointSet *temp = new pointSet;

        temp->setXpoint(yPoint.retXpoint());
        temp->setYpoint(yPoint.retYpoint());
        temp->setZpoint(yPoint.retZpoint());

       return temp;
}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    pointSet *getZPoints()
    {
        pointSet *temp = new pointSet;

        temp->setXpoint(zPoint.retXpoint());
        temp->setYpoint(zPoint.retYpoint());
        temp->setZpoint(zPoint.retZpoint());

       return temp;
}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void makeNewSurface ()
        {next = new surface;}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void setNextSurface (surface *n)
        {next = n;}
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    surface *getNextSurface()
        {

            return next;
        }
///----------------------------------------------------------------------

private:

    pointSet xPoint, yPoint, zPoint, centerPoint;
    surface *next;
};









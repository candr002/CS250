
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
#include <time.h>



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
void centroid(surface *n)
    {
        double temp;
        int rando;

        temp = (xPoint.retXpoint()+yPoint.retXpoint()+zPoint.retXpoint());
        temp = round(temp/3);

/*        srand(time(NULL));
        rando = trunc(temp);
        rando = rand() % rando - (trunc(rando/2));
        temp = rando;
*/
        centerpoint.setXpoint(temp);


        temp = (xPoint.retYpoint()+yPoint.retYpoint()+zPoint.retYpoint());
        temp = round(temp/3);
/*        srand(time(NULL));
        rando = trunc(temp);
        rando = rand() % rando - (trunc(rando/2));
        temp = rando;
*/        centerpoint.setYpoint(temp);


        temp = (xPoint.retZpoint()+yPoint.retZpoint()+zPoint.retZpoint());
        temp = round(temp/3);
        srand(time(NULL));
        rando = trunc(temp);
        rando = rand() % rando +1;
        temp = rando;

        centerpoint.setZpoint(temp);


    }
///----------------------------------------------------------------------

///----------------------------------------------------------------------
pointSet *getCentPoint()

{   pointSet * temp;
    temp = new pointSet;
    temp->setXpoint(centerpoint.retXpoint());
    temp->setYpoint(centerpoint.retYpoint());
    temp->setZpoint(centerpoint.retZpoint());
    return temp;

}
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

    zPoint.setXpoint(z->retXpoint());
    zPoint.setYpoint(z->retYpoint());
    zPoint.setZpoint(z->retZpoint());

        }
///----------------------------------------------------------------------


///----------------------------------------------------------------------
    pointSet *getXPoints()
    {
        pointSet *temp = new pointSet;

        temp->setXpoint(xPoint.retXpoint());
        temp->setYpoint(xPoint.retYpoint());
        temp->setZpoint(xPoint.retZpoint());
        return temp;

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

    pointSet xPoint, yPoint, zPoint, centerpoint;
    surface *next;
};









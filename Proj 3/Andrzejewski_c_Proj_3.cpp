
///***********************************************************
/// Author: Chris Andrzejewski
/// Date: 1 Oct 16
/// Program: Class Assignment 3 (Draw a Mountain)
///***********************************************************
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include "defs.h"

using namespace std;

void shatter(surface *head);



int main()

{
    ofstream outfile;
    ofstream outdat;
    outfile.open("command.txt");
    outdat.open("dat.txt");
    int xVal = 0, yVal = 0, zVal = 0, cVal = 0;
    int xValMax = 150, yValMax = 150, zValMax = 150, cValMax = 300;
    surface mountain;
    surface *head = &mountain;
    surface *current;
    current = head;

    pointSet centerpoint;
    pointSet *center = &centerpoint;

    pointSet point1; ///x == 0 , y == 0 , z == 0
    pointSet point2; ///x == 100 , y == 0 , z == 0
    pointSet point3; ///x == 0 , y == 100 , z == 0
    pointSet point4; ///x == 100 , y == 100 , z == 0
    pointSet point5;///    USER VAL
    pointSet *pointer1 = &point1;
    pointSet *pointer2 = &point2;
    pointSet *pointer3 = &point3;
    pointSet *pointer4 = &point4;
    pointSet *pointer5 = &point5;


    point1.setXpoint(0);
    point1.setYpoint(0);
    point1.setZpoint(0);


    point2.setXpoint(100);
    point2.setYpoint(0);
    point2.setZpoint(0);

    point3.setXpoint(100);
    point3.setYpoint(100);
    point3.setZpoint(0);

    point4.setXpoint(0);
    point4.setYpoint(100);
    point4.setZpoint(0);

    cout << "**************************************************************\n";
    cout << "**************************************************************\n";
    cout << "||Welcome to the AMAZING MOUNTAIN BUILDER GAME! Let's build.||\n";
    cout << "**************************************************************\n";
    cout << "**************************************************************\n\n\n";
    cout << "Please enter the X Y and Z values for the peak.\n";

    cin >> xVal;
    cin >> yVal;
    cin >> zVal;


    point5.setXpoint(xVal);
    point5.setYpoint(yVal);
    point5.setZpoint(zVal);



    ///Building basic mountain
    current=head;

    current->setXPoints(pointer1);
    current->setYPoints(pointer2);
    current->setZPoints(pointer5);
    current->makeNewSurface();
    current = current->getNextSurface();

    current->setXPoints(pointer2);
    current->setYPoints(pointer3);
    current->setZPoints(pointer5);
    current->makeNewSurface();
    current = current->getNextSurface();

    current->setXPoints(pointer3);
    current->setYPoints(pointer4);
    current->setZPoints(pointer5);
    current->makeNewSurface();
    current = current->getNextSurface();


    current->setXPoints(pointer4);
    current->setYPoints(pointer1);
    current->setZPoints(pointer5);





    current=head;
    //shatter(current);
        while (current!=NULL)
        {
        pointer1 = current->getXPoints();
        pointer2 = current->getYPoints();
        pointer3 = current->getZPoints();

        outdat << pointer1->retXpoint() << " "
                << pointer1->retYpoint() << " "
                << pointer1->retZpoint() << endl;

        outdat << pointer2->retXpoint() << " "
                << pointer2->retYpoint() << " "
                << pointer2->retZpoint() << endl;

        outdat << pointer3->retXpoint() << " "
                << pointer3->retYpoint() << " "
                << pointer3->retZpoint() << endl;

        outdat << pointer1->retXpoint() << " "
                << pointer1->retYpoint() << " "
                << pointer1->retZpoint() << endl<<endl;
        current = current->getNextSurface();
        }


    outdat.close();
    outfile << "clear" << endl ;
    outfile << "reset" << endl ;
    outfile << "set hidden3d" << endl ;
    outfile << "set dgrid3d" << endl;
    outfile << "set xrange [-10:125]" << endl;
    outfile << "set yrange [-10:125]" << endl;
    outfile << "set zrange [-10:125]" << endl;
    outfile << "splot \"dat.txt\" with lines" << endl;
    outfile << "pause -1";

    outfile.close();
    system("gnuplot command.txt ");


    delete head;
    delete pointer1;
    delete pointer2;
    delete pointer3;
    delete pointer4;
    delete pointer5;
    delete center;
    return 0;
}



void shatter(surface *head)
{

        surface *current = head;
        pointSet *centroid= new pointSet, *xVal = new pointSet, *yVal=new pointSet, *zVal=new pointSet;
        int temp, val1, val2, val3;
        surface *parentSurface = head;
        surface dasSurface;
        surface *surfTemp = &dasSurface, *surfDel;
        pointSet *pointTemp1, *pointTemp2, *pointTemp3;
        current = surfTemp;
        xVal = current->getXPoints();
        yVal = current->getYPoints();
        zVal = current->getZPoints();

        ///Working with the x value
        val1 = xVal->retXpoint();
        val2 = yVal->retXpoint();
        val3 = zVal->retXpoint();

        temp = ((val1 + val2 +val3) /2);

        centroid->setXpoint(temp);

        ///Working with the y value

        val1 = xVal->retYpoint();
        val2 = yVal->retYpoint();
        val3 = zVal->retYpoint();

        temp = ((val1 + val2 +val3) / 2 );

        centroid->setYpoint(temp);


        ///Working with the z value
        val1 = xVal->retZpoint();
        val2 = yVal->retZpoint();
        val3 = zVal->retZpoint();

        temp = ((val1 + val2 +val3) / 2);
        centroid->setXpoint(temp);



    pointTemp1= parentSurface->getXPoints();
    pointTemp3= centroid;
    pointTemp2= parentSurface->getYPoints();

    current->setXPoints(pointTemp1);
    current->setYPoints(pointTemp2);
    current->setZPoints(pointTemp3);
    current->makeNewSurface();
    current= surfTemp->getNextSurface();

    pointTemp1 = centroid;
    pointTemp2 = parentSurface->getYPoints();
    pointTemp3 = parentSurface->getZPoints();

    current->setXPoints(pointTemp1);
    current->setYPoints(pointTemp2);
    current->setZPoints(pointTemp3);

    current->makeNewSurface();
    current->getNextSurface();

    pointTemp1 = parentSurface->getXPoints();
    pointTemp2 = centroid;
    pointTemp3 = parentSurface->getZPoints();

    current->setXPoints(pointTemp1);
    current->setYPoints(pointTemp2);
    current->setZPoints(pointTemp3);

    current->setNextSurface(parentSurface->getNextSurface());

    surfDel = head;
    head = surfTemp;
    delete surfDel;



}

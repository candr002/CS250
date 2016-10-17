
///***********************************************************
/// Author: Chris Andrzejewski
/// Date: 1 Oct 16
/// Program: Class Assignment 3 (Draw a Mountain)
/// This program will build a mountain based on 4 hard coded
/// "base" points and a user-defined "peak" point.  Based on
/// these points, the program will generate a surface from
/// "shattering" each "surface" into progressively smaller
/// surfaces.
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

    ///Setting initial points (base) of mountain
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

    ///Output for user's sake
    cout << "**************************************************************\n";
    cout << "**************************************************************\n";
    cout << "||Welcome to the AMAZING MOUNTAIN BUILDER GAME! Let's build.||\n";
    cout << "**************************************************************\n";
    cout << "**************************************************************\n\n\n";
    cout << "Please enter the X Y and Z values for the peak.\n";

    ///Input final values (z,y,z points for peak) four mountain
    cin >> xVal;
    cin >> yVal;
    cin >> zVal;


    point5.setXpoint(xVal);
    point5.setYpoint(yVal);
    point5.setZpoint(zVal);



    ///Loading hard-coded and user-defined points into linked list
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




    ///Outputting all points within linked list out a data file for later usage
    current=head;

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

    ///Building a file of commands to build the mountain in GNUPlot based on previously generated data file (of points)
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

    ///Actual command to build the mountain
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




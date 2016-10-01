
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
#include "defs.h"

using namespace std;


///****************still need to write function to "shatter" a surface into 3 smaller surfaces based on it's 3 points and centroid********************


int main()

{
    ofstream outfile;
    ofstream outdat;
    outfile.open("command.txt");
    outdat.open("dat.txt");
    double xVal = 0, yVal = 0, zVal = 0, cVal = 0;
    double xValMax = 150, yValMax = 150, zValMax = 150, cValMax = 300;


    pointSet point1; ///x == 0 , y == 0 , z == 0
    pointSet point2; ///x == 100 , y == 0 , z == 0
    pointSet point3; ///x == 0 , y == 100 , z == 0
    pointSet point4; ///x == 100 , y == 100 , z == 0
    pointSet point5; ///x == 0 , y == 0 , z == USER VAL

    point1.setXpoint(0);
    point1.setYpoint(0);
    point1.setZpoint(0);

    point2.setXpoint(100);
    point2.setYpoint(0);
    point2.setZpoint(0);

    point3.setXpoint(0);
    point3.setYpoint(100);
    point3.setZpoint(0);

    point4.setXpoint(100);
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

    cout << xVal << endl;
    cout << yVal << endl;
    cout << zVal << endl;

    outdat << point1.retXpoint() << " "
            << point1.retYpoint() << " "
            << point1.retZpoint() << endl;

    outdat << point2.retXpoint() << " "
            << point2.retYpoint() << " "
            << point2.retZpoint() << endl;

    outdat << point3.retXpoint() << " "
            << point3.retYpoint() << " "
            << point3.retZpoint() << endl;

    outdat << point4.retXpoint() << " "
            << point4.retYpoint() << " "
            << point4.retZpoint() << endl;

    outdat << point5.retXpoint() << " "
            << point5.retYpoint() << " "
            << point5.retZpoint() << endl;


    outdat.close();
    outfile << "clear" << endl ;
    outfile << "reset" << endl ;
    outfile << "set hidden3d" << endl ;
    outfile << "set dgrid3d" << endl;
    outfile << "splot \"dat.txt\" with lines" << endl;
    outfile << "pause -1";

    outfile.close();
    system("gnuplot command.txt ");
    return 0;
}

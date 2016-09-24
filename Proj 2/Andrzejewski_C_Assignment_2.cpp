#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
  ofstream outfile;
  outfile.open("command.txt");
/// Declaring and opening outfile used for script


double yint1, yint2, slope1, slope2;
string title;
/// Declaring Variables

cout<<"What shall we call this graph? ";
    getline(cin,title);

cout<<"What is the SLOPE value (DECIMAL FORM) for the FIRST line?";
    cin>>slope1;
cout<<"What is the Y INTERCEPT value for the FIRST line?";
    cin>>yint1;

cout<<"What is the SLOPE value (DECIMAL FORM) for the SECOND line?";
    cin>>slope2;
cout<<"What is the Y INTERCEPT value for the SECOND line?";
    cin>>yint2;

/// Getting inputs (Title/plots)


///***********************generate the command.txt
outfile<<"clear"<<endl;
outfile<<"reset"<<endl;
outfile<<"set title \""<<title<<"\""<<endl;
outfile<<"m0 = "<<slope1<<endl;
outfile<<"b0 = "<<yint1<<endl;
outfile<<"m1 = "<<slope2<<endl;
outfile<<"b1 = "<<yint2<<endl;
outfile<<"f(x)=m0*(x)+b0"<<endl;
outfile<<"g(x)=m1*(x)+b1"<<endl;
outfile<<"set xrange [-20:20]"<<endl;
outfile<<"set yrange [-20:20]"<<endl;
/// formatting GNUPlot and setting variables



outfile<<"plot g(x), f(x)"<<endl;
/// output of graph

outfile<<"pause -1"<<endl;
/// Hold screen open

outfile.close();


system("gnuplot command.txt ");
/// system commant calling the script file

return 0;
}

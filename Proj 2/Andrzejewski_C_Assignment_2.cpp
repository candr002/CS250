#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
  ofstream outfile;
  outfile.open("command.txt");
double yint1, yint2, slope1, slope2;
string title;
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

///***********************generate the command.txt
outfile<<"clear"<<endl;
outfile<<"reset"<<endl;
outfile<<"set title \""<<title<<"\""<<endl;
outfile<<"m0 = "<<slope1<<endl;
outfile<<"b0 = "<<yint1<<endl;
outfile<<"m1 = "<<slope2<<endl;
outfile<<"b1 = "<<yint2<<endl;
outfile<<"f(x)=m0*(x)+b0"<<endl;
outfile<<"set xrange [-20:20]"<<endl;
outfile<<"set yrange [-20:20]"<<endl;


outfile<<"g(x)=m1*(x)+b1"<<endl;
outfile<<"set xrange [-20:20]"<<endl;
outfile<<"set yrange [-20:20]"<<endl;
outfile<<"plot g(x), f(x)"<<endl;

outfile<<"pause -1"<<endl;
outfile.close();

///**************************call gnuplot
system("gnuplot command.txt ");
return 0;
}

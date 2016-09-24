#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
  fstream fout;
  fout.open("command.txt",ios::out);
double a, b, c, d;
string title;
cout<<"what is the title? "; getline(cin,title);
cout<<"please enter the a value: "; cin>>a;
cout<<"please enter the b value: "; cin>>b;
cout<<"please enter the c value: "; cin>>c;
cout<<"please enter the d value: "; cin>>d;
///***********************generate the command.txt
fout<<"clear"<<endl;
fout<<"reset"<<endl;
fout<<"set title \""<<title<<"\""<<endl;
fout<<"a = "<<a<<endl;
fout<<"b = "<<b<<endl;
fout<<"c = "<<c<<endl;
fout<<"d = "<<d<<endl;
fout<<"f(x)=c/((x-a)*(x-a)+b)+d/sqrt(x)"<<endl;
fout<<"set xrange [0:10]"<<endl;
fout<<"set yrange [0:4]"<<endl;
fout<<"plot f(x)"<<endl;
fout<<"pause -1"<<endl;
fout.close();

///**************************call gnuplot
system("gnuplot command.txt ");
return 0;
}

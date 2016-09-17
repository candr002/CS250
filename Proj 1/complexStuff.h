#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

///======================================================================
class complexNums
 {
    public:
///----------------------------------------------------------------------
    ~complexNums()
    ///Destructor for the linked list
        {
        while (next != NULL)
            {
             complexNums *temp = next;
             next = next->next;
             delete temp;
            }
        delete next;
        };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    complexNums(){next = NULL;}
    void setnext(complexNums *n){next = n;}
    ///assigns an object to the end of the chain
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    complexNums *getnext(complexNums *n){return next;}
    ///proceeds down the linked list chain
///----------------------------------------------------------------------

///----------------------------------------------------------------------
     void makenew(){next = new complexNums;}
    ///makes a new object of complex type
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retReal() {return real;}
    ///returns the "real value" stored
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    double retImagine() {return imaginary;}
    ///Returns the "imaginary value" stored
///----------------------------------------------------------------------


///-----------------------------------------------------------------------
     void displayStuff(complexNums *ptr)
     ///Displays the linked list
     {
        complexNums *current = ptr;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\nHere is your CURRENT LIST:\n\n\t";

         while (current->next != NULL)
         {
             cout << showpoint << fixed<< setprecision(2);
             cout << "\n\t" << current->real << "\t" << current->imaginary << "i ";
             current = current->next;
         }
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
     };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void inputStuff(ifstream &theFile, complexNums *ptr)
    ///Creates the linked list from a file
    {
      double temp = 0;
      complexNums *current = ptr;
      while (!theFile.eof())
        {
            theFile >> current->real;
            theFile >> current->imaginary;
            current->next = new complexNums;
            current = current->next;

        }
    };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    void sumStuff(complexNums *start)
    ///Sums the linked list and outputs results
        {
        double realSum = 0;
        double imaginarySum = 0;
        complexNums *current = start;
        while (current->next != NULL)
        {
            realSum = realSum + current->real;
            imaginarySum = imaginarySum + current->imaginary;
            current = current->next;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << showpoint << fixed<< setprecision(2) << setw(9);
        cout << "\n\nThe SUM of the number list is:\n\n\t(" << realSum;
        if (imaginarySum < 0)
            cout << " - " << abs(imaginarySum) << "i)\n\n" ;
        else
            cout << " + " << imaginarySum << "i)\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
 void multiplyStuff(complexNums *start)
     ///Multiplies the linked list and outputs results

       {
        double real, realNext, realProd;
        double imaginary, imaginaryNext, imaginaryProd;
        complexNums *working = start;
        real = working->retReal();
        imaginary = working->retImagine();
        working = working->getnext(working);

        while (working->next != NULL)
            {
            realNext = working->retReal();
            imaginaryNext = working->retImagine();
            realProd = (real*realNext)- abs(imaginary*imaginaryNext);
            imaginaryProd = (real*imaginaryNext) + (imaginary*realNext);

            working = working->next;
            real= realProd;
            imaginary= imaginaryProd;
            }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << showpoint << fixed<< setprecision(2);
        cout << "\n\nThe PRODUCT of the number list is:\n\n\t(" << realProd ;
        if (imaginaryProd < 0)
            cout << " - " << abs(imaginaryProd) << "i)\n\n" ;
        else
            cout << " + " << abs(imaginaryProd) << "i)\n\n";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        };
///----------------------------------------------------------------------

///----------------------------------------------------------------------
    private:
        double real, imaginary;

        complexNums *next;
///----------------------------------------------------------------------
 };
///======================================================================

///======================================================================
 void errorMsg()
 ///Error message for not loading a file first
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "\n\nYou have to LOAD your FILE first silly!\n\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
///======================================================================

///======================================================================
void displayMenu()
///Displays program menu
    {
    cout << "\n\n\nThank you for choosing the altermacation machine! \n" <<
                "Please tell me how I can help you... \n\n"
                << "================================================ \n";
    cout << "1. LOAD my list please! \n"
                << "2. DISPLAY my fancy list por favor!\n"
                << "3. Can you ADD UP my LIST so I don't have to? \n"
                << "4. Let's get crazy! MULTIPLY EVERYTHING\n"
                << "5. You have helped me enough thanks! I'm all done. \n"
                << "================================================ \n\n";
    }
///======================================================================




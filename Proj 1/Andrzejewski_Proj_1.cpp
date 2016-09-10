#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;



class complexNums
 {
    public:

    complexNums(){next = NULL;}
    void setnext(complexNums *n){next = n;}
    ///assigns an object to the end of the chain

    complexNums *getnext(complexNums *n){return next;}
    ///proceeds down the linked list chain

     void makenew(){next = new complexNums;}
    ///makes a new object of complex type
///-----------------------------------------------------------------------
     void displayStuff(complexNums *ptr)
     {
        complexNums *current = ptr;
         while (current->next != NULL)
         {
             cout << showpoint << fixed<< setprecision(2);
             cout << "\n\t" << current->real << "\t" << current->imaginary << "i ";
             current = current->next;
         }
     };
///--------------------------------------------------
    void inputStuff(ifstream &theFile, complexNums *ptr)
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
///------------------------------------------------------
    void sumStuff(complexNums *start)
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
        cout << showpoint << fixed<< setprecision(2) << setw(9);
        cout << "The sum of the number list is (" << realSum;
        if (imaginarySum < 0)
            cout << " - " << abs(imaginarySum) << "i)\n\n" ;
        else
            cout << " + " << imaginarySum << "i)\n\n";
        };
///-------------------------------------------------------

 void multiplyStuff(complexNums *start)
       {
        double real, realSum;
        double imaginarySum = 0;
        complexNums *current = start;
        while (current->next != NULL)
        {
            realSum = realSum + current->real;
            imaginarySum = imaginarySum + current->imaginary;
            current = current->next;
        }
        cout << showpoint << fixed<< setprecision(2);
        cout << "The sum of the number list is (" << realSum;
        if (imaginarySum < 0)
            cout << " - " << abs(imaginarySum) << "i)\n\n" ;
        else
            cout << " + " << abs(imaginarySum) << "i)\n\n";
        };
///--------------------------------------------------------------
    private:
        double real, imaginary;

        complexNums *next;
 };

 ;


 int menu();




 void sumStuff();





 int main()
  {
      string fileName;
      ifstream numListFile;
      int choice = 0;

      complexNums numlist;
     complexNums *header = &numlist;
     complexNums *current = header;


      while (choice !=5 )
        {
            cout << "\nThank you for choosing the altermacation machine! \n" <<
                "Please tell me how I can help you... \n\n"
                << "================================================ \n";
            cout << "1. Load my list please! \n"
                << "2. Display my fancy list por favor!\n"
                << "3. Can you add up my list so I don't have to? \n"
                << "4. My life would be easier if you could just multiply that list for me! \n"
                << "5. You have helped me enough thanks! I'm all done. \n"
                << "================================================ \n\n";
            cin >> choice;
            switch (choice)
            {
                case 1:
                    {
                    cout << "\n\nYou have chosen " << choice << " I shall do my best to help...\n\n";
                    cout << "Please tell me the NAME of the FILE you want me to load from\n\n";
                    /// Taking filename as input from user
                    cin.clear();
                    cin.sync();
                    getline(cin, fileName);
                    ///using input to open requested file
                    numListFile.open(fileName.c_str());
                        if (!numListFile)
                        {
                            cerr << "Invalid FILE NAME please try again!\n\n";
                        }
                    current = header;
                    numlist.inputStuff(numListFile, current);
                    break;
                    };
                case 2:
                    {
                    cout << "\n\nYou have chosen " << choice << " I shall do my best to help...\n";
                    current = header;
                    numlist.displayStuff(current);
                    break;
                    };
                case 3:
                    {
                    cout << "\n\nYou have chosen " << choice << " I shall do my best to help...\n";
                    current = header;
                    numlist.sumStuff(current);
                    break;
                    };
                case 4:
                    {
                    cout << "You have chosen " << choice << " I shall do my best to help...\n";
                  //  multiplyStuff();
                    break;
                    };
                case 5:
                    {
                    cout << "\n\nYou have chosen " << choice << " Goodbye! I will miss you :( \n";
                    return 0;
                    };
                default :
                    {
                    cout << "\n\nThat is not a valid number silly! Please try again...\n";
                    };
            }
        };
  numListFile.close();
  return 0;
  };


